//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Invert a binary tree.
* 
*      4
*    /   \
*   2     7
*  / \   / \
* 1   3 6   9
* to
*      4
*    /   \
*   7     2
*  / \   / \
* 9   6 3   1
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
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
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode *temp = invertTree(root->left);
        root->left = invertTree(root->right);
        root->right = temp;
        return root;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Invert_Binary_Tree", "[Tree_Recursion]") {
	Solution s;
	SECTION("Empty Input") {
		REQUIRE(s.invertTree(NULL) == NULL);
	}
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3),a4(4),a6(6),a7(7),a9(9);
		a4.left = &a2; a4.right = &a7;
		a2.left = &a1; a2.right = &a3;
		a7.left = &a6; a7.right = &a9;
		TreeNode *result = s.invertTree(&a4);
		REQUIRE(serialize_tree(result) == "4,7,2,9,6,3,1,#,#,#,#,#,#,#,#");
	}
}
