//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

You may only use constant extra space.
For example,
Given the following binary tree,
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
// Learned Way
// µÝ¹é°æ
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
        // Every level
        if (!root) {return;}
        TreeLinkNode dummy(-1); // Record the head of this level
        for (TreeLinkNode* cur = root, *prev = &dummy; cur; cur = cur->next)		// The level cur in is already processed
        {
            if (cur->left) { prev->next = cur->left; prev = prev->next;}	// Processed it's next level
            if (cur->right) {prev->next = cur->right; prev = prev->next;}
        }
        connect(dummy.next);
    }
};
// µü´ú°æ
class Solution {
public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode* node = root;
		while (node)
		{
			TreeLinkNode* first = NULL; // The first node of next level
			TreeLinkNode* prev = NULL;  // previous node on the same level
			for (; node; node = node->next)
			{
				if (!first) {first = node->left ? node->left : node->right;}
				if (node->left)
				{
					if (prev) {prev->next = node->left;}
					prev = node->left;
				}
				if (node->right)
				{
					if (prev) {prev->next = node->right;}
					prev = node->right;
				}
			}
			node = first; // turn to next level
		}
	}
};