//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Two elements of a binary search tree (BST) are swapped by mistake.
* 
* Recover the tree without changing its structure.
* 
* Note:
* A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ��ͨ����Ҫ�������������Ҫջ����ǰ�����ҵ�һ�������ٴӺ���ǰ�ҵڶ������򣬽�����

// �������ջ��Morris���������ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
// һ���ߵ���ڵ㣬һ�߰���ڵ�������������Լ������������ߵ��ײ�ʱ�ص��Լ���
// ���û����ڵ��ˣ��ͷ��ʱ��ڵ㣬Ȼ���ߵ��ҽڵ㡣
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)��
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
    void recoverTree(TreeNode *root) {
		if (!root) return;
        pair<TreeNode*, TreeNode*> broken;
        TreeNode* prev = nullptr;
        TreeNode* cur = root;
        while (cur != nullptr)
        {
            if (cur->left == nullptr)
            {
                detect(broken, prev, cur);
                prev = cur;
                cur = cur->right;
            }else
            {
                auto node = cur->left;
                while (node->right != nullptr && node->right != cur)
                {
                    node = node->right;
                }
                if (node->right == nullptr)
                {
                    node->right = cur;
                    cur = cur->left;
                }else
                {
                    detect(broken, prev, cur);
                    node->right = nullptr;
                    prev = cur;
                    cur = cur->right;
                }
            }
        }
        swap (broken.first->val, broken.second->val);
    }
    
private:
    void detect(pair<TreeNode*, TreeNode*>& broken, TreeNode* prev, TreeNode* current)
    {
        if (prev != nullptr && prev->val > current->val)
        {
            if (broken.first == nullptr)
            {
                broken.first = prev;
            }
            broken.second = current;
        }
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Recover_Binary_Search_Tree", "[Tree_Traverse]"){
	Solution sln;
	SECTION("Empty Input") {
		sln.recoverTree(NULL);
	}
	SECTION("Normal Input") {
		TreeNode t1(5),t2(3),t3(4),t4(2),t5(7),t6(8);
		t1.left = &t2;
		t1.right = &t3;
		t2.left = &t4;
		t2.right = &t5;
		t3.right = &t6;
		sln.recoverTree(&t1);
		REQUIRE(serialize_tree(&t1) == "5,3,7,2,4,#,8,#,#,#,#,#,#");
	}
}

