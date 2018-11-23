//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
* 
* According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes
* v and w as the lowest node in T that has both v and w as descendants (where we allow a node to be
* a descendant of itself).”
* 
*         _______3______
*        /              \
*     ___5__          ___1__
*    /      \        /      \
*    6      _2       0       8
*          /  \
*          7   4
* For example, the lowest common ancestor (LCA) of nodes 5 and 1 is 3.
* Another example is LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself
* according to the LCA definition.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 递归。如果左右子树都没有那就是当前root，如果其中一个有那就是那一个。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor2(root->left, p, q);
        TreeNode* right = lowestCommonAncestor2(root->right, p, q);
        return !left ? right : !right ? left : root;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Lowest_Common_Ancestor_of_a_Binary_Tree", "[Tree_Recursion]"){
	Solution sln;
	SECTION("Normal Input") {
		TreeNode b1(5),b2(3),b3(1),b4(7),b5(4),b6(2),b7(6),b8(9),b9(8);
		b5.left = &b3; b5.right = &b8;
		b3.left = &b2; b3.right = &b4;
		b2.left = &b1;
		b8.left = &b6; b8.right = &b9;
		b6.right = &b7;
		REQUIRE(sln.lowestCommonAncestor2(&b5, &b1, &b4) == &b3);
		REQUIRE(sln.lowestCommonAncestor2(&b5, &b7, &b6) == &b6);
		REQUIRE(sln.lowestCommonAncestor2(&b5, &b7, &b1) == &b5);
		REQUIRE(sln.lowestCommonAncestor2(&b5, &b6, &b4) == &b5);
		REQUIRE(sln.lowestCommonAncestor2(&b5, &b7, &b5) == &b5);
		REQUIRE(sln.lowestCommonAncestor2(&b5, &b1, &b1) == &b1);
	}
}
