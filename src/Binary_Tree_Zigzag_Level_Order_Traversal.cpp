//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
* 
* For example:
* Given binary tree {3,9,20,#,#,15,7},
* 	   3
* 	  / \
* 	 9  20
* 	   /  \
* 	  15   7
* return its zigzag level order traversal as:
* [
* 	[3],
* 	[20,9],
* 	[15,7]
* ]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1

#ifdef W1
// 广度优先遍历，用一个bool记录方向，每一层结束就翻转一下。

// 迭代法。空间复杂度O(n)，时间复杂度O(n)。
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) {return result;}
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        nodes.push(NULL);
        bool is_left = true;
        vector<int> a_level;
        while (!nodes.empty())
        {
            TreeNode* cur = nodes.front();
            nodes.pop();
            if (cur)
            {
                a_level.push_back(cur->val);
                if (cur->left) {nodes.push(cur->left);}
                if (cur->right) {nodes.push(cur->right);}
            }else
            {
                if (!is_left)
                {
                    reverse(a_level.begin(), a_level.end());
                }
                result.push_back(a_level);
                a_level.clear();
                is_left = !is_left;
                if (!nodes.empty()) {nodes.push(NULL);}
            }
        }
        return result;
    }
};
#endif

#ifdef W2
// 递归法。空间复杂度O(n)，时间复杂度O(n)。
class Solution {
public:
	vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
		vector<vector<int> > result;
		traverse(root, 1, result, true);
		return result;
	}
	void traverse(TreeNode *root, size_t level, vector<vector<int>> &result, bool left_to_right)
	{
			if (!root) return;
			if (level > result.size())
				result.push_back(vector<int>());
			if (left_to_right)
				result[level-1].push_back(root->val);
			else
				result[level-1].insert(result[level-1].begin(), root->val);
			traverse(root->left, level+1, result, !left_to_right);
			traverse(root->right, level+1, result, !left_to_right);
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Binary_Tree_Zigzag_Level_Order_Traversal", "[Tree_Traverse]"){
	Solution sln;
	vector<vector<int> > result;
	SECTION("Empty Input") {
		REQUIRE(sln.zigzagLevelOrder(NULL) == result);
	}
	SECTION("Normal Input") {
		TreeNode n1(3),n2(9),n3(20),n4(15),n5(7);
		n1.left = &n2;
		n1.right = &n3;
		n3.left = &n4;
		n3.right = &n5;
		int r1[2] = {15,7};
		int r2[2] = {20,9};
		result.push_back(vector<int>(1,3));
		result.push_back(vector<int>(r2,r2+2));
		result.push_back(vector<int>(r1,r1+2));
		REQUIRE(sln.zigzagLevelOrder(&n1) == result);
	}
}