//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/31
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a linked list, remove the nth node from the end of list and return its head.
* 
* For example,
* 
* Given linked list: 1->2->3->4->5, and n = 2.
* 
* After removing the second node from the end, the linked list becomes 1->2->3->5.
* Note:
* Given n will always be valid.
* Try to do this in one pass.
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
// 时间复杂度O(n)，空间复杂度O(1)。
// 设两个指针p,q，让p先走n步，然后p和q一起走，直到p走到尾节点，删除q->next 即可。
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if(!head || n < 1) return head;
        ListNode* p = head;
        ListNode* q = head;
		// p先走n步，如果过程中p就到达终点，说明n比链表还长，不做操作。
        for (int i = 0; i < n; ++i)
        {
			if(!p) {return head;}
            p = p->next;
        }
		// p走了n步后就到达终点了，说明要删除的就是首节点，返回首节点后一节点。
        if (!p) {return q->next;}
		// p和q一起走，当p到达终点前一位时，q也正好在要删除元素的前一位。
        while (p->next)
        {
            p = p->next;
            q = q->next;
        }
        q->next = q->next ? q->next->next : NULL;
        return head;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Remove_Nth_Node_From_End_of_List", "[Linked Lists]"){
	Solution sln;
	ListNode a1(1);
	ListNode a2(2);
	ListNode a3(3);
	ListNode a4(4);
	ListNode a5(5);
	a1.next = &a2;
	a2.next = &a3;
	a3.next = &a4;
	a4.next = &a5;
	SECTION("Invalid Input"){
		REQUIRE(sln.removeNthFromEnd(NULL,0) == NULL);
		REQUIRE(sln.removeNthFromEnd(&a1, 10) == &a1);
	}
	SECTION("Normal Input"){
		int temp[4] = {1,2,3,5};
		vector<int> res(temp, temp+4);
		REQUIRE(get_nodes_val(sln.removeNthFromEnd(&a1,2)) == res);
	}
}
