//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of integers, every element appears three times except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2
#ifdef W1
/*
*	创建一个长度为sizeof(int)的数组count[sizeof(int)], 
*	count[i]表示在在i位出现的1的次数。
*	如果count[i]是3的整数倍，则忽略；
*	否则就把该位取出来组成答案。
*/
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
	int singleNumber(int A[], int n) {
		int result(0);
		const int bit_len = sizeof(int) * 8;
		int count[bit_len];
		fill_n(&count[0], bit_len, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < bit_len; ++j)
			{
				count[j] += (A[i] >> j) & 1;
				count[j] %= 3;
			}
		}
		for (int i = 0; i < bit_len; ++i)
		{
			result += count[i] << i;
		}
		return result;
	}
};
#endif

#ifdef W2
// 时间复杂度O(n)，空间复杂度O(1)。
/*
用one记录到当前处理的元素为止，二进制1出现"1次"（mod 3之后的1）的有哪些二进制位；
用two记录到当前计算的变量为止，二进制1出现"2次"（mod 3之后的2）的有哪些二进制位。
当one和two中的某一位同时为1时表示该二进制位上1出现了3次，此时需要清零。
即用二进制模拟三进制运算。最终one记录的是最终结果。
*/
class Solution {
public:
	int singleNumber(int A[], int n) {
		int one = 0, two = 0, three = 0;
		for (int i = 0; i < n; ++i) {
			two |= (one & A[i]);
			one ^= A[i];
			three = ~(one & two);
			one &= three;
			two &= three;
		}
		return one;
	}
};
#endif

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Single_Number_II", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.singleNumber(NULL,0) == 0);
	}
	SECTION("Normal Input"){
		int A[8] = {1,1,1,2,2,3,3,3};
		REQUIRE(s.singleNumber(A,8) == 2);
	}
}