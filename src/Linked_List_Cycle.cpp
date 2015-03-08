//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a linked list, determine if it has a cycle in it.
* 
* Follow up:
* Can you solve it without using extra space?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
// ��������ָ�룬һ����һ���������ÿ��������������ÿ����һ�������������������˵���л���
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
    bool hasCycle(ListNode *head) {
        if (!head) {return false;}
        if (head == head->next) {return true;}
        for (ListNode* slow = head, *fast = head; fast;)
        {
            slow = slow->next;
            fast = fast->next ? fast->next->next : NULL;
            if (slow == fast && fast)
            {
                return true;
            }
        }
        return false;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Linked_List_Cycle", "[Linked Lists]"){
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
	SECTION("Invalid Input"){
		REQUIRE(sln.hasCycle(NULL) == false);
	}
	SECTION("Normal Input"){
		REQUIRE(sln.hasCycle(&a1) == false);
		a5.next = &a1;
		REQUIRE(sln.hasCycle(&a1) == true);
	}
}