//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
//--------------------------------------------------------------------------------------------------------------*/
// My Way
// fast先走到k的倍数处等着，slow一个个跟上，同时反转next指向。此段的首尾更改一下next。
// 然后修改指针，进入下一个k倍数段。
class Solution {
public:
	ListNode *reverseKGroup(ListNode *head, int k) {
		if (k < 2) {return head;}
		if (!head || !head->next) {return head;}
		ListNode dummy(-1);
		dummy.next = head;
		int count(0);
		ListNode* fast = head;
		ListNode* slow = head->next;
		ListNode* period_start = &dummy;
		ListNode* prev = head;
		while(fast)
		{
			++count;
			ListNode* next_fast = fast->next;

			if ((count % k) == 0)
			{
				for(int i = 1; i < k; ++i)
				{
					ListNode* behind = slow->next;
					slow->next = prev;
					prev = slow;
					slow = behind;
				}
				ListNode* next_period_start = period_start->next;
				period_start->next->next = next_fast;
				period_start->next = prev;
				period_start = next_period_start;
				prev = next_fast;
				slow = next_fast ? next_fast->next : NULL;
			}
			fast = next_fast;
		}
		return dummy.next;
	}
};