//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given inorder and postorder traversal of a tree, construct the binary tree.

Note:
You may assume that duplicates do not exist in the tree.
//--------------------------------------------------------------------------------------------------------------*/
// My Way
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
class Solution {
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.empty() || postorder.empty()) return NULL;
        if (inorder.size() != postorder.size()) return NULL;
        return build(postorder, inorder.begin(), inorder.end());
    }
private:
    TreeNode* build(vector<int> &parents, vector<int>::iterator lit, vector<int>::iterator rit)
    {
        if (parents.empty() || lit == rit) {return NULL;}
        int parent = parents.back();
        parents.pop_back();
        TreeNode* node = new TreeNode(parent);
        node->right = build(parents, find(lit, rit, parent)+1, rit);
        node->left = build(parents, lit, find(lit, rit, parent));
        return node;
    }
};