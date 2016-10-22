//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/22
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* You are a professional robber planning to rob houses along a street.
* Each house has a certain amount of money stashed,
* the only constraint stopping you from robbing each of them is that adjacent houses have
* security system connected and it will automatically contact the police
* if two adjacent houses were broken into on the same night.
* 
* Given a list of non-negative integers representing the amount of money of each house, 
* determine the maximum amount of money you can rob tonight without alerting the police.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// dp[0][n]是n-2的最优选择加上今天的，dp[1][n]是n-1的最优选择。
class Solution {
public:
	int rob(vector<int>& nums) {
		vector<vector<int>> dp(2, vector<int>(nums.size()+1, 0));
		for (int i = 0; i < nums.size(); ++i)
		{
			dp[0][i+1] = dp[1][i] + nums[i];
			dp[1][i+1] = max(dp[0][i], dp[1][i]);
		}
		return max(dp[0][nums.size()], dp[1][nums.size()]);
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("House_Robber", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		int t[7] = {3,8,1,5,10,7,12};
		REQUIRE(s.rob(vector<int>(t,t+7)) == 30);
	}
}