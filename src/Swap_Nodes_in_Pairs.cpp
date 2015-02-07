//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
//--------------------------------------------------------------------------------------------------------------*/
// My Way
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
    ListNode *swapPairs(ListNode *head) {
        if (!head) {return head;}
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* node = head;
        ListNode* prev = &dummy;
        while (true)
        {
            if (!node->next) {break;}
            prev->next = node->next;
            node->next = node->next->next;
            prev->next->next = node;
            prev = node;
            if (!node->next) {break;}
            node = node->next;
        }
        return dummy.next;
    }
};