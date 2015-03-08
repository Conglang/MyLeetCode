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
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
// �ȱ���һ�飬�õ�������len��β�ڵ�nextָ���׽ڵ㣬�γɻ���������len-k%len������֮������µ��׽ڵ㡣
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (!head || !k) {return head;}
		// �õ�����
		int len(1);
		ListNode* temp(head);
		while (temp->next)
		{
			++len;
			temp = temp->next;
		}
		// �Ѵ�����������k��ɴ�����������ע��k�п��ܱ������ȴ�
		k = len - k % len;
		temp->next = head;	// ��β����
		for (int step = 0; step < k; ++step)
		{
			temp = temp->next;	// ��������ܣ����ǵ���ԭ�������ǰ��
		}
		head = temp->next;
		temp->next = nullptr;	// �Ͽ���
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
