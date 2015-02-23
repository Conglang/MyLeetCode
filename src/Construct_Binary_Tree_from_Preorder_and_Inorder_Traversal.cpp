//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given preorder and inorder traversal of a tree, construct the binary tree.
* 
* Note:
* You may assume that duplicates do not exist in the tree.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 递归。时间复杂度O(n)，空间复杂度O(logn)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 前序遍历会先访问父节点，中序遍历会将左右两边子树在父节点左右分开。
// 所以只要依次取出先序遍历的节点作为父节点，递归构造中序遍历中该节点左右两边的两颗子树即可。
class Solution {
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.empty() || inorder.empty()) {return NULL;}
        if (preorder.size() != inorder.size()) {return NULL;}
        reverse(preorder.begin(), preorder.end());
        return build(preorder, inorder.begin(), inorder.end());
    }
private:
    TreeNode* build(vector<int>& parents, vector<int>::iterator treelit, vector<int>::iterator treerit)
    {
        if (treelit == treerit || parents.empty()) return NULL;
        int parent = parents.back();
        parents.pop_back();
        TreeNode* node = new TreeNode(parent);
        node->left = build(parents, treelit, find(treelit, treerit, parent));	// 先左子树
        node->right = build(parents, find(treelit, treerit, parent)+1, treerit);	// 后右子树
		return node;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Construct_Binary_Tree_from_Preorder_and_Inorder_Traversal", "[Tree_Construct]"){
	Solution sln;
	vector<int> preorder,inorder;
	SECTION("Empty Input") {
		REQUIRE(sln.buildTree(preorder,inorder) == NULL);
	}
	SECTION("Normal Input1") {
		preorder.assign(1,1);
		inorder.assign(1,1);
		string result = serialize_tree(sln.buildTree(preorder,inorder));
		REQUIRE(result == "1,#,#");
	}
	SECTION("Normal Input2") {
		int p[5] = {1,2,3,4,5};
		int i[5] = {2,1,4,5,3};
		preorder.assign(p,p+5);
		inorder.assign(i,i+5);
		string result = serialize_tree(sln.buildTree(preorder,inorder));
		REQUIRE(result == "1,2,3,#,#,4,#,#,5,#,#");
	}
}