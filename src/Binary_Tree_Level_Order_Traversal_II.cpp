//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/29
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, return the bottom-up level order traversal of its nodes' values.
* (ie, from left to right, level by level from leaf to root).
* 
* For example:
* Given binary tree {3,9,20,#,#,15,7},
*    3
*   / \
*  9  20
*    /  \
*   15   7
* return its bottom-up level order traversal as:
* [
* 	[15,7],
* 	[9,20],
* 	[3]
* ]
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 可以用上一题的迭代版，反转一下答案。或者：

// 递归版，时间复杂度O(n)，空间复杂度O(n)。
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
    void tranverse(TreeNode* node, int layer, vector<vector<int> >& result)
    {
        if (!node) {return;}
        if (layer > result.size())
        {
            result.push_back(vector<int>());
        }
        result[layer-1].push_back(node->val);
        tranverse(node->left, layer+1, result);
        tranverse(node->right, layer+1, result);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        tranverse(root, 1, result);
        reverse(result.begin(), result.end());
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Binary_Tree_Level_Order_Traversal_II", "[Tree_Traverse]"){
	Solution sln;
	vector<vector<int> > result;
	SECTION("Empty Input") {
		REQUIRE(sln.levelOrderBottom(NULL) == result);
	}
	SECTION("Normal Input") {
		TreeNode n1(3),n2(9),n3(20),n4(15),n5(7);
		n1.left = &n2;
		n1.right = &n3;
		n3.left = &n4;
		n3.right = &n5;
		int r1[2] = {15,7};
		int r2[2] = {9,20};
		result.push_back(vector<int>(r1,r1+2));
		result.push_back(vector<int>(r2,r2+2));
		result.push_back(vector<int>(1,3));
		REQUIRE(sln.levelOrderBottom(&n1) == result);
	}
}