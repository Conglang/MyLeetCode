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
// ��ͨ����Ҫ�������������Ҫջ����ǰ�����ҵ�һ�������ٴӺ���ǰ�ҵڶ������򣬽�����
// �������ջ��Morris ���������ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)���д���ϸ����
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
