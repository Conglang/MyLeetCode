//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
* 
* For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
* the contiguous subarray [4,-1,2,1] has the largest sum = 6.
* 
* click to show more practice.
* 
* More practice:
* If you have figured out the O(n) solution,
* try coding another solution using the divide and conquer approach, which is more subtle.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1
#ifdef W1
// 动态规划，时间复杂度O(n)，空间复杂度O(1)。
/*
*	从头到尾遍历数组的时候，对于数组里的一个整数，有两种选择：
*	1. 加入之前的SubArray。当之前的SubArray总体和大于0的时候，其对后续结果有贡献。
*	2. 自己另起一个SubArray。当之前的SubArray总体和小于或等于0时，会拖后腿。
*	所以状态转移方程为：
*	设状态为f[i]，表示以Array[i]结尾的最大连续子序列和。
*	f[i] = max( f[i-1]+Array[i], Array[i] )
*	目标就是求得最大的f[i]。
*/
class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (!A || !n) return 0;
		int result(A[0]);
		int f(0);
		for (int i = 0; i < n; ++i)
		{
			f = max(f+A[i], A[i]);
			result = max(result, f);
		}
		return result;
	}
};
#endif

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Maximum_Subarray", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.maxSubArray(NULL,0) == 0);
	}
	SECTION("Normal Input") {
		int A[] = {-2,1,-3,4,-1,2,1,-5,4};
		REQUIRE(sln.maxSubArray(A,9) == 6);
	}
}