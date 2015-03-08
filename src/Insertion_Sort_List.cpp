//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/5
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Sort a linked list using insertion sort.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ��������ʱ�临�Ӷ�O(n^2)���ؼ����Ӷ�O(1)
// ��һ����¼���뵽�Ѿ��ź����������У��Ӷ��õ�һ���µġ���¼����1�������
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
    ListNode *insertionSortList(ListNode *head) {
        ListNode dummy(INT_MIN);
        
        for(ListNode* cur = head; cur;)
        {
            auto pos = findInsertPos(&dummy, cur->val);
            ListNode* temp = cur->next;
            cur->next = pos->next;
            pos->next = cur;
            cur = temp;
        }
        return dummy.next;
    }
private:
    ListNode* findInsertPos(ListNode* head, int x)
    {
        ListNode* pre = NULL;
        for (ListNode* cur = head; cur && cur->val <= x; pre = cur, cur = cur->next)
        {;}
        return pre;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Insertion_Sort_List", "[Sorting]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.insertionSortList(NULL) == NULL);
	}
	SECTION("Normal Input"){
		ListNode a1(1);
		ListNode a2(2);
		ListNode a3(3);
		ListNode a4(4);
		ListNode a5(5);
		ListNode a6(6);
		ListNode a7(7);
		ListNode a8(8);
		ListNode a9(9);
		ListNode a10(10);
		a1.next = &a3;
		a3.next = &a5;
		a5.next = &a2;
		a2.next = &a4;
		a4.next = &a8;
		a8.next = &a10;
		a10.next = &a6;
		a6.next = &a7;
		a7.next = &a9;
		int temp[10] = {1,2,3,4,5,6,7,8,9,10};
		vector<int> result(temp,temp+10);
		REQUIRE(get_nodes_val(sln.insertionSortList(&a1)) == result);
	}
}