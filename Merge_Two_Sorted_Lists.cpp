//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/2
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode* result = &dummy;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        while (node1 && node2)
        {
            if (node1->val <= node2->val)
            {
                result->next = node1;
                node1 = node1->next;
            }else
            {
                result->next = node2;
                node2 = node2->next;
            }
            result = result->next;
        }
        if (node1)
        {
            result->next = node1;
        }
        if (node2)
        {
            result->next = node2;
        }
        return dummy.next;
    }
};