//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Remove all elements from a linked list of integers that have value val.
* 
* Example
* Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
* Return: 1 --> 2 --> 3 --> 4 --> 5
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)
// 一遍遍历，两个指针prev和node，遇到同值就删除。
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
    ListNode* removeElements(ListNode* head, int val) {
        if (!head) return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *node(head), *prev(&dummy);
        while(node)
        {
            if (node->val == val)
            {
                prev->next = node->next;
                node = node->next;
            }else
            {
                prev = node;
                node = node->next;
            }
        }
        return dummy.next;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Remove_Linked_List_Elements", "[Linked Lists]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.removeElements(NULL, 1) == NULL);
	}
	SECTION("Normal Input"){
		ListNode a1(1),a2(1);
		a1.next = &a2;
		REQUIRE(s.removeElements(&a1, 1) == NULL);
		ListNode b1(1),b2(2),b3(2),b4(3);
		b1.next = &b2;
		b2.next = &b3;
		b3.next = &b4;
		int r[2] = {1,3};
		REQUIRE(get_nodes_val(s.removeElements(&b1, 2)) == vector<int>(r,r+2));
	}
}