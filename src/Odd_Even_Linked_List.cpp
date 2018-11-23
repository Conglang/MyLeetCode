//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a singly linked list, group all odd nodes together followed by the even nodes. 
* Please note here we are talking about the node number and not the value in the nodes.
* 
* You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
* 
* Example:
* Given 1->2->3->4->5->NULL,
* return 1->3->5->2->4->NULL.
* 
* Note:
* The relative order inside both the even and odd groups should remain as it was in the input. 
* The first node is considered odd, the second node even and so on ...
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)
// 两个指针一起跳着走，然后合并在一起。
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        if (!head->next) return head;
        ListNode dummy1(-1), dummy2(-2);
        ListNode *node1(head);
        ListNode *node2(head->next);
        dummy1.next = node1;
        dummy2.next = node2;
        while (node2 && node1->next->next)
        {
            node1->next = node1->next->next;
            node1 = node1->next;
            node2->next = node2->next->next;
            node2 = node2->next;
        }
        node1->next = dummy2.next;
        return dummy1.next;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Odd_Even_Linked_List", "[Linked Lists]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.oddEvenList(NULL) == NULL);
	}
	SECTION("Normal Input"){
		ListNode a1(1), a2(2);
		ListNode b(1);
		ListNode c1(1), c2(2), c3(3), c4(4), c5(5);
		ListNode d1(1), d2(2), d3(3), d4(4);
		a1.next = &a2;
		c1.next = &c2; c2.next = &c3; c3.next = &c4; c4.next = &c5;
		d1.next = &d2; d2.next = &d3; d3.next = &d4;
		int ra[2] = {1,2};
		int rb[1] = {1};
		int rc[5] = {1,3,5,2,4};
		int rd[4] = {1,3,2,4};
		REQUIRE(get_nodes_val(s.oddEvenList(&a1)) == vector<int>(ra, ra+2));
		REQUIRE(get_nodes_val(s.oddEvenList(&b)) == vector<int>(rb, rb+1));
		REQUIRE(get_nodes_val(s.oddEvenList(&c1)) == vector<int>(rc, rc+5));
		REQUIRE(get_nodes_val(s.oddEvenList(&d1)) == vector<int>(rd, rd+4));
	}
}