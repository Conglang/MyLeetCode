//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array of integers, every element appears twice except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 异或操作可以清除偶数次出现的情况
// Use STL
class Solution {
public:
	int singleNumber(int A[], int n) {
		return accumulate(A, A+n, 0, bit_xor<int>());
	}
};
// Not Using STL
class Solution {
public:
	int singleNumber(int A[], int n) {
		int result(0);
		for (int i = 0; i < n; ++i)
		{
			result ^= A[i];
		}
		return result;
	}
};