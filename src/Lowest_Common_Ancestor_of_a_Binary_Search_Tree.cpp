//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary search tree (BST), find the lowest common ancestor (LCA) of two given nodes in the BST.
* 
* According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between
* two nodes v and w as the lowest node in T that has both v and w as descendants
* (where we allow a node to be a descendant of itself).”
* 
*         _______6______
*        /              \
*     ___2__          ___8__
*    /      \        /      \
*    0      _4       7       9
*          /  \
*          3   5
* For example, the lowest common ancestor (LCA) of nodes 2 and 8 is 6.
* Another example is LCA of nodes 2 and 4 is 2, since a node can be a descendant of itself according to the LCA definition.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// BST树节点值在左右子树节点值之间，利用这个性质。
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || !p || !q) return nullptr;
        while ((root->val - p->val) * (root->val - q->val) > 0)
        {
            root = (root->val - p->val > 0) ? root->left : root->right;
        }
        return root;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Lowest_Common_Ancestor_of_a_Binary_Search_Tree", "[Binary Search Tree]"){
	Solution sln;
	SECTION("Normal Input") {
		TreeNode b1(1),b2(2),b3(3),b4(4),b5(5),b6(6),b7(7),b8(8),b9(9);
		b5.left = &b3; b5.right = &b8;
		b3.left = &b2; b3.right = &b4;
		b2.left = &b1;
		b8.left = &b6; b8.right = &b9;
		b6.right = &b7;
		REQUIRE(sln.lowestCommonAncestor(&b5, &b1, &b4) == &b3);
		REQUIRE(sln.lowestCommonAncestor(&b5, &b7, &b6) == &b6);
		REQUIRE(sln.lowestCommonAncestor(&b5, &b7, &b1) == &b5);
		REQUIRE(sln.lowestCommonAncestor(&b5, &b6, &b4) == &b5);
		REQUIRE(sln.lowestCommonAncestor(&b5, &b7, &b5) == &b5);
		REQUIRE(sln.lowestCommonAncestor(&b5, &b1, &b1) == &b1);
	}
}
