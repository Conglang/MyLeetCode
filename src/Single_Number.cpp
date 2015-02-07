//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of integers, every element appears twice except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 异或操作可以清除偶数次出现的情况
// 时间复杂度O(n)，空间复杂度O(1)。
#define W2
#ifdef W1
// Use STL
class Solution {
public:
	int singleNumber(int A[], int n) {
#if __cplusplus < 201103L
		int sum(0);
		for_each(A, A+n, [&](int n){sum ^= n;});
		return sum;
#else
		return accumulate(A, A+n, 0, bit_xor<int>());
#endif
	}
};
#endif

#ifdef W2
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
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Single_Number", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.singleNumber(NULL, 0) == 0);
	}
	SECTION("Normal Input"){
		int A[5] = {1,1,1,2,2};
		REQUIRE(s.singleNumber(A,5) == 1);
	}
}