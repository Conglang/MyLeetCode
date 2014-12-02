//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/2
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, determine if it is a valid binary search tree (BST).

Assume a BST is defined as follows:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.
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
    bool isValidBST(TreeNode *root) {
        if (!root) return true;
        queue<int> nodes;
        tranverse(nodes, root);
        int pre(nodes.front());
        nodes.pop();
        while(!nodes.empty())
        {
            if (nodes.front() <= pre) return false;
            pre = nodes.front();
            nodes.pop();
        }
        return true;
    }
private:
    void tranverse(queue<int>& nodes, TreeNode* node)
    {
        if (!node) {return;}
        tranverse(nodes, node->left);
        nodes.push(node->val);
        tranverse(nodes, node->right);
    }
};

// Learned Way
// 时间复杂度O(n) ，空间复杂度O(logn)
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return isValidBST(root, INT_MIN, INT_MAX);
	}
	bool isValidBST(TreeNode* root, int lower, int upper) {
		if (root == nullptr) return true;
		return root->val > lower && root->val < upper
			&& isValidBST(root->left, lower, root->val)
			&& isValidBST(root->right, root->val, upper);
	}
};