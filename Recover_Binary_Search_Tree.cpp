//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//--------------------------------------------------------------------------------------------------------------*/
// 普通方法要用中序遍历，需要栈。从前往后找第一处逆序，再从后往前找第二处逆序，交换。
// 如果不用栈。Morris 中序遍历。时间复杂度O(n)，空间复杂度O(1)。有待再细看。
// Learned Way
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
    void recoverTree(TreeNode *root) {
        pair<TreeNode*, TreeNode*> broken;
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                detect(broken, prev, cur);
                prev = cur;
                cur = cur->right;
            }else
            {
                auto node = cur->left;
                while (node->right != nullptr && node->right != cur)
                {
                    node = node->right;
                }
                if (node->right == nullptr)
                {
                    node->right = cur;
                    cur = cur->left;
                }else
                {
                    detect(broken, prev, cur);
                    node->right = nullptr;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        swap (broken.first->val, broken.second->val);
    }
    
private:
    void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* current)
    {
        if (prev != nullptr && prev->val > current->val)
        {
            if (broken.first == nullptr)
            {
                broken.first = prev;
            }
            broken.second = current;
        }
    }
};
