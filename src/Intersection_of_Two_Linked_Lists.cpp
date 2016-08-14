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
* A:          a1 �� a2
*                    �K
*                      c1 �� c2 �� c3
*                    �J            
* B:     b1 �� b2 �� b3
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
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
/*
���ڿռ临�Ӷ�Ҫ��O(1)��˵�������ö���ռ��¼���ʽڵ㣬���Ҳ������������ṹ��
ʱ�临�Ӷ�O(n)��ʾ����һ����ʲô���ʣ����Ծ���������������
������
����Ϊ���򵥵����⣬�ཻ�����ʾ����ཻ������ĳ���һ��������������ཻǰ�ĳ�����Ⱦͺ��ˣ�����ֻ��ͬʱ��ͷ�����ͻ��ڽ����������
�����뵽���ֱ����AB�õ��˴˵ĳ��ȣ������Ǹ��������Ĳ�������������ͱ�ɼ򻯵������ˡ�
Ȼ����ͬʱ��ʼ�������ͱض��ڽ����������
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