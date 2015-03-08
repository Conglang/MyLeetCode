//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
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
// ʱ�临�Ӷ�O(m+n)���ռ临�Ӷ�O(1)��
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
            if (!node->next || node->val != node->next->val)	// ����һ����֮��ֵ��ͬ��ֵ
            {
                if (!in_suc)	// ֮ǰ������������ֵ���أ�Ҫ��
                {
                    prev->next = node;
                    prev = node;
                }else	// ֮ǰ����������ֵ��Ҫ��
                {
                    prev->next = NULL;
                }
                in_suc = false;
            }else	// ��ֵ��֮��ֵ��ͬ�����Ϊ������
            {
                in_suc = true;
            }
            node = node->next;
        }
        return dummy.next;
    }
};TEST_CASE("Remove_Duplicates_from_Sorted_list_II", "[Linked Lists]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.deleteDuplicates2(NULL) == NULL);
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
