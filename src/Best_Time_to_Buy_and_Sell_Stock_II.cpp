//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* Design an algorithm to find the maximum profit.
* You may complete as many transactions as you like
* (ie, buy one and sell one share of the stock multiple times). 
* However, you may not engage in multiple transactions at the same time
* (ie, you must sell the stock before you buy again).
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 贪婪算法。只要第二天比今天的贵，就今天买进，明天卖出。
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
	int maxProfit2(vector<int> &prices) {
		int profit(0);
		for (int i = 1; i < prices.size(); ++i)
		{
			if (prices[i-1] < prices[i])
			{
				profit += prices[i] - prices[i-1];
			}
		}
		return profit;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Best_Time_to_Buy_and_Sell_Stock_II", "[Greedy Technique]"){
	Solution sln;
	vector<int> prices;
	SECTION("Empty Input") {
		REQUIRE(sln.maxProfit2(prices) == 0);
	}
	SECTION("Normal Input1") {
		int temp[7] = {1,2,3,4,5,6,7};
		prices.assign(temp, temp+7);
		REQUIRE(sln.maxProfit2(prices) == 6);
	}
	SECTION("Normal Input2") {
		int temp[7] = {7,6,5,4,3,2,1};
		prices.assign(temp, temp+7);
		REQUIRE(sln.maxProfit2(prices) == 0);
	}
	SECTION("Normal Input3") {
		int temp[7] = {10,1,1,5,7,6,8};
		prices.assign(temp, temp+7);
		REQUIRE(sln.maxProfit2(prices) == 8);
	}
}