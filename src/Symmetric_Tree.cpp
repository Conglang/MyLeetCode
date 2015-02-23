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
// 递归方式，时间复杂度O(n)，空间复杂度O(logn)。
class Solution 
{
public:
	bool check_node(TreeNode* left_node, TreeNode* right_node)
	{
		if (!left_node && !right_node)				{return true;}	// 两边节点均为空，对称。
		if (!left_node || !right_node)				{return false;}	// 只有一边节点为空，不对称。
		if (left_node->val != right_node->val)		{return false;}	// 两边节点值不同，不对称。

		// 左边的左节点是否等于右边的右节点，左边的右节点是否等于右边的左节点。
		return check_node(left_node->left, right_node->right) && (check_node(left_node->right, right_node->left));
	}

	bool isSymmetric(TreeNode *root) 
	{
		return root ? check_node(root->left, root->right) : true;
	}
};
#endif

#ifdef W2
// 迭代方式
// 时间复杂度 O(n)，空间复杂度 O(logn)
class Solution
{
public:
	bool isSymmetric(TreeNode *root) 
	{
		if (!root)   {return true;}

		std::list<TreeNode*> this_queue;	// 处理队列
		this_queue.push_back(root->left);
		this_queue.push_back(root->right);	// root的左右节点加入队尾

		while (!this_queue.empty())	// 队列中还有待处理的节点时
		{
			TreeNode* left_side = this_queue.front();
			this_queue.pop_front();
			TreeNode* right_side = this_queue.front();
			this_queue.pop_front();	// 得到队首两个节点

			// 比较两节点
			if (!left_side && !right_side)			{continue;}
			if (!left_side || !right_side)			{return false;}
			if(left_side->val != right_side->val)   {return false;}

			// 按左左、右右；左右、右左的顺序加入队尾
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