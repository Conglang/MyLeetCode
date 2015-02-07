//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//--------------------------------------------------------------------------------------------------------------*/
// My way
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
    int minDepth(TreeNode *root) {
        if (!root) {return 0;}
        std::multimap<int, TreeNode*> queue;
        queue.insert(make_pair(1,root));
        while(!queue.empty())
        {
            TreeNode* node = (*queue.begin()).second;
            int layer = (*queue.begin()).first;
            queue.erase(queue.begin());
            if(!node->left && !node->right)
            {
                return layer;
            }
            if(node->left)
            {
                queue.insert(make_pair(layer+1, node->left));
            }
            if(node->right)
            {
                queue.insert(make_pair(layer+1, node->right));
            }
        }
    }
};

// 心得：还是要看标准库，适配器那里。直接用stack更好。