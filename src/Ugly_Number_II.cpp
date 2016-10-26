//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Write a program to find the n-th ugly number.
* 
* Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
* For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
* 
* Note that 1 is typically treated as an ugly number.
* 
* Hint:
* 
* 1. The naive approach is to call isUgly for every number until you reach the nth one.
* Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
* 2. An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
* 3 The key is how to maintain the order of the ugly numbers.
* Try a similar approach of merging from three sorted lists: L1, L2, and L3.
* 4. Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/24306/elegant-c-solution-o-n-space-time-with-detailed-explanation
class Solution {
public:
	int nthUglyNumber(int n) {
		vector <int> results (1,1);
		int i = 0, j = 0, k = 0;
		while (results.size() < n)
		{
			results.push_back(min(results[i] * 2, min(results[j] * 3, results[k] * 5)));
			if (results.back() == results[i] * 2) ++i;
			if (results.back() == results[j] * 3) ++j;
			if (results.back() == results[k] * 5) ++k;
		}
		return results.back();
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Ugly_Number_II", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.nthUglyNumber(1) == 1);
		REQUIRE(s.nthUglyNumber(2) == 2);
		REQUIRE(s.nthUglyNumber(3) == 3);
		REQUIRE(s.nthUglyNumber(20) == 36);
		REQUIRE(s.nthUglyNumber(40) == 144);
	}
}