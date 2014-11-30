//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given preorder and inorder traversal of a tree, construct the binary tree.

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
        node->left = build(parents, treelit, find(treelit, treerit, parent));
        node->right = build(parents, find(treelit, treerit, parent)+1, treerit);
    }
};