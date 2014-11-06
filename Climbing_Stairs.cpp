﻿//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//--------------------------------------------------------------------------------------------------------------*/
// important
/*
		分析
		设 f ( n ) 表示爬 n 阶楼梯的不同方法数，为了爬到第 n 阶楼梯，有两个选择：
		• 从第 n − 1 阶前进 1 步；
		• 从第 n − 1 阶前进 2 步；
		因此，有 f ( n ) = f ( n − 1) + f ( n − 2)。
		这是一个斐波那契数列。
		方法 1，递归，太慢；方法 2，迭代。
		方法 3，数学公式。斐波那契数列的通项公式为 a n = √15 [( 1 +2√5 ) n − ( 1 −2√5 ) n ] 。
*/
// My way，迭代
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