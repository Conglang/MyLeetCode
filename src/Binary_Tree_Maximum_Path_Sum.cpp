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
// 用最大连续子序列和(Maximum Subarray)的思路。用dfs遍历。
// 先算出左右子树的结果L和R，如果L大于0，那么对后续结果有利，加上L；如果R大于0，对后续结果也有利，加上R。
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
        max_sum = max(max_sum, sum);	// 是可能包含左右的当前路径
        return max(l, r) > 0 ? max(l, r) + node->val : node->val;	// 返回的是只包含左或者右的，两者之间最长那个与本节点的和。即本节点是一个端点。
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