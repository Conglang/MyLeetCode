//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/3
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 分治法，自底向上。(!)
// 时间复杂度O(n)，空间复杂度O(logn)。
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedListToBST(ListNode *head) {
        int len(0);
        ListNode* p = head;
        while (p)
        {
            ++len;
            p = p->next;
        }
        return sortedListToBST(head, 0, len - 1);
    }
private:
    TreeNode* sortedListToBST(ListNode*& list, int start, int end)
    {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* leftchild = sortedListToBST(list, start, mid - 1);	// 当可以有左子树的时候持续向左。
        TreeNode* parent = new TreeNode(list->val);	// list 指针已经走到了中间处
        parent->left = leftchild;
        list = list->next;	// 到达左子树的尽头NULL后才处理自己，并进行到下一节点，排除已放置的这个。
        parent->right = sortedListToBST(list, mid + 1, end);	// 然后处理右子树。右子树如果有左子树也会持续向左。
        return parent;	// 于是这是中序遍历的样子，也就是构造平衡二叉树的顺序。
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Convert_Sorted_List_to_Binary_Search_Tree", "[Binary Search Tree]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.sortedListToBST(nullptr) == nullptr);
	}
	SECTION("Normal Input") {
		ListNode a1(1),a2(2),a3(3);
		a1.next = &a2; a2.next = &a3;
		REQUIRE(serialize_tree(sln.sortedListToBST(&a1)) == "2,1,3,#,#,#,#");
	}
}