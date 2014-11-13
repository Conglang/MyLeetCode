//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way 1
// 创建一个长度为 sizeof(int) 的数组 count[sizeof(int)] ， count[i] 表示在在 i 位出现的 1 的次数。如果 count[i] 是 3 的整数倍，则忽略；否则就把该位取出来组成答案。
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
// Learned Way 2
/*
用 one 记录到当前处理的元素为止，二进制 1 出现“1 次”（mod 3 之后的 1）的有哪
些二进制位；用 two 记录到当前计算的变量为止，二进制 1 出现“2 次”（mod 3 之后的 2）的有哪
些二进制位。当 one 和 two 中的某一位同时为 1 时表示该二进制位上 1 出现了 3 次，此时需要清
零。即用二进制模拟三进制运算。最终 one 记录的是最终结果。
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