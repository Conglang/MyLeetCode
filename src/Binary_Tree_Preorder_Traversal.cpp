//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
	\
		2
	/
3
return [1,2,3].
Note: Recursive solution is trivial, could you do it iteratively?
//--------------------------------------------------------------------------------------------------------------*/
// 没什么难度的递归方法
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
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        preorder_traverse(root, result);
        return result;
    }
    
private:
    void preorder_traverse(TreeNode* node, vector<int>& num)
    {
        if (!node) {return;}
        num.push_back(node->val);
        preorder_traverse(node->left, num);
        preorder_traverse(node->right, num);
    }
};

// 迭代法，时间复杂度O(n)，空间复杂度O(n)
// My Way
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
    vector<int> preorderTraversal(TreeNode *root) {
       vector<int> result;
       if (!root) {return result;}
       
       result.push_back(root->val);
       stack<TreeNode*> tra_nodes;
       tra_nodes.push(root);
       
       while (!tra_nodes.empty())
       {
           while (tra_nodes.top()->left)
           {
               result.push_back(tra_nodes.top()->left->val);
               tra_nodes.push(tra_nodes.top()->left);
           }
           while (!tra_nodes.empty() && !tra_nodes.top()->right)
           {
               tra_nodes.pop();
           }
           if (!tra_nodes.empty())
           {
               TreeNode* node = tra_nodes.top();
               tra_nodes.pop();
               tra_nodes.push(node->right);
               result.push_back(node->right->val);
           }
       }
       return result;
    }
};

// Cleaner Way
// 使用栈，时间复杂度 O(n) ，空间复杂度 O(n)
class Solution {
public:
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> result;
		const TreeNode *p;
		stack<const TreeNode *> s;
		p = root;
		if (p != nullptr) s.push(p);
		while (!s.empty())
		{
			p = s.top();
			s.pop();
			result.push_back(p->val);
			if (p->right != nullptr) s.push(p->right);
			if (p->left != nullptr) s.push(p->left);
		}
		return result;
	}
};