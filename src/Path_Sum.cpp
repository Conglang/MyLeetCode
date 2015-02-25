//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
* 
* For example:
* Given the below binary tree and sum = 22,
*              5
*             / \
*            4   8
*           /   / \
*          11  13  4
*         /  \      \
*        7    2      1
* return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
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
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL) return false;
		if (root->left == NULL && root->right == NULL)	// leaf
		{
			return sum == root->val;
		}
		return hasPathSum(root->left, sum - root->val) || hasPathSum(root->right, sum - root->val);
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Path_Sum", "[Tree_Recursion]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.hasPathSum(NULL,10) == false);
	}
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3);
		a1.right = &a3;
		a3.left = &a2;
		REQUIRE(sln.hasPathSum(&a1,6) == true);
		REQUIRE(sln.hasPathSum(&a1,5) == false);
	}
}