//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2017/02/09
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given the root of a tree, you are asked to find the most frequent subtree sum.
* The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node
* (including the node itself). So what is the most frequent subtree sum value?
* If there is a tie, return all the values with the highest frequency in any order.
* 
* Examples 1
* Input:
* 
*    5
*  /  \
* 2   -3
* return [2, -3, 4], since all the values happen only once, return all of them in any order.
* Examples 2
* Input:
* 
*    5
*  /  \
* 2   -5
* return [2], since 2 happens twice, however -5 only occur once.
* Note: You may assume the sum of values in any subtree is in the range of 32-bit signed integer.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        // calculate all subtree sums
        unordered_map<int, int> allSumsCounts;
        calculateSubtreeSum(allSumsCounts, root);
        // find most frequent number
        int maxcount(INT_MIN);
        for (auto it = allSumsCounts.begin(); it != allSumsCounts.end(); ++it)
        {
            if ((*it).second > maxcount)
            {
                maxcount = (*it).second;
            }
        }
        // find most frequent some
        vector<int> result;
        for (auto it = allSumsCounts.begin(); it != allSumsCounts.end(); ++it)
        {
            if ((*it).second == maxcount)
            {
                result.push_back((*it).first);
            }
        }
        return result;
    }
    
    int calculateSubtreeSum(unordered_map<int, int>& result, TreeNode* root)
    {
        if (!root) return 0;
        int subLeft(calculateSubtreeSum(result, root->left));
        int subRight(calculateSubtreeSum(result, root->right));
        int sum(root->val + subLeft + subRight);
        if (result.count(sum) != 0)
            ++result[sum];
        else
            result[sum] = 1;
        return sum;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Most_Frequent_Subtre_Sum", "[Tree_Recursion]"){
	Solution s;
	SECTION("Normal Input"){
		int r1[3] = {2, -3, 4};
		vector<int> result1(r1, r1+3);
		TreeNode a1(5), a2(2), a3(-3);
		a1.left = &a2; a1.right = &a3;
		REQUIRE(s.findFrequentTreeSum(&a1) == result1);

		int r2[1] = {2};
		vector<int> result2(r2, r2+1);
		TreeNode b1(5), b2(2), b3(-5);
		b1.left = &b2; b1.right = &b3;
		REQUIRE(s.findFrequentTreeSum(&a2) == result2);
	}
	SECTION("Empty Input"){
		REQUIRE(s.findFrequentTreeSum(nullptr) == vector<int>());
	}
}