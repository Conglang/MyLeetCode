//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree
* 
*     struct TreeLinkNode {
*       TreeLinkNode *left;
*       TreeLinkNode *right;
*       TreeLinkNode *next;
*     }
* Populate each next pointer to point to its next right node. If there is no next right node,
* the next pointer should be set to NULL.
* 
* Initially, all next pointers are set to NULL.
* 
* Note:
* 
* You may only use constant extra space.
* You may assume that it is a perfect binary tree (ie, all leaves are at the same level,
* and every parent has two children).
* For example,
* Given the following perfect binary tree,
*          1
*        /  \
*       2    3
*      / \  / \
*     4  5  6  7
* After calling your function, the tree should look like:
*          1 -> NULL
*        /  \
*       2 -> 3 -> NULL
*      / \  / \
*     4->5->6->7 -> NULL
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2

#ifdef W1
// 宽度优先遍历，不合格，因为不是常数空间。时间复杂度O(n)，空间复杂度O(logn)。
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) return;
        queue<TreeLinkNode*> tranvers;
        tranvers.push(root);
        tranvers.push(NULL);
        TreeLinkNode* node = NULL;
        while (!tranvers.empty())
        {
            TreeLinkNode* cur = tranvers.front();
            tranvers.pop();
            if (!cur)
            {
                if (!tranvers.empty()) {tranvers.push(NULL);}
            }else
            {
                if (cur->left) {tranvers.push(cur->left);}
                if (cur->right) {tranvers.push(cur->right);}
            }
            if (node)
            {
                node->next = cur;
            }
            node = cur;
        }
    }
};
#endif

#ifdef W2
// 只适用于完美二叉树情况。
// 时间复杂度O(n)，空间复杂度O(logn)。
/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        connect(root, NULL);
    }
private:
    void connect(TreeLinkNode *node, TreeLinkNode *sibling)
    {
        if (!node) return;
        node->next = sibling;
        if (sibling)
        {
            connect(node->right, sibling->left);
        }else
        {
            connect(node->right, NULL);
        }
        connect(node->left, node->right);
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Polulating_Next_Right_Pointers_in_Each_Node", "[Tree_Traverse]"){
	Solution sln;
	SECTION("Empty Input") {
		sln.connect(NULL);
	}
	SECTION("Normal Input") {
		TreeLinkNode t1(1),t2(2),t3(3),t4(4),t5(5);
		t1.left = &t2;
		t1.right = &t3;
		t2.left = &t4;
		t2.right = &t5;
		sln.connect(&t1);
		REQUIRE(t1.next == NULL);
		REQUIRE(t2.next == &t3);
		REQUIRE(t3.next == NULL);
		REQUIRE(t4.next == &t5);
		REQUIRE(t5.next == NULL);
	}
}