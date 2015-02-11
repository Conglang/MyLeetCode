//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a sorted linked list, delete all duplicates such that each element appear only once.
* 
* For example,
* Given 1->1->2, return 1->2.
* Given 1->1->2->3->3, return 1->2->3.
//--------------------------------------------------------------------------------------------------------------*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "../project/include.h"
// 迭代。时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {
        if (!head) return head;
		ListNode* prev = head;
		ListNode* node = head->next;
		while (node)
		{
			if (node->val == prev->val)
			{
				prev->next = node->next;
				node = prev->next;
			}else
			{
				prev = node;
				node = node->next;
			}
		}
		return head;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Remove_Duplicates_from_Sorted_list", "[Linked Lists]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.deleteDuplicates(NULL) == NULL);
	}
	SECTION("Normal Input1"){
		ListNode a1(1);
		ListNode a2(1);
		ListNode a3(2);
		a1.next = &a2;
		a2.next = &a3;
		int temp[2] = {1,2};
		vector<int> res(temp, temp+2);
		REQUIRE(get_nodes_val(sln.deleteDuplicates(&a1)) == res);
	}
	SECTION("Normal Input2"){
		ListNode a1(1);
		ListNode a2(1);
		ListNode a3(2);
		ListNode a4(3);
		ListNode a5(3);
		a1.next = &a2;
		a2.next = &a3;
		a3.next = &a4;
		a4.next = &a5;
		int temp[3] = {1,2,3};
		vector<int> res(temp, temp+3);
		REQUIRE(get_nodes_val(sln.deleteDuplicates(&a1)) == res);
	}
}