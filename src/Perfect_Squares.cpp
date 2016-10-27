//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a positive integer n, find the least number of perfect square numbers 
* (for example, 1, 4, 9, 16, ...) which sum to n.
* 
* For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/24255/summary-of-4-different-solutions-bfs-dp-static-dp-and-mathematics
// Static Dynamic Programming
class Solution {
public:
	int numSquares(int n) {
		if (n < 0) return 0;
		static vector<int> countPerfectSquares(1,0);
		// countPerfectSquares[i] = the least number of perfect square numbers which sums to i.
		while (countPerfectSquares.size() <= n)
		{
			int m(countPerfectSquares.size());
			int count_square(INT_MAX);
			for (int i = 1; i * i <= m; ++i)
			{
				count_square = min(count_square, countPerfectSquares[m - i*i]+1);
			}
			countPerfectSquares.push_back(count_square);
		}
		return countPerfectSquares[n];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Perfect_Squares", "[Dynamic Programming]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.numSquares(1) == 1);
		REQUIRE(s.numSquares(20) == 2);
		REQUIRE(s.numSquares(50) == 2);
	}
}