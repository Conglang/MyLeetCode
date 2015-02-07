//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, return the inorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
	\
		2
	/
3
return [1,3,2].

Note: Recursive solution is trivial, could you do it iteratively?
//--------------------------------------------------------------------------------------------------------------*/
// My Way
// 时间复杂度O(n)，空间复杂度O(n)
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> result;
        if (!root) {return result;}
        stack<TreeNode*> nodes;
        
        nodes.push(root);
        while (!nodes.empty())
        {
            while (!nodes.empty() && nodes.top()->left)
            {
                nodes.push(nodes.top()->left);
            }
            while (!nodes.empty() && !nodes.top()->right)
            {
                result.push_back(nodes.top()->val);
                nodes.pop();
            }
            if (!nodes.empty() && nodes.top()->right)
            {
                TreeNode* node = nodes.top();
                nodes.pop();
                result.push_back(node->val);
                nodes.push(node->right);
            }
        }
        return result;
    }
};

// Cleaner Way
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> result;
		const TreeNode *p = root;
		stack<const TreeNode *> s;
		while (!s.empty() || p != nullptr) 
		{
			if (p != nullptr) 
			{
				s.push(p);
				p = p->left;
			}else
			{
				p = s.top();
				s.pop();
				result.push_back(p->val);
				p = p->right;
			}
		}
		return result;
	}
};