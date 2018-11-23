//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/5
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

#define W2

#ifdef W1
// 如果采用复用mergeTwoLists的方法，会超时。

// 使用heap，时间复杂度O(n*logk)，空间复杂度O(n)。
// 从列表中每个的第一个开始形成一个堆，不断把最小元素弹出，把其下一位推进去，持续维护这个堆。
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        vector<ListNode*> heap;
        // make heap with the first element of each list
        for (int i = 0; i < lists.size(); ++i)
        {
            if (lists[i] != NULL)
            {
                heap.push_back(lists[i]);
            }
        }
        make_heap(heap.begin(), heap.end(), NodeCmp());
        ListNode* head = NULL;
        ListNode* curr = NULL;
        while (!heap.empty())
        {
            ListNode* min = heap.front();
            pop_heap(heap.begin(), heap.end(), NodeCmp());
            heap.pop_back();
            
            if (!head) head = min;
            if (curr) curr->next = min;
            curr = min;
            
            // add next element from list to heap if it's not null
            if (curr->next)
            {
                heap.push_back(curr->next);
                push_heap(heap.begin(), heap.end(), NodeCmp());
            }
        }
        return head;
    }
private:
   struct NodeCmp
   {
       bool operator()(ListNode* a, ListNode* b)
       {
           return a->val > b->val;
       }
   };
};

#endif

#ifdef W2
// devide and conquer
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.empty())
            return nullptr;
        if (lists.size() == 1) {
            return lists[0];
        }
        return mergeKLists(lists.begin(), lists.end());
    }
    
    ListNode *mergeKLists(vector<ListNode*>::iterator begin, vector<ListNode*>::iterator end) {
        if (begin == end || begin + 1 == end)
            return *begin;
        auto mid = begin + (end - begin) / 2;
        ListNode* left = mergeKLists(begin, mid);
        ListNode* right = mergeKLists(mid, end);
        return mergeTwoLists(left, right);
    }
private:
   ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode* result = &dummy;
        ListNode* node1 = l1;
        ListNode* node2 = l2;
        while (node1 && node2)
        {
            if (node1->val <= node2->val)
            {
                result->next = node1;
                node1 = node1->next;
            }else
            {
                result->next = node2;
                node2 = node2->next;
            }
            result = result->next;
        }
		result->next = node1 ? node1 : node2;
        return dummy.next;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Merge_k_Sorted_Lists", "[Sorting]"){
	Solution sln;
	vector<ListNode *> lists;
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
	a1.next = &a3;//1,3,5
	a3.next = &a5;
	a2.next = &a4;//2,4,8,10
	a4.next = &a8;
	a8.next = &a10;
	a6.next = &a7;//6,7,9
	a7.next = &a9;
	SECTION("Empty Input"){
		REQUIRE(sln.mergeKLists(lists) == NULL);
	}
	SECTION("Normal Input"){
		lists.push_back(&a1);
		lists.push_back(&a2);
		lists.push_back(&a6);
		int temp[10] = {1,2,3,4,5,6,7,8,9,10};
		vector<int> result(temp,temp+10);
		REQUIRE(get_nodes_val(sln.mergeKLists(lists)) == result);
	}
}