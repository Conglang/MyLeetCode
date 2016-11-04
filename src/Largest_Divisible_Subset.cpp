//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/11/04
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a set of distinct positive integers, find the largest subset such that
* every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
* 
* If there are multiple solutions, return any subset is fine.
* 
* Example 1:
* 
* nums: [1,2,3]
* 
* Result: [1,2] (of course, [1,3] will also be ok)
* Example 2:
* 
* nums: [1,2,4,8]
* 
* Result: [1,2,4,8]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 首先想到的是backtracking
// 试着用DP
// Ref: https://discuss.leetcode.com/topic/58571/c-solution-using-dp
class Solution {
public:
	vector<int> largestDivisibleSubset(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> results(nums.size());
		vector<int> res;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] % nums[j] == 0 && results[j].size() > results[i].size())
				{
					results[i] = results[j];
				}
			}
			results[i].push_back(nums[i]);
			if (res.size() < results[i].size()) {res = results[i];}
		}
		return res;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Largest_Divisible_Subset", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		int t1[3] = {1,2,3};
		int r1[2] = {1,2};
		int t2[4] = {1,2,4,8};
		REQUIRE(s.largestDivisibleSubset(vector<int>(t1,t1+3)) == vector<int>(r1,r1+2));
		REQUIRE(s.largestDivisibleSubset(vector<int>(t2,t2+4)) == vector<int>(t2,t2+4));
	}
}
