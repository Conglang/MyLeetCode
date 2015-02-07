//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
   3
  / \
9  20
    /  \
 15   7
return its level order traversal as:
[
	[3],
	[9,20],
	[15,7]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//--------------------------------------------------------------------------------------------------------------*/
// Important
// µü´ú°æ
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) {return result;}
        
        queue<TreeNode*> current, next;
        vector<int> layer_val;
        
        current.push(root);
        
        while (!current.empty())
        {
            while(!current.empty())
            {
                TreeNode* node = current.front();
                current.pop();
                layer_val.push_back(node->val);
                
                if (node->left) {next.push(node->left);}
                if (node->right) {next.push(node->right);}
            }
            result.push_back(layer_val);
            layer_val.clear();
            swap(current, next);
        }
        return result;
    }
};