//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/3
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
* 
* For example:
* Given the below binary tree and sum = 22,
*              5
*             / \
*            4   8
*           /   / \
*          11  13  4
*         /  \    / \
*        7    2  5   1
* return
* [
*    [5,4,11,2],
*    [5,8,4,5]
* ]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// DFS
class Solution {
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if (!root) {return result;}
        vector<int> layer;	// 中间结果
        tranverse(root, result, layer, sum);
        return result;
    }
private:
    void tranverse(TreeNode* node, vector<vector<int> >& result, vector<int>& layer, int gap)
    {
        if (!node) return;
        layer.push_back(node->val);
        if(!node->left && !node->right)	// leaf
        {
            if (gap == node->val)
            {
                result.push_back(layer);
            }
        }
        if (node->left) {tranverse(node->left, result, layer, gap - node->val);}
        if (node->right) {tranverse(node->right, result, layer, gap - node->val);}
        layer.pop_back();
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Path_Sum_II", "[Tree_Recursion]"){
	Solution sln;
	vector<vector<int> > result;
	SECTION("Empty Input") {
		REQUIRE(sln.pathSum(NULL,10) == result);
	}
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3);
		a1.right = &a3;
		a3.left = &a2;
		int temp[3] = {1,3,2};
		result.push_back(vector<int>(temp,temp+3));
		REQUIRE(sln.pathSum(&a1,6) == result);
	}
}
