//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 动态规划。相当于求两个区间各自最大利润的最大和。即要确定区间如何划分使两部分的最大利润的和最大。
// 时间复杂度O(n)，空间复杂度O(n)。
class Solution {
public:
	int maxProfit3(vector<int> &prices) {
		if (prices.size() < 2) return 0;
		const int n = prices.size();
		vector<int> firstpart(n,0);
		vector<int> secondpart(n,0);
		// 从左向右求前半部分的最大利润。
		for (int i = 1, least = prices[0]; i < n; ++i)
		{
			least = min(least, prices[i]);
			firstpart[i] = max(firstpart[i-1], prices[i]-least);
		}
		// 从右向左求后半部分的最大利润。
		for (int i = n-2, most = prices[n-1]; i >=0; --i)
		{
			most = max(most, prices[i]);
			secondpart[i] = max(secondpart[i+1], most-prices[i]);
		}
		// 求它们和的最大值。
		int result(0);
		for (int i = 0; i < n; ++i)
		{
			result = max(result, firstpart[i]+secondpart[i]);
		}
		return result;
	}
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Best_Time_to_Buy_and_Sell_Stock_III", "[Dynamic Programming]"){
	Solution sln;
	vector<int> prices;
	SECTION("Empty Input") {
		REQUIRE(sln.maxProfit3(prices) == 0);
	}
	SECTION("Normal Input") {
		int temp[5] = {1,6,1,1,6};
		prices.assign(temp, temp+5);
		REQUIRE(sln.maxProfit3(prices) == 10);
	}
}