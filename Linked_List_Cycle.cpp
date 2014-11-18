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
// 时间复杂度O(n)，空间复杂度O(1)
// 设置两个指针，一个快一个慢，快的每次走两步，慢的每次走一步，如果两者能相遇，说明有环。
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