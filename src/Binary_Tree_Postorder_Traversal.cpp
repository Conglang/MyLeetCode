//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, return the postorder traversal of its nodes' values.
* 
* For example:
* Given binary tree {1,#,2,3},
* 	1
* 	 \
* 	  2
* 	 /
* 	3
* return [3,2,1].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
// ����ڵ�ʱ�����������㣬�������ڵ���ջ��
// ��û����ڵ�ʱ��ȡ��ջ��һ��Ԫ�أ�������ҽڵ��ѱ����ʣ����ʸ�ջ��Ԫ�ء�
// ����ҽڵ�δ�����ʣ�ջ��Ԫ��������ջ�������ҽڵ㿪ʼ�ظ������������̡�
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
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Binary_Tree_Postorder_Traversal", "[Tree_Traverse]"){
	Solution sln;
	vector<int> result;
	SECTION("Empty Input") {
		REQUIRE(sln.postorderTraversal(NULL) == result);
	}
	SECTION("Normal Input") {
		TreeNode t1(1);
		TreeNode t2(2);
		TreeNode t3(3);
		t1.right = &t2;
		t2.left = &t3;
		int r[3] = {3,2,1};
		result.assign(r,r+3);
		REQUIRE(sln.postorderTraversal(&t1) == result);
	}
}