//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.
* 
* For example,
* Given n = 3, your program should return all 5 unique BST's shown below.
* 
*    1         3     3      2      1
*     \       /     /      / \      \
*      3     2     1      1   3      2
*     /     /       \                 \
*    2     1         2                 3
* confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
// 分析见前一题。
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) return generate(1, 0);
        return generate(1, n);
    }
private:
    vector<TreeNode*> generate(int start, int end)
    {
        vector<TreeNode*> subTree;
        if (start > end)
        {
            subTree.push_back(nullptr);
            return subTree;
        }
        for (int k = start; k <= end; ++k)
        {
            vector<TreeNode*> leftSubs = generate(start, k - 1);
            vector<TreeNode*> rightSubs = generate(k + 1, end);
#if __cplusplus < 201103L
			for (auto iit = leftSubs.begin(); iit != leftSubs.end(); ++iit)
			{
				auto i = *iit;
				for (auto jit = rightSubs.begin(); jit != rightSubs.end(); ++jit)
				{
					auto j = *jit;
#else
            for (auto i : leftSubs)
            {
                for (auto j : rightSubs)
                {
#endif
                    TreeNode* node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
        }
        return subTree;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Unique_Binary_Search_Trees_II", "[Binary Search Tree]"){
	Solution sln;
	vector<TreeNode*> result;
	SECTION("Empty Input") {
		result.push_back(NULL);
		REQUIRE(sln.generateTrees(0) == result);
	}
	SECTION("Normal Input") {
		result = sln.generateTrees(3);
		vector<string> cal;
		string r[5] = {"1,#,3,2,#,#,#","1,#,2,#,3,#,#","2,1,3,#,#,#,#","3,2,#,1,#,#,#","3,1,#,#,2,#,#"};
		vector<string> pre(r,r+5);
		for (auto it = result.begin(); it != result.end(); ++it)
		{
			cal.push_back(serialize_tree(*it));
		}
		sort(pre.begin(),pre.end());
		sort(cal.begin(),cal.end());
		REQUIRE(pre == cal);
	}
}