//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/5
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
* 
* Would this affect the run-time complexity? How and why?
* 
* Write a function to determine if a given target is in the array.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(logn)，空间复杂度O(1)。
// 二分查找
// 当A[l] == A[m]，无法确定方向时，单纯++l;
class Solution {
public:
	bool search2(int A[], int n, int target) {
		int l(0),r(n);	// 区间[l,r)
		while (l != r)
		{
			int m = (l + r) / 2;
			if (A[m] == target) {return true;}
			if (A[l] < A[m])	// 如果左半边不包含旋转点
			{
				if (target < A[m] && target >= A[l])	// 如果在稳定递增的左半边
				{
					r = m;
				}else
				{
					l = m + 1;
				}
			}else if (A[l] > A[m]) // 如果左半边包含旋转点
			{
				if (target > A[m] && target <= A[r-1])	// 如果在稳定递增的右半边
				{
					l = m + 1;
				}else
				{
					r = m;
				}
			}else	// 如果不能确定旋转点在哪里，就l++，往后进行看看
			{
				++l;
			}
		}
		return false;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Search_in_Rotated_Sorted_Array_II", "[Arrays]"){
	Solution s;
	int A[7] = {4,5,6,7,0,1,2};
	int B[5] = {1,3,1,1,1};
	int C[5] = {1,1,1,3,1};
	SECTION("Empty Input"){
		REQUIRE(s.search2(NULL, 0, 3) == false);
	}
	SECTION("Find")	{
		REQUIRE(s.search2(A, 7, 2) == true);
		REQUIRE(s.search2(B, 5, 3) == true);
		REQUIRE(s.search2(C, 5, 3) == true);
	}
	SECTION("Not Find") {
		REQUIRE(s.search2(A, 7, 3) == false);
		REQUIRE(s.search2(B, 5, 2) == false);
		REQUIRE(s.search2(C, 5, 2) == false);
	}
}
