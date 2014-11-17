//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.

Return a deep copy of the list.
//--------------------------------------------------------------------------------------------------------------*/
// My Way
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (!head) {return NULL;}
        std::map<RandomListNode*, RandomListNode*> old_new_comp;
        RandomListNode* node = head;
        RandomListNode dummy(-1);
        RandomListNode* last_new_node = &dummy;
        while (node)
        {
            RandomListNode* new_node = new RandomListNode(node->label);
            last_new_node->next = new_node;
            old_new_comp.insert(make_pair(node, new_node));
            node = node->next;
            last_new_node = new_node;
        }
        node = head;
        while (node)
        {
            old_new_comp[node]->random = old_new_comp[node->random];
            node = node->next;
        }
        return dummy.next;
    }
};

// Learned Way, Better
// 时间复杂度O(n)，空间复杂度O(1)
/*
 cur					cur->next ...
 ↓					↗			↓
 new_node			another_new_node ...
 先排列成这样的顺序，这样，cur->next->random = cur->random->next;
 然后再拆开就可以了
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