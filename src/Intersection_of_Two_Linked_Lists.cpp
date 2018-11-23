//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Write a program to find the node at which the intersection of two singly linked lists begins.
* 
* 
* For example, the following two linked lists:
* 
* A:          a1 → a2
*                    ↘
*                      c1 → c2 → c3
*                    ↗            
* B:     b1 → b2 → b3
* begin to intersect at node c1.
* 
* 
* Notes:
* 
* If the two linked lists have no intersection at all, return null.
* The linked lists must retain their original structure after the function returns.
* You may assume there are no cycles anywhere in the entire linked structure.
* Your code should preferably run in O(n) time and use only O(1) memory.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)
/*
由于空间复杂度要求O(1)，说明不能用额外空间记录访问节点，并且不允许更改链表结构。
时间复杂度O(n)提示我们一定有什么性质，可以经过几遍遍历解决。
分析：
化简为更简单的问题，相交的性质就是相交后链表的长度一样，如果两者在相交前的长度相等就好了，这样只需同时从头遍历就会在交汇点相遇。
于是想到，分别遍历AB得到彼此的长度，长的那个先走相差的步数。这样问题就变成简化的问题了。
然后再同时开始遍历，就必定在交汇点相遇。
*/
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) {return nullptr;}
        if (headA == headB) {return headA;}
        
        ListNode *n1 = headA;
        int countA(0);
        while(n1)
        {
            ++countA;
            n1 = n1->next;
        }
        ListNode *n2 = headB;
        int countB(0);
        while(n2)
        {
            ++countB;
            n2 = n2->next;
        }
        
        n1 = countA > countB ? headA : headB;
        n2 = countA > countB ? headB : headA;
        for (int i = 0; i < abs(countA-countB); ++i)
        {
            n1 = n1->next;
        }
        
        while (n1 && n2)
        {
            if (n1 == n2) {return n1;}
            n1 = n1->next;
            n2 = n2->next;
        }
        return nullptr;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Intersection_of_Two_Linked_Lists", "[Linked Lists]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.getIntersectionNode(NULL,NULL) == NULL);
	}
	SECTION("One Pass Another Input"){
		ListNode a(0),b(0),c(0),d(0);
		a.next = &b;
		b.next = &c;
		c.next = &d;
		REQUIRE(s.getIntersectionNode(&a, &c) == &c);
	}
	SECTION("Normal Input"){
		ListNode a1(0),a2(0),b1(0),b2(0),b3(0),c1(0),c2(0),c3(0);
		a1.next = &a2;
		a2.next = &c1;
		c1.next = &c2;
		c2.next = &c3;
		b1.next = &b2;
		b2.next = &b3;
		b3.next = &c1;
		REQUIRE(s.getIntersectionNode(&a1,&b1) == &c1);
	}
}