//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/11/05
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* We are playing the Guess Game. The game is as follows:
* 
* I pick a number from 1 to n. You have to guess which number I picked.
* 
* Every time you guess wrong, I'll tell you whether the number I picked is higher or lower.
* 
* However, when you guess a particular number x, and you guess wrong, you pay $x. 
* You win the game when you guess the number I picked.
* 
* Example:
* 
* n = 10, I pick 8.
* 
* First round:  You guess 5, I tell you that it's higher. You pay $5.
* Second round: You guess 7, I tell you that it's higher. You pay $7.
* Third round:  You guess 9, I tell you that it's lower. You pay $9.
* 
* Game over. 8 is the number I picked.
* 
* You end up paying $5 + $7 + $9 = $21.
* Given a particular n ¡Ý 1, find out how much money you need to have to guarantee a win.
* 
* Hint:
* 
* 1. The best strategy to play the game is to minimize the maximum loss you could possibly face.
* Another strategy is to minimize the expected loss. Here, we are interested in the first scenario.
* 2. Take a small example (n = 3). What do you end up paying in the worst case?
* 3. Check out this article if you're still stuck. https://en.wikipedia.org/wiki/Minimax
* 4. The purely recursive implementation of minimax would be worthless for even a small n. You MUST use dynamic programming.
* 5. As a follow-up, how would you modify your code to solve the problem of minimizing the expected loss, instead of the worst-case loss?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/51353/simple-dp-solution-with-explanation
/*
For each number x in range[i,j]
result_when_pick_x = x + max(DP[i,x-1], DP[x+1,j])
for whenever you choose a number, the feedback is always bad and therefore leads you to a worse branch.
DP[i,j] = min(res_i, res_i+1, ..., res_j)
min makes sure that you are minimizing your cost.
*/
class Solution {
public:
	int getMoneyAmount(int n) {
		vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
		return DP(dp, 1, n);
	}
private:
	int DP(vector<vector<int>>& dp, int s, int e)
	{
		if (s >= e) return 0;
		if (dp[s][e]) return dp[s][e];
		int globalMin(INT_MAX);
		for (int i = s; i <= e; ++i)
		{
			int localMax = i + max(DP(dp, s, i-1), DP(dp, i+1, e));
			globalMin = min(globalMin, localMax);
		}
		dp[s][e] = globalMin;
		return globalMin;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Guess_Number_Higher_or_Lower_II", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.getMoneyAmount(1) == 0);
		REQUIRE(s.getMoneyAmount(5) == 6);
		REQUIRE(s.getMoneyAmount(9) == 14);
		REQUIRE(s.getMoneyAmount(15) == 30);
	}
}