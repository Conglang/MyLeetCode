//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Reverse a linked list from position m to n. Do it in-place and in one-pass.
* 
* For example:
* Given 1->2->3->4->5->NULL, m = 2 and n = 4,
* 
* return 1->4->3->2->5->NULL.
* 
* Note:
* Given m, n satisfy the following condition:
* 1 ≤ m ≤ n ≤ length of list.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// (!)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 先得到起点前一顶点head2，时刻维护head2/prev/cur三个顶点间的关系。
// prev的next指向cur的next，head2的next指向cur，cur的next指向prev，cur每次向后前进一位。
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
		if(!head || m >= n) return head;
		ListNode dummy(-1);
		dummy.next = head;
		ListNode* prev = &dummy;
		for (int i = 0; i < m-1; ++i)
		{
			prev = prev->next;
		}
		ListNode* const head2 = prev;

		prev = head2->next;
		ListNode* cur = prev->next;
		for (int i = m; i < n; ++i)
		{
			prev->next = cur->next;
			cur->next = head2->next;
			head2->next = cur;
			cur = prev->next;
		}
		return dummy.next;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Reverse_Linked_List_II", "[Linked Lists]"){
	Solution sln;
	ListNode head(1);
	ListNode n2(2);
	ListNode n3(3);
	ListNode n4(4);
	ListNode n5(5);
	head.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	SECTION("Empty Input"){
		REQUIRE(sln.reverseBetween(NULL,1,2) == NULL);
		REQUIRE(get_nodes_val(sln.reverseBetween(&head,1,0)) == get_nodes_val(&head));
		// 为突出重点，暂未考虑m或n大于链表总长度的情况。
	}
	SECTION("Normal Input1"){
		int temp[5] = {2,1,3,4,5};
		vector<int> res(temp, temp+5);
		REQUIRE(get_nodes_val(sln.reverseBetween(&head,1,2)) == res);
	}
	SECTION("Normal Input2"){
		int temp[5] = {1,2,5,4,3};
		vector<int> res(temp, temp+5);
		REQUIRE(get_nodes_val(sln.reverseBetween(&head,3,5)) == res);
	}
	SECTION("Normal Input3"){
		int temp[5] = {1,4,3,2,5};
		vector<int> res(temp, temp+5);
		REQUIRE(get_nodes_val(sln.reverseBetween(&head,2,4)) == res);
	}
}