//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Follow up for problem "Populating Next Right Pointers in Each Node".
* 
* What if the given tree could be any binary tree? Would your previous solution still work?
* 
* Note:
* 
* You may only use constant extra space.
* For example,
* Given the following binary tree,
*          1
*        /  \
*       2    3
*      / \    \
*     4   5    7
* After calling your function, the tree should look like:
*          1 -> NULL
*        /  \
*       2 -> 3 -> NULL
*      / \    \
*     4-> 5 -> 7 -> NULL
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
#define W2

#ifdef W1
// 递归版。时间复杂度O(n)，空间复杂度O(1)。
/*
除root所在第一行外，在其他行最左边添加一个dummy节点，然后从左到右遍历这一层，同时添加next指针值。
          root
	      /  \
dummy->  1 -> 2
*/
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect2(TreeLinkNode *root) {
        // Every level
        if (!root) {return;}
        TreeLinkNode dummy(-1); // Record the head of this level
        for (TreeLinkNode* cur = root, *prev = &dummy; cur; cur = cur->next)		// The level cur in is already processed
        {
            if (cur->left) { prev->next = cur->left; prev = prev->next;}	// Processed it's next level
            if (cur->right) {prev->next = cur->right; prev = prev->next;}
        }
        connect2(dummy.next);
    }
};
#endif

#ifdef W2
// 迭代版，时间复杂度O(n)，空间复杂度O(1)。
// 通过一个node指针，进行本层的遍历。利用一个prev指针记录之前的节点并设置next指针值。
// 有左节点就连左节点，有右节点就连右节点。本层处理结束后进入下一层。
class Solution {
public:
	void connect2(TreeLinkNode *root) {
		TreeLinkNode* node = root;
		while (node)
		{
			// 每次初始时清空first和prev。
			TreeLinkNode* first = NULL; // The first node of next level
			TreeLinkNode* prev = NULL;  // previous node on the same level
			// 从左到右依次处理本层所有节点。
			for (; node; node = node->next)
			{
				if (!first) {first = node->left ? node->left : node->right;}
				if (node->left)
				{
					if (prev) {prev->next = node->left;}
					prev = node->left;
				}
				if (node->right)
				{
					if (prev) {prev->next = node->right;}
					prev = node->right;
				}
			}
			node = first; // turn to next level
		}
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Polulating_Next_Right_Pointers_in_Each_Node_II", "[Tree_Traverse]"){
	Solution sln;
	SECTION("Empty Input") {
		sln.connect2(NULL);
	}
	SECTION("Normal Input") {
		TreeLinkNode t1(1),t2(2),t3(3),t4(4),t5(5);
		t1.left = &t2;
		t1.right = &t3;
		t2.left = &t4;
		t3.right = &t5;
		sln.connect2(&t1);
		REQUIRE(t1.next == NULL);
		REQUIRE(t2.next == &t3);
		REQUIRE(t3.next == NULL);
		REQUIRE(t4.next == &t5);
		REQUIRE(t5.next == NULL);
	}
}