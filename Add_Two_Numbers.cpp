//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        vector<ListNode> nodes;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        ListNode dummy(-1);
        ListNode* start = &dummy;
        int plus(0);
        while (node1 || node2)
        {
            ListNode* this_node = new ListNode(0);
            int sum = (node1 ? node1->val : 0) + (node2 ? node2->val : 0) + plus;
            this_node->val = sum % 10;
            plus = sum / 10;
            start->next = this_node;
            node1 = node1 ? node1->next : NULL;
            node2 = node2 ? node2->next : NULL;
            start = start->next;
        }
        if (plus) {start->next = new ListNode(plus);}
        return dummy.next;
    }
};