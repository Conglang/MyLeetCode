//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a linked list and a value x, partition it such that all nodes less than x come before nodes
* greater than or equal to x.
* 
* You should preserve the original relative order of the nodes in each of the two partitions.
* 
* For example,
* Given 1->4->3->2->5->2 and x = 3,
* return 1->2->2->4->3->5.
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
// 时间复杂度O(n)，空间复杂度O(1)。
// 左右两个头结点，分别构建两段，然后拼合。
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
		if (!head) return head;
        ListNode left_dummy(-1);
        ListNode right_dummy(-1);
        ListNode* node = head;
        ListNode* left_node = &left_dummy;
        ListNode* right_node = &right_dummy;
        while (node)
        {
            if (node->val < x)
            {
                left_node->next = node;
                left_node = node;
            }
            else
            {
                right_node->next = node;
                right_node = node;
            }
            node = node->next;
        }
        left_node->next = right_dummy.next;
        right_node->next = NULL;
        return left_dummy.next;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Partition_List", "[Linked Lists]"){
	Solution sln;
	ListNode head(1);
	ListNode n2(4);
	ListNode n3(3);
	ListNode n4(2);
	ListNode n5(5);
	ListNode n6(2);
	head.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	SECTION("Empty Input"){
		REQUIRE(sln.partition(NULL, 0) == NULL);
	}
	SECTION("Normal Input1"){
		int temp[6] = {1,2,2,4,3,5};
		vector<int> res(temp, temp+6);
		REQUIRE(get_nodes_val(sln.partition(&head,3)) == res);
	}
	SECTION("Normal Input2"){
		int temp[6] = {1,4,3,2,5,2};
		vector<int> res(temp, temp+6);
		REQUIRE(get_nodes_val(sln.partition(&head,1)) == res);
	}
	SECTION("Normal Input3"){
		int temp[6] = {1,4,3,2,5,2};
		vector<int> res(temp, temp+6);
		REQUIRE(get_nodes_val(sln.partition(&head,6)) == res);
	}

}
