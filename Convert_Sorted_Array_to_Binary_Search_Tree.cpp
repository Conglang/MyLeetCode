//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/2
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.empty()) return NULL;
        vector<int>::iterator it = num.begin() + num.size() / 2;
        TreeNode* node = new TreeNode(*it);
        vector<int>lt(num.begin(), it);
        vector<int>rt(it+1, num.end());
        node->left = sortedArrayToBST(lt);
        node->right = sortedArrayToBST(rt);
        return node;
    }
};