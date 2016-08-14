//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Reverse a singly linked list.
* 
* click to show more hints.
* 
* Hint:
* A linked list can be reversed either iteratively or recursively. Could you implement both?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)
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
    ListNode* reverseList(ListNode* head) {
        if (!head) return nullptr;
        ListNode *prev(nullptr), *node(head);
        while(node)
        {
            ListNode *next_node = node->next;
            node->next = prev;
            prev = node;
            node = next_node;
        }
        return prev;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Reverse_Linked_List", "[Linked Lists]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.reverseList(NULL) == NULL);
	}
	SECTION("Normal Input"){
		ListNode a(1),b(2),c(3),d(4);
		a.next = &b;
		b.next = &c;
		c.next = &d;
		int r[4] = {4,3,2,1};
		REQUIRE(get_nodes_val(s.reverseList(&a)) == vector<int>(r,r+4));
	}
}
