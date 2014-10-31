//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/31
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
//--------------------------------------------------------------------------------------------------------------*/

// My Way
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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {return true;}
        if (!p || !q) {return false;}
        if (p->val != q->val) {return false;}
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};