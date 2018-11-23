//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* You are given two linked lists representing two non-negative numbers.
* The digits are stored in reverse order and each of their nodes contain a single digit.
* Add the two numbers and return it as a linked list.
* 
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// 时间复杂度O(m+n)，空间复杂度O(1)。
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
            node1 = node1 ? node1->next : nullptr;
            node2 = node2 ? node2->next : nullptr;
            start = start->next;
        }
        if (plus) {start->next = new ListNode(plus);}
        return dummy.next;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Add_Two_Numbers", "[Linked Lists]"){
	Solution s;
	ListNode a1(2);
	ListNode a2(4);
	ListNode a3(3);
	a1.next = &a2;
	a2.next = &a3;
	ListNode b1(5);
	ListNode b2(6);
	ListNode b3(4);
	b1.next = &b2;
	b2.next = &b3;
	int temp[3] = {7,0,8};
	vector<int> r(temp, temp+3);
	SECTION("Empty Input"){
		REQUIRE(s.addTwoNumbers(NULL, NULL) == NULL);
		ListNode t(5);
		REQUIRE(s.addTwoNumbers(&t, NULL)->val == t.val);
	}
	SECTION("Normal Input"){
		ListNode* result = s.addTwoNumbers(&a1, &b1);
		vector<int> r1;
		while (result)
		{
			r1.push_back(result->val);
			result = result->next;
		}
		REQUIRE(r1 == r); 
	}
}