//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 左右两个头结点，分别构建两段，然后拼合。
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
    ListNode *partition(ListNode *head, int x) {
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);
        ListNode* node = head;
        ListNode* left_node = &left_dummy;
        ListNode* right_node = &right_dummy;
        while (node)
        {
            if (node->val < x)
            {
                left_node->next = node;
                left_node = node;
            }
            else
            {
                right_node->next = node;
                right_node = node;
            }
            node = node->next;
        }
        left_node->next = right_dummy.next;
        right_node->next = NULL;
        return left_dummy.next;
    }
};