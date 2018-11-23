//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/2
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Merge two sorted linked lists and return it as a new list.
* The new list should be made by splicing together the nodes of the first two lists.
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
// 时间复杂度O(min(m,n))，空间复杂度O(1)
// 设置一个dummy放在前面，用两个指针分别遍历两个链表，
// 把比较小的挂在dummy为头的链表后面。最后的剩余也挂在后面。
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode* result = &dummy;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        while (node1 && node2)
        {
            if (node1->val <= node2->val)
            {
                result->next = node1;
                node1 = node1->next;
            }else
            {
                result->next = node2;
                node2 = node2->next;
            }
            result = result->next;
        }
		result->next = node1 ? node1 : node2;
        return dummy.next;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Merge_Two_Sorted_Lists", "[Sorting]"){
	Solution sln;
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	ListNode a6(6);
	ListNode a7(7);
	a1.next = &a3;
	a3.next = &a5;
	a2.next = &a4;
	a4.next = &a6;
	a6.next = &a7;
	SECTION("Empty Input"){
		REQUIRE(sln.mergeTwoLists(NULL, NULL) == NULL);
	}
	SECTION("Normal Input"){
		int temp[7] = {1,2,3,4,5,6,7};
		vector<int> result(temp, temp+7);
		REQUIRE(get_nodes_val(sln.mergeTwoLists(&a1,&a2)) == result);
	}
}
