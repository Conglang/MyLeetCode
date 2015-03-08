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
// �ݹ顣ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(logn)
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// ��������������ʸ��ڵ㣬��������Ὣ�������������ڸ��ڵ����ҷֿ���
// ����ֻҪ���η���ȡ����������Ľڵ���Ϊ���ڵ㣬�ݹ鹹����������иýڵ��������ߵ������������ɡ�
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
        node->right = build2(parents, find(lit, rit, parent)+1, rit);	// ��������
        node->left = build2(parents, lit, find(lit, rit, parent));	// ��������
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