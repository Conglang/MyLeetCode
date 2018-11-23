//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* Design an algorithm to find the maximum profit. You may complete at most k transactions.
* 
* Note:
* You may not engage in multiple transactions at the same time
* (ie, you must sell the stock before you buy again).
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/8984/a-concise-dp-solution-in-java/8
// DP。如果次数很多，仍然贪婪计算，有利就卖；如果次数少，就每个次数，每天，当天要不要买或卖。
class Solution {
public:
	int maxProfitInf(vector<int> &prices) {
		int buyin = INT_MAX, profit = 0;
		// for(auto & price : prices) {
		for (auto it = prices.begin(); it != prices.end(); ++it)
		{
			auto price = *it;
			if(price > buyin) profit += price - buyin;                
			buyin = price;
		}
		return profit;
	}

	int maxProfit(int k, vector<int> &prices) {
		if(k == 0 || prices.empty()) return 0;
		// Max profit by k transaction from 0 to i
		const int n = prices.size();        
		if(k >= n / 2) return maxProfitInf(prices);

		// balance - the balance with at most j transactions with item 0 to i
		// profit - the profit with at most j transactions with item 0 to i
		vector<int> balance(k + 1, INT_MIN), profit(k + 1);

		for(int i = 0; i < n; ++i) {
			for(int j = 1; j <= k; ++j) {
				balance[j] = max(profit[j - 1] - prices[i], balance[j]); // whether to buy at prices[i]
				profit[j] = max(balance[j] + prices[i], profit[j]); // whether to sell at prices[i]
			}
		}

		return profit[k];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Best_Time_to_Buy_and_Sell_Stock_IV", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		int t1[10] = {3,7,5,9,2,10,13,9,4,10};
		REQUIRE(s.maxProfit(3, vector<int>(t1, t1+10)) == 23);
		int t2[2] = {3,7};
		REQUIRE(s.maxProfit(10, vector<int>(t2, t2+2)) == 4);
	}
}