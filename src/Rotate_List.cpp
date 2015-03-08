//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a list, rotate the list to the right by k places, where k is non-negative.
* 
* For example:
* Given 1->2->3->4->5->NULL and k = 2,
* return 4->5->1->2->3->NULL.
//--------------------------------------------------------------------------------------------------------------*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)。
// 先遍历一遍，得到链表长度len。尾节点next指向首节点，形成环，接着跑len-k%len步。这之后就是新的首节点。
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !k) {return head;}
		// 得到长度
		int len(1);
		ListNode* temp(head);
		while (temp->next)
		{
			++len;
			temp = temp->next;
		}
		// 把从右向左数的k变成从左向右数，注意k有可能比链表长度大
		k = len - k % len;
		temp->next = head;	// 首尾相连
		for (int step = 0; step < k; ++step)
		{
			temp = temp->next;	// 接着向后跑，就是到了原来链表的前端
		}
		head = temp->next;
		temp->next = nullptr;	// 断开环
		return head;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Rotate_List", "[Linked Lists]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.rotateRight(NULL,1) == NULL);
	}
	SECTION("Normal Input1"){
		ListNode a1(1);
		ListNode a2(2);
		ListNode a3(3);
		ListNode a4(4);
		ListNode a5(5);
		a1.next = &a2;
		a2.next = &a3;
		a3.next = &a4;
		a4.next = &a5;
		int temp[5] = {4,5,1,2,3};
		vector<int> res(temp, temp+5);
		REQUIRE(get_nodes_val(sln.rotateRight(&a1,2)) == res);
	}
}
