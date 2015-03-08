//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/6
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Sort a linked list in O(n log n) time using constant space complexity.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// (!)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 常数空间，空间复杂度O(nlogn)，单链表适合用归并排序，双向链表适合用快速排序。
// 归并排序。利用快慢指针把链表分为两部分。然后递归利用归并排序。
class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next && slow->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(fast);
        return merge_two_sorted_lists(l1, l2);
    }
private:
    ListNode* merge_two_sorted_lists(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy(-1);
        ListNode* p = &dummy;
        for(; l1 || l2; p = p->next)
        {
            if (!l1) {p->next = l2; l2 = l2->next;}
            else if (!l2) {p->next = l1; l1 = l1->next;}
            else if (l1->val > l2->val) {p->next = l2; l2 = l2->next;}
            else {p->next = l1; l1 = l1->next;}
        }
        return dummy.next;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Sort_List", "[Sorting]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.sortList(NULL) == NULL);
	}
	SECTION("Normal Input"){
		ListNode a1(1);
		ListNode a2(2);
		ListNode a3(3);
		ListNode a4(4);
		ListNode a5(5);
		ListNode a6(6);
		ListNode a7(7);
		ListNode a8(8);
		ListNode a9(9);
		ListNode a10(10);
		a1.next = &a3;
		a3.next = &a5;
		a5.next = &a2;
		a2.next = &a4;
		a4.next = &a8;
		a8.next = &a10;
		a10.next = &a6;
		a6.next = &a7;
		a7.next = &a9;
		int temp[10] = {1,2,3,4,5,6,7,8,9,10};
		vector<int> result(temp,temp+10);
		REQUIRE(get_nodes_val(sln.sortList(&a1)) == result);
	}
}