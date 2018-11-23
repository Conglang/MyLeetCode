//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
* 
* Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3,
* the linked list should become 1 -> 2 -> 4 after calling your function.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)
// 既然拿不到之前节点的指针，只能把从此以后的节点的值移位。
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
    void deleteNode(ListNode* node) {
        if (!node) return;
        ListNode *prev(nullptr);
        while(node->next)
        {
            node->val ^= node->next->val;
            node->next->val ^= node->val;
            node->val ^= node->next->val;
            prev = node;
            node = node->next;
        }
        if (prev) {prev->next = nullptr;}
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Delete_Node_in_a_Linked_List", "[Linked Lists]"){
	Solution s;
	ListNode a(1),b(2),c(3),d(4);
	a.next = &b;
	b.next = &c;
	c.next = &d;
	SECTION("Empty Input"){
		int r[4] = {1,2,3,4};
		s.deleteNode(NULL);
		REQUIRE(get_nodes_val(&a) == vector<int>(r,r+4));
		s.deleteNode(&d);
		REQUIRE(get_nodes_val(&a) == vector<int>(r,r+4));
	}
	SECTION("Normal Input"){
		int r[3] = {1,2,4};
		s.deleteNode(&c);
		REQUIRE(get_nodes_val(&a) == vector<int>(r,r+3));
	}
}