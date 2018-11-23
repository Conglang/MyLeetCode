//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a singly linked list, determine if it is a palindrome.
* 
* Follow up:
* Could you do it in O(n) time and O(1) space?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)
// 由于空间复杂度是O(1)，只可能是同时两边遍历，所以想到先求出链表长度，然后一边走到中间一边反转链表，然后在中间两个指针华丽比较。
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
    bool isPalindrome(ListNode* head) {
        if (!head) return true;
        if (!head->next) return true;
        ListNode *node(head);
        int count(0);
        while (node)
        {
            ++count;
            node = node->next;
        }
        
        node = head;
        ListNode *prev(nullptr), *rnext(head->next);
        int mid(count/2);
        while (mid)
        {
            --mid;
            rnext = node->next;
            node->next = prev;
            prev = node;
            node = rnext;
			rnext = node->next;
        }
        
        ListNode *ln(prev), *rn(count%2 ? rnext : node);
        while(ln && rn)
        {
            if (ln->val != rn->val) {return false;}
            ln = ln->next;
            rn = rn->next;
        }
        return true;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Palindrome_Linked_List", "[Linked Lists]"){
	Solution s;
	SECTION("Empty Input"){
		ListNode a(0);
		REQUIRE(s.isPalindrome(NULL) == true);
		REQUIRE(s.isPalindrome(&a) == true);
	}
	SECTION("Normal Input"){
		ListNode a1(1),a2(2),a3(1);
		ListNode b1(1),b2(2),b3(2),b4(1);
		ListNode c1(1),c2(2),c3(1),c4(1);
		ListNode d1(1),d2(2),d3(2);
		a1.next = &a2; a2.next = &a3;
		b1.next = &b2; b2.next = &b3; b3.next = &b4;
		c1.next = &c2; c2.next = &c3; c3.next = &c4;
		d1.next = &d2; d2.next = &d3;
		REQUIRE(s.isPalindrome(&a1) == true);
		REQUIRE(s.isPalindrome(&b1) == true);
		REQUIRE(s.isPalindrome(&c1) == false);
		REQUIRE(s.isPalindrome(&d1) == false);
	}
}