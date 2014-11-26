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
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
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
                p = p->left;	// ��������
            }
            q = NULL;
            while (!s.empty())
            {
                p = s.top();
                s.pop();
				// �Һ��Ӳ����ڻ��ѱ����ʣ�����֮
                if (p->right == q)
                {
                    result.push_back(p->val);
                    q = p;	// ����շ��ʹ��Ľ��
                }else
                {
                    s.push(p);	// ��ǰ��㲻�ܷ��ʣ�����ν�ջ
                    p = p->right;	// ����������
                    break;	// ���¿�ʼѭ�����ԴӴ˽ڵ㿪ʼ���������µȵ���һ��
                }
            }
        }while (!s.empty());
        
        return result;
    }
};