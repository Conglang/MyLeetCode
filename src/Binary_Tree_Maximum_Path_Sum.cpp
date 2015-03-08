//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/4
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, find the maximum path sum.
* 
* The path may start and end at any node in the tree.
* 
* For example:
* Given the below binary tree,
* 
*        1
*       / \
*      2   3
* Return 6.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
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
		if(!root) return 0;
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
        max_sum = max(max_sum, sum);	// �ǿ��ܰ������ҵĵ�ǰ·��
        return max(l, r) > 0 ? max(l, r) + node->val : node->val;	// ���ص���ֻ����������ҵģ�����֮����Ǹ��뱾�ڵ�ĺ͡������ڵ���һ���˵㡣
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Binary_Tree_Maximum_Path_Sum", "[Tree_Recursion]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.maxPathSum(NULL) == 0);
	}
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3),a4(0);
		a1.right = &a3;
		a3.left = &a2;
		a3.right = &a4;
		REQUIRE(sln.maxPathSum(&a1) == 6);
	}
}