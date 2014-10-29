//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, find its maximum depth.

The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//--------------------------------------------------------------------------------------------------------------*/
// My way
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
    int this_depth(TreeNode* root, int depth)
    {
        if (!root) {return depth;}
        return max(this_depth(root->left, depth+1), this_depth(root->right, depth+1));
    }
    int maxDepth(TreeNode *root) {
        return this_depth(root, 0);
    }
};