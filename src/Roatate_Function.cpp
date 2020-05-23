//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/09
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/59886/share-my-c-solution-with-explanation-easy-to-understand
/*
F(0) = 0*A[0] + 1*A[1] + ...... + (n-1)*A[n-1]
F(1) = 0 *A[n-1] + 1*A[0] + 2*A[1] + 3*A[2] + ...... + (n-1)*A[n-2]
.
.
F(n-1) = 0*A[1] + 1*A[2] + 2*A[3] + ...... + (n-1)*A[0]
F(1) - F(0) = A[0] + A[1] + A[2] + ...... + A[n-2] - (n-1)*A[n-1]
==>F(1) = (A[0] + A[1] + A[2] + ...... + A[n-1]) - n*A[n-1] + F(0)
set sum = A[0] + A[1] + A[2] + ...... + A[n-1]
F(2) = sum - n*A[n-2] + F(1)
.
.
F(i) = sum - n*A[n-i] + F(i-1)
*/
class Solution {
public:
	int maxRotateFunction(vector<int>& A) {
		int n = A.size();
		int ret = 0;
		int sum = 0;
		int f = 0;

		for (int i = 0; i < n; i++)
		{
			sum += A[i];
			f += i * A[i];
		}

		ret = f;
		for (int i = 1; i < n; i++)
		{
			f = f + sum - n * A[n - i];
			ret = max(ret, f);
		}

		return ret;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Roatate_Function", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		vector<int> v;
		REQUIRE(s.maxRotateFunction(v) == 0);
	}
	SECTION("Normal Input"){
		int a[4] = {4,3,2,6};
		int b[2] = {-2147483648, -2147483648};
		vector<int> v1(a,a+4);
		REQUIRE(s.maxRotateFunction(v1) == 26);
		vector<int> v2(b,b+2);
		REQUIRE(s.maxRotateFunction(v2) == -2147483648);
	}
}