//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, imagine yourself standing on the right side of it,
* return the values of the nodes you can see ordered from top to bottom.
* 
* For example:
* Given the following binary tree,
*    1            <---
*  /   \
* 2     3         <---
*  \     \
*   5     4       <---
* You should return [1, 3, 4].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(n)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> result;
        if (!root) return result;
        queue<TreeNode*> bfsQueue;
        bfsQueue.push(root);
        bfsQueue.push(nullptr);
        while(!bfsQueue.empty())
        {
            TreeNode *node = bfsQueue.front();
            bfsQueue.pop();
            if(node->left) bfsQueue.push(node->left);
            if(node->right) bfsQueue.push(node->right);
            if (bfsQueue.front() == nullptr)
            {
                bfsQueue.pop();
                result.push_back(node->val);
                if (!bfsQueue.empty())
                    bfsQueue.push(nullptr);
            }
        }
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Binary_Tree_Right_Side_View", "[Tree_Tranverse]"){
	Solution s;
	SECTION("Empty Input") {
		REQUIRE(s.rightSideView(NULL) == vector<int>());
	}
	SECTION("Normal Input") {
		TreeNode a1(1), a2(2), a3(3), a4(4);
		a1.left = &a2; a1.right = &a3;
		a2.right = &a4;
		int r[3] = {1,3,4};
		REQUIRE(s.rightSideView(&a1) == vector<int>(r,r+3));
	}
}