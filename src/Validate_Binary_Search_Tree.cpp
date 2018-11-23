//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/2
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, determine if it is a valid binary search tree (BST).
* 
* Assume a BST is defined as follows:
* 
* The left subtree of a node contains only nodes with keys less than the node's key.
* The right subtree of a node contains only nodes with keys greater than the node's key.
* Both the left and right subtrees must also be binary search trees.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2

#ifdef W1
// 时间复杂度O(n)，空间复杂度O(n)。
// 中序遍历的结果应该是递增的，根据这个判断。
// 本方法是先用递归中序遍历一遍，然后再遍历结果比较，不是太好。
// 直接用迭代方式遍历并比较更好。
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
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        queue<int> nodes;
        tranverse(nodes, root);
        int pre(nodes.front());
        nodes.pop();
        while(!nodes.empty())
        {
            if (nodes.front() <= pre) return false;
            pre = nodes.front();
            nodes.pop();
        }
        return true;
    }
private:
    void tranverse(queue<int>& nodes, TreeNode* node)
    {
        if (!node) {return;}
        tranverse(nodes, node->left);
        nodes.push(node->val);
        tranverse(nodes, node->right);
    }
};
#endif

#ifdef W2
// 递归判断本节点值是否在可行区间内。时间复杂度O(n) ，空间复杂度O(logn)。
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, INT_MIN, INT_MAX);
	}
	bool isValidBST(TreeNode* root, int lower, int upper) {
		if (root == nullptr) return true;
		return root->val > lower && root->val < upper
			&& isValidBST(root->left, lower, root->val)
			&& isValidBST(root->right, root->val, upper);
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Validate_Binary_Search_Tree", "[Binary Search Tree]"){
	Solution sln;
	TreeNode a1(1),a2(2),a3(3);
	SECTION("Empty Input") {
		REQUIRE(sln.isValidBST(NULL) == true);
	}
	SECTION("Normal Input1") {
		REQUIRE(sln.isValidBST(&a1) == true);
	}
	SECTION("Normal Input2") {
		a1.right = &a3;
		a3.left = &a2;
		REQUIRE(sln.isValidBST(&a1) == true);
	}
	SECTION("Normal Input3") {
		a1.left = &a3;
		a3.left = &a2;
		REQUIRE(sln.isValidBST(&a1) == false);
	}
}