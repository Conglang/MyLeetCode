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
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
/* 
*	��fast��slow����ʱ��slow�϶�û�б����������� fast�Ѿ��ڻ���ѭ����nȦ(1 �� n)��
*	����slow����s������fast����2s����fast����������s�����ڻ��϶�ת��nȦ�����軷��Ϊr����
*		2s = s + nr
*		s = nr
*	����������ΪL������ڵ������������Ϊa����㵽����ڵ�ľ���Ϊx����Ѱ��x��a��L�Ĺ�ϵ��
*		x + a = nr = (n-1)*r + r = (n-1)*r + L - x
*		x = (n-1)*r + (L - x - a)
*	L - x - aΪ�����㵽����ڵ�ľ��롣��֪��������ͷ������ڵ�=n-1Ȧ�ڻ�+�����㵽����ڵ㡣
*	�������ǿ��Դ�head��ʼ����һ��ָ��slow2��������ָ��ÿ��ǰ��һ��������һ�����ڻ���ڵ�������
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
            fast = fast->next ? fast->next->next : NULL;
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
        return NULL;
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
		REQUIRE(sln.detectCycle(NULL) == NULL);
	}
	SECTION("Normal Input"){
		REQUIRE(sln.detectCycle(&a1) == NULL);
		a5.next = &a3;
		REQUIRE(sln.detectCycle(&a1) == &a3);
	}
}
