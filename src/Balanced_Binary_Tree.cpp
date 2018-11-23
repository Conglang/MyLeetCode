//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/29
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, determine if it is height-balanced.
* 
* For this problem, a height-balanced binary tree is defined as a binary tree in which
* the depth of the two subtrees of every node never differ by more than 1.
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
// 时间复杂度O(n)，空间复杂度O(logn)。
// 递归法，在每个节点计算其左右子树的层数，如不平衡就返回-1。
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
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Balanced_Binary_Tree", "[Tree_Traverse]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.isBalanced(NULL) == true);
	}
	SECTION("Normal Input1") {
		TreeNode t1(1),t2(2),t3(2),t4(3),t5(3);
		t1.left = &t2;
		t1.right = &t3;
		t2.left = &t4;
		t3.right = &t5;
		REQUIRE(sln.isBalanced(&t1) == true);
	}
	SECTION("Normal Input1") {
		TreeNode t1(1),t2(2),t3(2),t4(3),t5(3);
		t1.left = &t2;
		t2.right = &t3;
		t2.left = &t4;
		t3.right = &t5;
		REQUIRE(sln.isBalanced(&t1) == false);
	}
}