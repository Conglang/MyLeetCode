//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
* 
* Note: 
* You may assume k is always valid, 1 ≤ k ≤ BST's total elements.
* 
* Follow up:
* What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently?
* How would you optimize the kthSmallest routine?
* 
* Hint:
* 
* Try to utilize the property of a BST.
* What if you could modify the BST node's structure?
* The optimal runtime complexity is O(height of BST).
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 中序遍历
// 先去左子树找，如果有就返回。没有的话就--k，此时如果k为0了，表示当前节点就是，返回。不然就去右子树找。
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
    int kthSmallest(TreeNode* root, int k) {
        return find(root, k);
    }
private:
    int find(TreeNode* node, int& k)
    {
        if (!node) return -1;
        int x = find(node->left, k);
        if (!k) return x;
        if (!--k) return node->val;
        return find(node->right, k);
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Kth_Smallest_Element_in_a_BST", "[Binary Search Tree]"){
	Solution sln;
	SECTION("Normal Input") {
		TreeNode a1(1);
		REQUIRE(sln.kthSmallest(&a1, 1) == 1);
		TreeNode b1(1),b2(2),b3(3),b4(4),b5(5),b6(6),b7(7),b8(8),b9(9);
		b5.left = &b3; b5.right = &b8;
		b3.left = &b2; b3.right = &b4;
		b2.left = &b1;
		b8.left = &b6; b8.right = &b9;
		b6.right = &b7;
		REQUIRE(sln.kthSmallest(&b5, 9) == 9);
	}
}
