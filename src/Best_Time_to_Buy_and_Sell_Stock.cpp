//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Say you have an array for which the ith element is the price of a given stock on day i.
* 
* If you were only permitted to complete at most one transaction
* (ie, buy one and sell one share of the stock), design an algorithm to find
* the maximum profit.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 贪心。找到最小价格的一天和最大价格的一天，注意最小价格那天要在最大价格那天前面。
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
	int maxProfit(vector<int> &prices) {
		if (prices.empty()) return 0;
		int result(0);
		int minv(prices[0]),maxv(prices[0]);
#if __cplusplus < 201103L
		for(auto it = prices.begin(); it != prices.end(); ++it)
		{
			int i = *it;
#else
		for(auto i : prices)
		{
#endif
			if (i < minv) {minv = i; maxv = 0;}
			if (i > maxv) {maxv = i;}
			result = max(maxv-minv, result);
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Best_Time_to_Buy_and_Sell_Stock", "[Greedy Technique]"){
	Solution sln;
	vector<int> prices;
	SECTION("Empty Input") {
		REQUIRE(sln.maxProfit(prices) == 0);
	}
	SECTION("Normal Input") {
		int temp[6] = {10,2,5,1,7,8};
		prices.assign(temp,temp+6);
		REQUIRE(sln.maxProfit(prices) == 7);
	}
}