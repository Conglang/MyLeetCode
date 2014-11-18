//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
// ��������ָ�룬һ����һ���������ÿ��������������ÿ����һ�������������������˵���л���
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
    bool hasCycle(ListNode *head) {
        if (!head) {return false;}
        if (head == head->next) {return true;}
        for (ListNode* slow = head, *fast = head; fast;)
        {
            slow = slow->next;
            fast = fast->next ? fast->next->next : NULL;
            if (slow == fast && fast)
            {
                return true;
            }
        }
        return false;
    }
};