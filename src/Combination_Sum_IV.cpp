//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/11/07
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an integer array with all positive numbers and no duplicates, 
* find the number of possible combinations that add up to a positive integer target.
* 
* Example:
* 
* nums = [1, 2, 3]
* target = 4
* 
* The possible combination ways are:
* (1, 1, 1, 1)
* (1, 1, 2)
* (1, 2, 1)
* (1, 3)
* (2, 1, 1)
* (2, 2)
* (3, 1)
* 
* Note that different sequences are counted as different combinations.
* 
* Therefore the output is 7.
* Follow up:
* What if negative numbers are allowed in the given array?
* How does it change the problem?
* What limitation we need to add to the question to allow negative numbers?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/52302/1ms-java-dp-solution-with-detailed-explanation
#define W3

#ifdef W1
// Recursive
// Time Limit Exceed
/*
So we know that target is the sum of numbers in the array. 
Imagine we only need one more number to reach target, this number can be any one in the array.
combination[target] = sum(combination[target - nums[i]])
*/
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		if (!target) return 1;
		int res(0);
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] <= target)
			{
				res += combinationSum4(nums, target-nums[i]);
			}
		}
		return res;
	}
};
#endif

#ifdef W2
// DP, Top-down
// Just use memo to store calculated intermediate result.
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		// initiate
		intermediate.assign(target+1, -1);
		intermediate[0] = 1;
		return helper(nums, target);
	}
private:
	vector<int> intermediate;
	int helper(vector<int>& nums, int target)
	{
		// return recorded value
		if (intermediate[target] != -1) {return intermediate[target];}
		// calculate
		int res(0);
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] <= target)
			{
				res += helper(nums, target-nums[i]);
			}
		}
		intermediate[target] = res;
		return res;
	}
};
#endif

#ifdef W3
// DP
// Bottom-up
class Solution {
public:
	int combinationSum4(vector<int>& nums, int target) {
		vector<int> combination(target+1, 0);
		combination[0] = 1;
		for (int t = 1; t < target+1; ++t)
		{
			for (int n = 0; n < nums.size(); ++n)
			{
				if (t >= nums[n])
					combination[t] += combination[t - nums[n]];
			}
		}
		return combination[target];
	}
};
#endif

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Combination_Sum_IV", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		int a[3] = {1,2,3};
		vector<int> v(a, a+3);
		REQUIRE(s.combinationSum4(v, 4) == 7);
	}
}