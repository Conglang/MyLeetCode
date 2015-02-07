//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree

struct TreeLinkNode {
TreeLinkNode *left;
TreeLinkNode *right;
TreeLinkNode *next;
}
Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

Initially, all next pointers are set to NULL.

Note:

You may only use constant extra space.
You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
For example,
Given the following perfect binary tree,
     1
    /  \
  2    3
  / \    \
4   5    7
After calling your function, the tree should look like:
        1 -> NULL
      /    \
    2 -> 3 -> NULL
   / \        \
4-> 5 -> 7 -> NULL
//--------------------------------------------------------------------------------------------------------------*/
// My Way
// 宽度优先遍历，不合格，因为不是常数空间。
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
// Learned Way，只适用于完美二叉树情况。
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