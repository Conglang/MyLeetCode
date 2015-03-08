//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/3
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ���η����Ե����ϡ�(!)
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(logn)��
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedListToBST(ListNode *head) {
        int len(0);
        ListNode* p = head;
        while (p)
        {
            ++len;
            p = p->next;
        }
        return sortedListToBST(head, 0, len - 1);
    }
private:
    TreeNode* sortedListToBST(ListNode*& list, int start, int end)
    {
        if (start > end) return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* leftchild = sortedListToBST(list, start, mid - 1);	// ����������������ʱ���������
        TreeNode* parent = new TreeNode(list->val);	
        parent->left = leftchild;
        list = list->next;	// �����������ľ�ͷNULL��Ŵ����Լ��������е���һ�ڵ㣬�ų��ѷ��õ������
        parent->right = sortedListToBST(list, mid + 1, end);	// Ȼ�����������������������������Ҳ���������
        return parent;	// ��������������������ӣ�Ҳ���ǹ���ƽ���������˳��
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Convert_Sorted_List_to_Binary_Search_Tree", "[Binary Search Tree]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.sortedListToBST(NULL) == NULL);
	}
	SECTION("Normal Input") {
		ListNode a1(1),a2(2),a3(3);
		a1.next = &a2; a2.next = &a3;
		REQUIRE(serialize_tree(sln.sortedListToBST(&a1)) == "2,1,3,#,#,#,#");
	}
}