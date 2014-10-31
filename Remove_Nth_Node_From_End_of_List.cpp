//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/31
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a linked list, remove the nth node from the end of list and return its head.

For example,

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
//--------------------------------------------------------------------------------------------------------------*/
// My way
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        vector<ListNode*> nodes;
        ListNode* this_node = head;
        while (this_node)
        {
            nodes.push_back(this_node);
            this_node = this_node->next;
        }
        if (!nodes.empty() && n <= nodes.size())
        {
            int size = nodes.size();
            if (n == size)
            {
                head = head->next;
            }else if(n == 1)
            {
                nodes[size-2]->next = NULL;
            }else
            {
                nodes[size-n-1]->next = nodes[size-n+1];
            }
        }
        return head;
    }
};

// Better Way
// 设两个指针 p, q，让 q 先走 n 步，然后 p 和 q 一起走，直到 q 走到尾节点，删除 p->next 即可。
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode* p = head;
        ListNode* q = head;
        for (int i = 0; i < n; ++i)
        {
            p = p->next;
        }
        if (!p) {return q->next;}
        while (p->next)
        {
            p = p->next;
            q = q->next;
        }
        q->next = q->next ? q->next->next : NULL;
        return head;
    }
};