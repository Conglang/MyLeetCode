//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a list, rotate the list to the right by k places, where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k = 2,
return 4->5->1->2->3->NULL.
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
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head) {return NULL;}
        if (!k || !head->next) {return head;}
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* node = head;
        ListNode* late_node = head;
        int length(0);
        for (ListNode* i = head; i; i = i->next)
        {
            ++length;
        }
        k = k % length;
        int index(1);
        while (node->next)
        {
            if (index > k )
            {
                late_node = late_node->next;
            }
            
            node = node->next;
            ++index;
        }
        node->next = head;
        dummy.next = late_node->next;
        late_node->next = NULL;
        return dummy.next;
    }
};