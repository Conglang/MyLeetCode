//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/29
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//--------------------------------------------------------------------------------------------------------------*/
// Important
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
    int cal_balance(TreeNode* node)
    {
        if (!node) {return 0;}
        int left = cal_balance(node->left);
        int right = cal_balance(node->right);
        if (left < 0 || right < 0 || abs(left - right) > 1) {return -1;}
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode *root) {
       return cal_balance(root) >= 0;
    }
};