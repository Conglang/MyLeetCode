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
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
// ������ָ��p,q����p����n����Ȼ��p��qһ���ߣ�ֱ��p�ߵ�β�ڵ㣬ɾ��q->next ���ɡ�
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if(!head || n < 1) return head;
        ListNode* p = head;
        ListNode* q = head;
		// p����n�������������p�͵����յ㣬˵��n��������������������
        for (int i = 0; i < n; ++i)
        {
			if(!p) {return head;}
            p = p->next;
        }
		// p����n����͵����յ��ˣ�˵��Ҫɾ���ľ����׽ڵ㣬�����׽ڵ��һ�ڵ㡣
        if (!p) {return q->next;}
		// p��qһ���ߣ���p�����յ�ǰһλʱ��qҲ������Ҫɾ��Ԫ�ص�ǰһλ��
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
