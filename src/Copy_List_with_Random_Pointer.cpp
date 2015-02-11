//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
* 
* Return a deep copy of the list.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 时间复杂度O(n)，空间复杂度O(1)。
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
// Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};
// 时间复杂度O(n)，空间复杂度O(1)
/*
 cur			cur->next ...
 ↓		↗		↓
 new_node		another_new_node ...
 先排列成这样的顺序，这样，cur->next->random = cur->random->next;
 然后再拆开就可以了。
*/
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {return NULL;}
        for (RandomListNode* cur = head; cur;)
        {
            RandomListNode* node = new RandomListNode(cur->label);
            node->next = cur->next;
            cur->next = node;
            cur = node->next;
        }
        for (RandomListNode* cur = head; cur;)
        {
            if (cur->random)
            {
                cur->next->random = cur->random->next;
            }
            cur = cur->next->next;
        }
        RandomListNode dummy(-1);
        RandomListNode* new_cur = &dummy;
        for (RandomListNode* cur = head; cur;)
        {
            new_cur->next = cur->next;
            new_cur = new_cur->next;
            cur->next = cur->next->next;
            cur = cur->next;
        }
        return dummy.next;
    }
};
//--------------------------------------------------------------------------------------------------------------
vector<int> get_nodes_val(RandomListNode* head)
{
	vector<int> val;
	while (head)
	{
		val.push_back(head->random->label);
		head = head->next;
	}
	return val;
}
TEST_CASE("Copy_List_with_Random_Pointer", "[Linked Lists]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.copyRandomList(NULL) == NULL);
	}
	SECTION("Normal Input"){
		RandomListNode a1(1);
		RandomListNode a2(2);
		RandomListNode a3(3);
		RandomListNode a4(4);
		RandomListNode a5(5);
		a1.next = &a2;
		a2.next = &a3;
		a3.next = &a4;
		a4.next = &a5;
		a1.random = &a4;
		a2.random = &a3;
		a3.random = &a1;
		a4.random = &a5;
		a5.random = &a2;
		int temp[5] = {4,3,1,5,2};
		vector<int> res(temp, temp+5);
		REQUIRE(get_nodes_val(&a1) == res);
	}
}