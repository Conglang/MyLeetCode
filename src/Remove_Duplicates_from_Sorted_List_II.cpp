//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a sorted linked list, delete all nodes that have duplicate numbers,
* leaving only distinct numbers from the original list.
* 
* For example,
* Given 1->2->3->3->4->4->5, return 1->2->5.
* Given 1->1->1->2->3, return 2->3.
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
    ListNode *deleteDuplicates2(ListNode *head) {
        ListNode dummy(-1);
        dummy.next = head;
        ListNode* node = head;
        ListNode* prev = &dummy;
        bool in_suc = false;
        while (node)
        {
            if (!node->next || node->val != node->next->val)	// 遇到一个与之后值不同的值
            {
                if (!in_suc)	// 之前不是连续，此值独特，要。
                {
                    prev->next = node;
                    prev = node;
                }else	// 之前是连续，此值不要。
                {
                    prev->next = nullptr;
                }
                in_suc = false;
            }else	// 此值与之后值相同，标记为连续。
            {
                in_suc = true;
            }
            node = node->next;
        }
        return dummy.next;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Remove_Duplicates_from_Sorted_list_II", "[Linked Lists]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.deleteDuplicates2(nullptr) == nullptr);
	}
	SECTION("Normal Input1"){
		ListNode a1(1),a2(2),a3(3),a4(3),a5(4),a6(4),a7(5);
		a1.next = &a2;
		a2.next = &a3;
		a3.next = &a4;
		a4.next = &a5;
		a5.next = &a6;
		a6.next = &a7;
		int temp[3] = {1,2,5};
		vector<int> res(temp, temp+3);
		REQUIRE(get_nodes_val(sln.deleteDuplicates2(&a1)) == res);
	}
	SECTION("Normal Input2"){
		ListNode a1(1),a2(1),a3(1),a4(2),a5(3);
		a1.next = &a2;
		a2.next = &a3;
		a3.next = &a4;
		a4.next = &a5;
		int temp[2] = {2,3};
		vector<int> res(temp, temp+2);
		REQUIRE(get_nodes_val(sln.deleteDuplicates2(&a1)) == res);
	}
}
