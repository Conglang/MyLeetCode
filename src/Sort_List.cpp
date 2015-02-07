//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/6
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Sort a linked list in O(n log n) time using constant space complexity.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 常数空间，空间复杂度O(nlogn)，单链表适合用归并排序，双向链表适合用快速排序。
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
    ListNode *sortList(ListNode *head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next && slow->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(fast);
        return merge_two_sorted_lists(l1, l2);
    }
private:
    ListNode* merge_two_sorted_lists(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy(-1);
        ListNode* p = &dummy;
        for(; l1 || l2; p = p->next)
        {
            if (!l1) {p->next = l2; l2 = l2->next;}
            else if (!l2) {p->next = l1; l1 = l1->next;}
            else if (l1->val > l2->val) {p->next = l2; l2 = l2->next;}
            else {p->next = l1; l1 = l1->next;}
        }
        return dummy.next;
    }
};