//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/31
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* You are given coins of different denominations and a total amount of money amount. 
* Write a function to compute the fewest number of coins that you need to make up that amount.
* If that amount of money cannot be made up by any combination of the coins, return -1.
* 
* Example 1:
* coins = [1, 2, 5], amount = 11
* return 3 (11 = 5 + 5 + 1)
* 
* Example 2:
* coins = [2], amount = 3
* return -1.
* 
* Note:
* You may assume that you have an infinite number of each kind of coin.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		vector<int> DP(amount+1, amount+1);
		DP[0] = 0;
		for (int i = 1; i <= amount; ++i)
		{
			for (int j = 0; j < coins.size(); ++j)
			{
				if (coins[j] <= i)
					DP[i] = min(DP[i], DP[i - coins[j]] + 1);
			}
		}
		return DP[amount] == amount+1 ? -1 : DP[amount];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Coin_Change", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		int t1[4] = {186,419,83,408};
		vector<int> v1(t1,t1+4);
		REQUIRE(s.coinChange(v1, 6249) == 20);
		int t2[1] = {1};
		vector<int> v2(t2,t2+1);
		REQUIRE(s.coinChange(v2, 0) == 0);
		int t3[1] = {2};
		vector<int> v3(t3,t3+1);
		REQUIRE(s.coinChange(v3, 3) == -1);
	}
}