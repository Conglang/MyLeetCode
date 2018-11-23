//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, find its maximum depth.
* 
* The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// 递归。时间复杂度O(n)，空间复杂度O(logn)。
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
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Maximum_Depth_of_Binary_Tree", "[Tree_Recursion]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.maxDepth(NULL) == 0);
	}
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3);
		a1.right = &a3;
		a3.left = &a2;
		REQUIRE(sln.maxDepth(&a1) == 3);
	}
}