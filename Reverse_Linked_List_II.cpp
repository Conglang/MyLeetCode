//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note:
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.
//--------------------------------------------------------------------------------------------------------------*/
// My Way
// 记录下m前一node等待，当n出现时交换。
// 在m和n中间，反转。
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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (m == n) {return head;}
        ListNode dummy(0);
        dummy.next = head;
        ListNode* at_m = NULL;
        ListNode* node = &dummy;
        ListNode* prev = NULL;
        for (int i = 0; i < n+2; ++i)
        {
            ListNode* next = node ? node->next : NULL;
            if (i == m - 1)
            {
                at_m = node;
            }
            if (i == m)
            {
                prev = node;
            }
            if (i > m && i < n + 1)
            {
                node->next = prev;
                prev = node;
            }
            if (i == n + 1 || !node)
            {
                if (at_m && at_m->next) {at_m->next->next = node;}
                if (at_m) {at_m->next = prev;}
                break;
            }
            node = next;
        }
        return dummy.next;
    }
};