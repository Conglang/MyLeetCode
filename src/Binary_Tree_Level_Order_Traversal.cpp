//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, return the level order traversal of its nodes' values.
* (ie, from left to right, level by level).
* 
* For example:
* Given binary tree {3,9,20,#,#,15,7},
*    3
*   / \
*  9  20
*    /  \
*   15   7
* return its level order traversal as:
* [
* 	[3],
* 	[9,20],
* 	[15,7]
* ]
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 迭代版，时间复杂度O(n)，空间复杂度O(n)。
// 核心是广度优先遍历。用两个队列跟踪本层和下层，然后交换。
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > result;
        if (!root) {return result;}
        
        queue<TreeNode*> current, next;
        vector<int> layer_val;
        
        current.push(root);
        
        while (!current.empty())
        {
            while(!current.empty())
            {
                TreeNode* node = current.front();
                current.pop();
                layer_val.push_back(node->val);
                
                if (node->left) {next.push(node->left);}
                if (node->right) {next.push(node->right);}
            }
            result.push_back(layer_val);
            layer_val.clear();
            swap(current, next);
        }
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Binary_Tree_Level_Order_Traversal", "[Tree_Traverse]"){
	Solution sln;
	vector<vector<int> > result;
	SECTION("Empty Input") {
		REQUIRE(sln.levelOrder(NULL) == result);
	}
	SECTION("Normal Input") {
		TreeNode n1(3),n2(9),n3(20),n4(15),n5(7);
		n1.left = &n2;
		n1.right = &n3;
		n3.left = &n4;
		n3.right = &n5;
		int r1[2] = {15,7};
		int r2[2] = {9,20};
		result.push_back(vector<int>(1,3));
		result.push_back(vector<int>(r2,r2+2));
		result.push_back(vector<int>(r1,r1+2));
		REQUIRE(sln.levelOrder(&n1) == result);
	}
}