//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* node = head;
        ListNode* prev = &dummy;
        bool in_suc = false;
        while (node)
        {
            if (!node->next || node->val != node->next->val)
            {
                if (!in_suc)
                {
                    prev->next = node;
                    prev = node;
                }else
                {
                    prev->next = NULL;
                }
                in_suc = false;
            }else
            {
                in_suc = true;
            }
            node = node->next;
        }
        return dummy.next;
    }
};