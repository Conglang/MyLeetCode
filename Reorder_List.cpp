//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/19
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a singly linked list L: L0��L1������Ln-1��Ln,
reorder it to: L0��Ln��L1��Ln-1��L2��Ln-2����

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
/*
��Ŀ�涨Ҫ in-place��Ҳ����˵ֻ��ʹ�� O (1) �Ŀռ䡣
�����ҵ��м�ڵ㣬�Ͽ����Ѻ��ص����� reverse һ�£��ٺϲ�����������
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
    void reorderList(ListNode *head) {
        if (!head) {return;}
        unsigned int count(0);
        ListNode* node = head;
        ListNode* end(NULL);
        while (node)
        {
            ++count;
            end = node->next ? NULL : node;
            node = node->next;
        }
        
        ListNode* middle(head);
        for (int i = 0; i < count / 2; ++i)
        {
            middle = middle->next;
        }
        
        node = middle->next;
        ListNode* pre = middle;
        while (node)
        {
            ListNode* behind = node->next;
            node->next = pre;
            pre = node;
            node = behind;
        }
        
        node = end;
        ListNode* node2 = head;
        while (node2 != middle)
        {
            ListNode* left_next = node2->next;
            ListNode* right_next = node->next;
            node2->next = node;
            node->next = left_next;
            node2 = left_next;
            node = right_next;
        }
        node2->next = NULL;
    }
};