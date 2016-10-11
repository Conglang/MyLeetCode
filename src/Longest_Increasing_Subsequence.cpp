//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an unsorted array of integers, find the length of longest increasing subsequence.
* 
* For example,
* Given [10, 9, 2, 5, 3, 7, 101, 18],
* The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. 
* Note that there may be more than one LIS combination, it is only necessary for you to return the length.
* 
* Your algorithm should run in O(n2) complexity.
* 
* Follow up: Could you improve it to O(n log n) time complexity?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Time complexity O(nlogn)
// Ref: https://discuss.leetcode.com/topic/28696/9-lines-c-code-with-o-nlogn-complexity/2
// Ref: http://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/
class Solution {
public:
	int lengthOfLIS(vector<int>& nums) {
		vector<int> res;    // records of the last(largest) element of each active sequence
		for(int i=0; i<nums.size(); i++)
		{
			auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
			if(it==res.end()) res.push_back(nums[i]);
			else *it = nums[i];
		}
		return res.size();
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Longest_Increasing_Subsequence", "[Binary_Search]"){
	Solution s;
	SECTION("Normal Input"){
		int nums[8] = {10, 9, 2, 5, 3, 7, 101, 18};
		REQUIRE(s.lengthOfLIS(vector<int>(nums, nums+8)) == 4);
	}
}