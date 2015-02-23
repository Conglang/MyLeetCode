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
// �ݹ�档ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
/*
��root���ڵ�һ���⣬����������������һ��dummy�ڵ㣬Ȼ������ұ�����һ�㣬ͬʱ���nextָ��ֵ��
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
// �����棬ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
// ͨ��һ��nodeָ�룬���б���ı���������һ��prevָ���¼֮ǰ�Ľڵ㲢����nextָ��ֵ��
// ����ڵ������ڵ㣬���ҽڵ�����ҽڵ㡣���㴦������������һ�㡣
class Solution {
public:
	void connect2(TreeLinkNode *root) {
		TreeLinkNode* node = root;
		while (node)
		{
			// ÿ�γ�ʼʱ���first��prev��
			TreeLinkNode* first = NULL; // The first node of next level
			TreeLinkNode* prev = NULL;  // previous node on the same level
			// ���������δ��������нڵ㡣
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