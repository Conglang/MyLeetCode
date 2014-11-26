//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
1
	\
	2
	/
3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        
        const TreeNode *p, *q;
        stack<const TreeNode *> s;
        p = root;
        do {
            while (p != NULL)
            {
                s.push(p);
                p = p->left;	// 往左下走
            }
            q = NULL;
            while (!s.empty())
            {
                p = s.top();
                s.pop();
				// 右孩子不存在或已被访问，访问之
                if (p->right == q)
                {
                    result.push_back(p->val);
                    q = p;	// 保存刚访问过的结点
                }else
                {
                    s.push(p);	// 当前结点不能访问，需二次进栈
                    p = p->right;	// 处理右子树
                    break;	// 重新开始循环，以从此节点开始，重新左下等等那一轮
                }
            }
        }while (!s.empty());
        
        return result;
    }
};