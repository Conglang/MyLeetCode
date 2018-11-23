//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
* 
* Follow up:
* Can you solve it without using extra space?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)。
/* 
*	当fast与slow相遇时，slow肯定没有遍历完链表，而 fast已经在环内循环了n圈(1 ≤ n)。
*	假设slow走了s步，则fast走了2s步（fast步数还等于s加上在环上多转的n圈），设环长为r，则：
*		2s = s + nr
*		s = nr
*	设整个链表长为L，环入口点与相遇点距离为a，起点到环入口点的距离为x，则，寻找x与a和L的关系：
*		x + a = nr = (n-1)*r + r = (n-1)*r + L - x
*		x = (n-1)*r + (L - x - a)
*	L - x - a为相遇点到环入口点的距离。可知，从链表头到环入口点=n-1圈内环+相遇点到环入口点。
*	于是我们可以从head开始另设一个指针slow2，两个慢指针每次前进一步，它俩一定会在环入口点相遇。
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
    ListNode *detectCycle(ListNode *head) {
        for (ListNode* slow = head, *fast = head; fast;)
        {
            slow = slow->next;
            fast = fast->next ? fast->next->next : nullptr;
            if (slow == fast && fast)
            {
                ListNode* slow2 = head;
                while (slow != slow2)
                {
                    slow = slow->next;
                    slow2 = slow2->next;
                }
                return slow2;
            }
        }
        return nullptr;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Linked_List_Cycle_II", "[Linked Lists]"){
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
		REQUIRE(sln.detectCycle(nullptr) == nullptr);
	}
	SECTION("Normal Input"){
		REQUIRE(sln.detectCycle(&a1) == nullptr);
		a5.next = &a3;
		REQUIRE(sln.detectCycle(&a1) == &a3);
	}
}
