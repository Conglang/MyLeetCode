//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/19
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a singly linked list L: L0→L1→…→Ln-1→Ln,
* reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
* 
* You must do this in-place without altering the nodes' values.
* 
* For example,
* Given {1,2,3,4}, reorder it to {1,4,2,3}.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)。
/*
*	题目规定要in-place，也就是说只能使用O(1)的空间。
*	可以找到中间节点，断开，把后半截单链表reverse一下，再合并两个单链表。
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {
        if (!head) {return;}
        unsigned int count(0);
        ListNode* node = head;
        ListNode* end(NULL);
        while (node)
        {
            ++count;
            end = node->next ? NULL : node;
            node = node->next;
        }
        
        ListNode* middle(head);
        for (int i = 0; i < count / 2; ++i)
        {
            middle = middle->next;
        }
        
        node = middle->next;
        ListNode* pre = middle;
        while (node)
        {
            ListNode* behind = node->next;
            node->next = pre;
            pre = node;
            node = behind;
        }
        
        node = end;
        ListNode* node2 = head;
        while (node2 != middle)
        {
            ListNode* left_next = node2->next;
            ListNode* right_next = node->next;
            node2->next = node;
            node->next = left_next;
            node2 = left_next;
            node = right_next;
        }
        node2->next = NULL;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Reorder_List", "[Linked Lists]"){
	Solution sln;
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	SECTION("Normal Input"){
		int temp[5] = {1,5,2,4,3};
		vector<int> res(temp, temp+5);
		sln.reorderList(&a1);
		REQUIRE(get_nodes_val(&a1) == res);
	}
}