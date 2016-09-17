//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/8
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a sorted array and a target value, return the index if the target is found.
* If not, return the index where it would be if it were inserted in order.
* 
* You may assume no duplicates in the array.
* 
* Here are few examples.
* [1,3,5,6], 5 → 2
* [1,3,5,6], 2 → 1
* [1,3,5,6], 7 → 4
* [1,3,5,6], 0 → 0
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)。
// 使用lower_bound即可找到插入位置，lower_bound内使用二分查找。
class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		if (!A || !n) {return 0;}
		return lower_bound(A, A+n, target) - A;
	}

	template <typename ForwardIterator, typename T>
	ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T value)
	{
		while (first != last)
		{
			auto mid = next(first, distance(first, last) / 2);
			if (value > *mid) first = ++mid;
			else last = mid;
		}
		return first;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Search_Insert_Position", "[Searching]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.searchInsert(NULL, 0, 5) == 0);
	}
	SECTION("Normal Input"){
		int A[4] = {1,3,5,6};
		REQUIRE(sln.searchInsert(A, 4, 5) == 2);
		REQUIRE(sln.searchInsert(A, 4, 2) == 1);
		REQUIRE(sln.searchInsert(A, 4, 7) == 4);
		REQUIRE(sln.searchInsert(A, 4, 0) == 0);
	}
}
