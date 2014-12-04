//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/4
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.

An example is the root-to-leaf path 1->2->3 which represents the number 123.

Find the total sum of all root-to-leaf numbers.

For example,

     1
    / \
  2   3
The root-to-leaf path 1->2 represents the number 12.
The root-to-leaf path 1->3 represents the number 13.

Return the sum = 12 + 13 = 25.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
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
    int sumNumbers(TreeNode *root) {
        return cal_sum(root, 0);
    }
private:
    int cal_sum(TreeNode* node, int sum)
    {
        if (!node) return 0;
        if (!node->left && !node->right)
        {
            return sum * 10 + node->val;
        }
        return cal_sum(node->left, sum * 10 + node->val) + cal_sum(node->right, sum * 10 + node->val);
    }
};