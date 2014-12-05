//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/5
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Sort a linked list using insertion sort.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 插入排序，时间复杂度O(n^2)，控件复杂度O(1)
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        
        for(ListNode* cur = head; cur;)
        {
            auto pos = findInsertPos(&dummy, cur->val);
            ListNode* temp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = temp;
        }
        return dummy.next;
    }
private:
    ListNode* findInsertPos(ListNode* head, int x)
    {
        ListNode* pre = NULL;
        for (ListNode* cur = head; cur && cur->val <= x; pre = cur, cur = cur->next)
        {;}
        return pre;
    }
};
