//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/5
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 复用mergeTwoLists，不可，会TLE
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
        if (lists.empty()) return NULL;
        ListNode* l1 = lists[0];
        for (int i = 1; i < lists.size(); ++i)
        {
            l1 = mergeTwoLists(l1, lists[i]);
        }
        return l1;
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode dummy(-1);
        ListNode* p = &dummy;
        for (; l1 && l2; p = p->next)
        {
            if (l1->val > l2->val) {p->next = l2; l2 = l2->next;}
            else {p->next = l1; l1 = l1->next;}
        }
        p->next = l1 ? l1 : l2;
        return dummy.next;
    }
};

// Learned Way，using heaps O(n*logk)
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