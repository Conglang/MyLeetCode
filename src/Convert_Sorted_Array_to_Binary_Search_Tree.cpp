//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/2
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
// 分治法，时间复杂度O(n)，空间复杂度O(logn)。
// 在指定区间内，以中间节点为父节点，然后分别构造左右区间。
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.empty()) return NULL;
        vector<int>::iterator it = num.begin() + num.size() / 2;
        TreeNode* node = new TreeNode(*it);
        vector<int>lt(num.begin(), it);
        vector<int>rt(it+1, num.end());
        node->left = sortedArrayToBST(lt);
        node->right = sortedArrayToBST(rt);
        return node;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Convert_Sorted_Array_to_Binary_Search_Tree", "[Binary Search Tree]"){
	Solution sln;
	vector<int> num;
	SECTION("Empty Input") {
		REQUIRE(sln.sortedArrayToBST(num) == NULL);
	}
	SECTION("Normal Input") {
		int temp[3] = {1,2,3};
		num.assign(temp,temp+3);
		REQUIRE(serialize_tree(sln.sortedArrayToBST(num)) == "2,1,3,#,#,#,#");
	}
}