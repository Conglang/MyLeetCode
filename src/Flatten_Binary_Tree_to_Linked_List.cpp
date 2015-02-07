//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

		1
       / \
	 2   5
	/ \    \
  3   4    6
The flattened tree should look like:
1
	\
		2
			\
				3
					\
						4
							\
								5
									\
										6
click to show hints.

Hints:
If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// ��������ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(logn)��
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
    void flatten(TreeNode *root) {
        if (!root) return;
        stack<TreeNode*> wait;
        wait.push(root);
        //TreeNode* prev = nullptr;
        while(!wait.empty())
        {
            auto node = wait.top();
            wait.pop();
            if (node->right) {wait.push(node->right);}
            if (node->left) {wait.push(node->left);}
            
            node->left = nullptr/*prev*/;
            if (!wait.empty())
            {
                node->right = wait.top();
				//prev = node;
            }
        }
    }
};
// �ݹ鷨1
class Solution {
public:
	void flatten(TreeNode *root) {
		if (root == nullptr) return; // ��ֹ����
		flatten(root->left);
		flatten(root->right);
		if (nullptr == root->left) return;
		// �����ϲ��������������γɵ�������뵽 root �� root->right ֮��
		TreeNode *p = root->left;
		while(p->right) p = p->right; //Ѱ�����������һ���ڵ�
		p->right = root->right;
		root->right = root->left;
		root->left = nullptr;
	}
};