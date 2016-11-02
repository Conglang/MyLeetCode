//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/11/02
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a positive integer n, break it into the sum of at least two positive integers 
* and maximize the product of those integers. Return the maximum product you can get.
* 
* For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
* 
* Note: You may assume that n is not less than 2 and not larger than 58.
* 
* Hint:
* 
* There is a simple O(n) solution to this problem.
* You may check the breaking results of n ranging from 7 to 10 to discover the regularities.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/42978/java-dp-solution/8
class Solution {
public:
	int integerBreak(int n) {
		// 1.Init except dp[n], since it cannot be itself and must break into two positive
		vector<int> dp(n+1, 0);
		for (int i = 1; i < n; ++i)
		{
			dp[i] = i;	// no cut
		}
		// 2.Compute max product
		for (int i = 2; i <= n; ++i)
		{
			for (int j = 1; j <= i-j; ++j)  // only check j <= i-j
			{
				dp[i] = max(dp[i], dp[j] * dp[i-j]);	// cut in the middle
			}
		}
		return dp[n];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Integer_Break", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.integerBreak(2) == 1);
		REQUIRE(s.integerBreak(3) == 2);
		REQUIRE(s.integerBreak(4) == 4);
		REQUIRE(s.integerBreak(5) == 6);
		REQUIRE(s.integerBreak(6) == 9);
		REQUIRE(s.integerBreak(7) == 12);
		REQUIRE(s.integerBreak(8) == 18);
		REQUIRE(s.integerBreak(9) == 27);
		REQUIRE(s.integerBreak(10) == 36);
		REQUIRE(s.integerBreak(11) == 54);
	}
}