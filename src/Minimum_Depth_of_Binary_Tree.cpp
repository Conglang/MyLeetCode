//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, find its minimum depth.
* 
* The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
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

// DFS，时间复杂度O(n)，空间复杂度O(logn).
class Solution {
public:
    int minDepth(TreeNode *root) {
        if(!root) return 0;
        if(!root->left) return 1 + minDepth(root->right);
        if(!root->right) return 1 + minDepth(root->left);
        return 1+min(minDepth(root->left),minDepth(root->right));
    }
};
// 另一种方法是BFS
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Minimum_Depth_of_Binary_Tree", "[Tree_Recursion]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.minDepth(NULL) == 0);
	}
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3),a4(4);
		a1.left = &a4;
		a1.right = &a3;
		a3.left = &a2;
		REQUIRE(sln.minDepth(&a1) == 2);
	}
}