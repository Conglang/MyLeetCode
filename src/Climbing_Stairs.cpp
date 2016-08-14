//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* You are climbing a stair case. It takes n steps to reach to the top.
* 
* Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/*
*	分析
*	设f(n)表示爬n阶楼梯的不同方法数，为了爬到第n阶楼梯，有两个选择：
*	+ 从第n−1阶前进1步；
*	+ 从第n−1阶前进2步；
*	因此，有f(n) = f(n−1) + f(n−2)。
*	这是一个斐波那契数列。
*	方法 1，递归，太慢；
*	方法 2，迭代。
*	方法 3，数学公式。斐波那契数列的通项公式。
*/
// 迭代，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
	int climbStairs(int n) {
		int prev2 = 0;
		int prev1 = 1;
		int result = prev1 + prev2;
		while (n--)
		{
			result = prev1 + prev2;
			prev2 = prev1;
			prev1 = result;
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Climbing_Stairs", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.climbStairs(0) == 1);
	}
	SECTION("Normal Input"){
		REQUIRE(s.climbStairs(3) == 3);
	}
}