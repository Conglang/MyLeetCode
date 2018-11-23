//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, return the inorder traversal of its nodes' values.
* 
* For example:
* Given binary tree {1,#,2,3},
* 	1
* 	 \
* 	  2
* 	 /
* 	3
* return [1,3,2].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2

#ifdef W1
// 一种迭代方法。
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
#endif

#ifdef W2
// 时间复杂度O(n)，空间复杂度O(n)。
// 直接走到左节点，把父节点放入栈。如果没有左节点了，出栈，到其右节点。指针和栈都有特别的作用。
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
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Binary_Tree_Inorder_Traversal", "[Tree_Traverse]"){
	Solution sln;
	vector<int> result;
	SECTION("Empty Input") {
		REQUIRE(sln.inorderTraversal(NULL) == result);
	}
	SECTION("Normal Input") {
		TreeNode t1(1);
		TreeNode t2(2);
		TreeNode t3(3);
		t1.right = &t2;
		t2.left = &t3;
		int r[3] = {1,3,2};
		result.assign(r,r+3);
		REQUIRE(sln.inorderTraversal(&t1) == result);
	}
}