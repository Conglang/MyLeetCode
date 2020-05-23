//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* Design an algorithm to find the maximum profit. You may complete as many transactions as you like
* (ie, buy one and sell one share of the stock multiple times) with the following restrictions:
* 
* You may not engage in multiple transactions at the same time
* (ie, you must sell the stock before you buy again).
* After you sell your stock, you cannot buy stock on next day.
* (ie, cooldown 1 day)
* Example:
* 
* prices = [1, 2, 3, 0, 2]
* maxProfit = 3
* transactions = [buy, sell, cooldown, buy, sell]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/30421/share-my-thinking-process
/*
buy[i] means before day i what is the maxProfit for any sequence end with buy.
sell[i] means before day i what is the maxProfit for any sequence end with sell.
rest[i] means before day i what is the maxProfit for any sequence end with rest.

buy[i]  = max(rest[i-1]-price, buy[i-1]) 
sell[i] = max(buy[i-1]+price, sell[i-1])
rest[i] = max(sell[i-1], buy[i-1], rest[i-1])

由于buy[i] <= rest[i], rest[i] <= sell[i]，所以最后一行等价为rest[i] = sell[i-1]

化简为：
buy[i] = max(sell[i-2]-price, buy[i-1])
sell[i] = max(buy[i-1]+price, sell[i-1])

由于day i只和i-1和i-2有关系，所以可以只使用O(1) Space。
*/
class Solution {
public:
	int maxProfit5(vector<int>& prices) {
		if (prices.empty()) return 0;
		int buy(INT_MIN), sell(0), prev_buy(INT_MIN), prev_sell(0);
		for (int i = 0; i < prices.size(); ++i)
		{
			prev_buy = buy;
			buy = max(prev_sell - prices[i], buy);
			prev_sell = sell;
			sell = max(prev_buy + prices[i], sell);
		}
		return sell;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Best_Time_to_Buy_and_Sell_Stock_with_Cooldown", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		int t[5] = {1,2,3,0,2};
		vector<int> v(t,t+5);
		REQUIRE(s.maxProfit5(v) == 3);
	}
}