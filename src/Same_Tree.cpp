//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/31
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two binary trees, write a function to check if they are equal or not.
* 
* Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
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
// 时间复杂度O(n)，空间复杂度O(logn)。
class Solution {
public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        if (!p && !q) {return true;}
        if (!p || !q) {return false;}
        if (p->val != q->val) {return false;}
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Same_Tree", "[Tree_Traverse]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.isSameTree(NULL,NULL) == true);
	}
	SECTION("Normal Input") {
		TreeNode n1(3),n2(9),n3(20),n4(15),n5(7);
		n1.left = &n2;
		n1.right = &n3;
		n3.left = &n4;
		n3.right = &n5;
		REQUIRE(sln.isSameTree(&n1,&n1) == true);
		REQUIRE(sln.isSameTree(&n1,&n3) == false);
	}
}