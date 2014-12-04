//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/4
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

        1
       / \
     2   3
Return 6.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// ��������������к�(Maximum Subarray)��˼·����dfs������
// ��������������Ľ��L��R�����L����0����ô�Ժ����������������L�����R����0���Ժ������Ҳ����������R��
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
    int maxPathSum(TreeNode *root) {
        max_sum = INT_MIN;
        dfs(root);
        return max_sum;
    }
private:
    int max_sum;
    int dfs(TreeNode* node)
    {
        if (!node) return 0;
        int l = dfs(node->left);
        int r = dfs(node->right);
        int sum = node->val;
        if (l > 0) sum += l;
        if (r > 0) sum += r;
        max_sum = max(max_sum, sum);
        return max(l, r) > 0 ? max(l, r) + node->val : node->val; 
    }
};