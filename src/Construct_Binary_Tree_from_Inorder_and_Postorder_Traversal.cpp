//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given inorder and postorder traversal of a tree, construct the binary tree.
* 
* Note:
* You may assume that duplicates do not exist in the tree.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
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
// 后序遍历会最后访问父节点，中序遍历会将左右两边子树在父节点左右分开。
// 所以只要依次反向取出后序遍历的节点作为父节点，递归构造中序遍历中该节点左右两边的两颗子树即可。
class Solution {
public:
    TreeNode *buildTree2(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()) return NULL;
        if (inorder.size() != postorder.size()) return NULL;
        return build2(postorder, inorder.begin(), inorder.end());
    }
private:
    TreeNode* build2(vector<int> &parents, vector<int>::iterator lit, vector<int>::iterator rit)
    {
        if (parents.empty() || lit == rit) {return NULL;}
        int parent = parents.back();
        parents.pop_back();
        TreeNode* node = new TreeNode(parent);
        node->right = build2(parents, find(lit, rit, parent)+1, rit);	// 先右子树
        node->left = build2(parents, lit, find(lit, rit, parent));	// 后左子树
        return node;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Construct_Binary_Tree_from_Inorder_and_Postorder_Traversal", "[Tree_Construct]"){
	Solution sln;
	vector<int> postorder,inorder;
	SECTION("Empty Input") {
		REQUIRE(sln.buildTree2(inorder,postorder) == NULL);
	}
	SECTION("Normal Input1") {
		postorder.assign(1,1);
		inorder.assign(1,1);
		string result = serialize_tree(sln.buildTree2(inorder,postorder));
		REQUIRE(result == "1,#,#");
	}
	SECTION("Normal Input2") {
		int p[5] = {2,5,4,3,1};
		int i[5] = {2,1,4,5,3};
		postorder.assign(p,p+5);
		inorder.assign(i,i+5);
		string result = serialize_tree(sln.buildTree2(inorder,postorder));
		REQUIRE(result == "1,2,3,#,#,4,#,#,5,#,#");
	}
}