//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* You have a total of n coins that you want to form in a staircase shape,
* where every k-th row must have exactly k coins.
* 
* Given n, find the total number of full staircase rows that can be formed.
* 
* n is a non-negative integer and fits within the range of a 32-bit signed integer.
* 
* Example 1:
* 
* n = 5
* 
* The coins can form the following rows:
* ก่
* ก่ ก่
* ก่ ก่
* 
* Because the 3rd row is incomplete, we return 2.
* Example 2:
* 
* n = 8
* 
* The coins can form the following rows:
* ก่
* ก่ ก่
* ก่ ก่ ก่
* ก่ ก่
* 
* Because the 4th row is incomplete, we return 3.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1

#ifdef W1
// Binary Search
class Solution {
public:
	int arrangeCoins(int n) {
		int start(0), end(n);
		while (start <= end)
		{
			int mid(start + ((end - start) >> 1));
			if ((0.5 * mid * mid + 0.5 * mid ) <= n)
			{
				start = mid + 1;
			}else
			{
				end = mid - 1;
			}
		}
		return start-1;
	}
};
#endif

#ifdef W2
// Ref: https://discuss.leetcode.com/topic/65575/java-o-1-solution-math-problem/7
/*
(1 + X) * X = 2n
4X * X + 4 * X = 8n
(2X + 1)(2X + 1) - 1 = 8n
X = (Math.sqrt(8 * n + 1) - 1)/ 2
*/
class Solution {
public:
	int arrangeCoins(int n) {
		return (int)(sqrt(1 + 8.0 * n) - 1) >> 1;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Arranging_Coins", "[Binary_Search]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.arrangeCoins(5) == 2);
		REQUIRE(s.arrangeCoins(6) == 3);
		REQUIRE(s.arrangeCoins(7) == 3);
		REQUIRE(s.arrangeCoins(8) == 3);
	}
}