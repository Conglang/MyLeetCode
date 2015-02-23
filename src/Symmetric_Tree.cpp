//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/24
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
* For example, this binary tree is symmetric:
*     1
*    / \
*   2   2
*  / \ / \
* 3  4 4  3
* 
* But the following is not:
*     1
*    / \
*   2   2
*    \   \
*    3    3
* 
* Note:
* Bonus points if you could solve it both recursively and iteratively.
//--------------------------------------------------------------------------------------------------------------*/
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//---------------------------------------------------
#include "../project/include.h"
#define W1

#ifdef W1
// �ݹ鷽ʽ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(logn)��
class Solution 
{
public:
	bool check_node(TreeNode* left_node, TreeNode* right_node)
	{
		if (!left_node && !right_node)				{return true;}	// ���߽ڵ��Ϊ�գ��Գơ�
		if (!left_node || !right_node)				{return false;}	// ֻ��һ�߽ڵ�Ϊ�գ����Գơ�
		if (left_node->val != right_node->val)		{return false;}	// ���߽ڵ�ֵ��ͬ�����Գơ�

		// ��ߵ���ڵ��Ƿ�����ұߵ��ҽڵ㣬��ߵ��ҽڵ��Ƿ�����ұߵ���ڵ㡣
		return check_node(left_node->left, right_node->right) && (check_node(left_node->right, right_node->left));
	}

	bool isSymmetric(TreeNode *root) 
	{
		return root ? check_node(root->left, root->right) : true;
	}
};
#endif

#ifdef W2
// ������ʽ
// ʱ�临�Ӷ� O(n)���ռ临�Ӷ� O(logn)
class Solution
{
public:
	bool isSymmetric(TreeNode *root) 
	{
		if (!root)   {return true;}

		std::list<TreeNode*> this_queue;	// �������
		this_queue.push_back(root->left);
		this_queue.push_back(root->right);	// root�����ҽڵ�����β

		while (!this_queue.empty())	// �����л��д�����Ľڵ�ʱ
		{
			TreeNode* left_side = this_queue.front();
			this_queue.pop_front();
			TreeNode* right_side = this_queue.front();
			this_queue.pop_front();	// �õ����������ڵ�

			// �Ƚ����ڵ�
			if (!left_side && !right_side)			{continue;}
			if (!left_side || !right_side)			{return false;}
			if(left_side->val != right_side->val)   {return false;}

			// ���������ң����ҡ������˳������β
			this_queue.push_back(left_side->left);
			this_queue.push_back(right_side->right);
			this_queue.push_back(left_side->right);
			this_queue.push_back(right_side->left);
		}
		return true;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Symmetric_Tree", "[Tree_Traverse]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.isSymmetric(NULL) == true);
	}
	SECTION("Normal Input1") {
		TreeNode t1(1),t2(2),t3(2),t4(3),t5(3);
		t1.left = &t2;
		t1.right = &t3;
		t2.left = &t4;
		t3.right = &t5;
		REQUIRE(sln.isSymmetric(&t1) == true);
	}
	SECTION("Normal Input2") {
		TreeNode t1(1),t2(2),t3(2),t4(3),t5(3);
		t1.left = &t2;
		t1.right = &t3;
		t2.left = &t4;
		t3.left = &t5;
		REQUIRE(sln.isSymmetric(&t1) == false);
	}
}