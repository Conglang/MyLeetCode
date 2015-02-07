//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
//--------------------------------------------------------------------------------------------------------------*/
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
        set<int> existed_values;
        ListNode* node = head;
        ListNode* last_node = NULL;
        while (node)
        {
            if (existed_values.find(node->val) != existed_values.end())
            {
                last_node->next = node->next;
            }else
            {
                existed_values.insert(node->val);
                last_node = node;
            }
            node = node->next;
        }
        return head;
    }
};