//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a linked list, swap every two adjacent nodes and return its head.
* 
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. You may not modify the values in the list,
* only nodes itself can be changed.
//--------------------------------------------------------------------------------------------------------------*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        if (!head) {return head;}
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* node = head;
        ListNode* prev = &dummy;
        while (true)
        {
            if (!node->next) {break;}
            prev->next = node->next;
            node->next = node->next->next;
            prev->next->next = node;
            prev = node;
            if (!node->next) {break;}
            node = node->next;
        }
        return dummy.next;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Swap_Nodes_in_Pairs", "[Linked Lists]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.swapPairs(NULL) == NULL);
	}
	SECTION("Normal Input1"){
		ListNode a1(1);
		ListNode a2(2);
		ListNode a3(3);
		ListNode a4(4);
		a1.next = &a2;
		a2.next = &a3;
		a3.next = &a4;
		int temp[4] = {2,1,4,3};
		vector<int> res(temp, temp+4);
		REQUIRE(get_nodes_val(sln.swapPairs(&a1)) == res);
	}
	SECTION("Normal Input2"){
		ListNode a1(1);
		ListNode a2(2);
		ListNode a3(3);
		ListNode a4(4);
		ListNode a5(5);
		a1.next = &a2;
		a2.next = &a3;
		a3.next = &a4;
		a4.next = &a5;
		int temp[5] = {2,1,4,3,5};
		vector<int> res(temp, temp+5);
		REQUIRE(get_nodes_val(sln.swapPairs(&a1)) == res);
	}
}