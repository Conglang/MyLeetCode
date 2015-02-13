//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/7
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a sorted array of integers, find the starting and ending position of a given target value.
* 
* Your algorithm's runtime complexity must be in the order of O(log n).
* 
* If the target is not found in the array, return [-1, -1].
* 
* For example,
* Given [5, 7, 7, 8, 8, 10] and target value 8,
* return [3, 4].
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
#define  W3

#ifdef W1
// 时间复杂度O(n)，空间复杂度O(1)
// 改进空间：二分。
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> result(2, -1);
		int left = 0;
		int right = n-1;
		if (A[left] > target || A[right] < target) {return result;}

		while (left < n-1 && A[left] < target) {++left;}
		while (right > -1 && A[right] > target) {--right;}

		if (left < right)
		{
			result[0] = left;
			result[1] = right;
		}else if (left == right)
		{
			result.assign(2, left);
		}
		return result;
	}
};
#endif

#ifdef W2
// 偷懒的做法，使用 STL
// 时间复杂度 O(logn)，空间复杂度 O(1)
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		const int l = distance(A, lower_bound(A, A + n, target));
		const int u = distance(A, prev(upper_bound(A, A + n, target)));
		if (A[l] != target) // not found
			return vector<int> { -1, -1 };
		else
			return vector<int> { l, u };
	}
};
#endif

#ifdef W3
// 重新实现lower_bound和upper_bound
// 时间复杂度O(logn)，空间复杂度O(1)。
class Solution {
public:
	vector<int> searchRange (int A[], int n, int target) {
		auto lower = lower_bound(A, A + n, target);
		auto uppper = upper_bound(lower, A + n, target);
		if (lower == A + n || *lower != target)
#if __cplusplus < 201103L
			return vector<int>(2, -1);
#else
			return vector<int> { -1, -1 };
#endif
		else
#if __cplusplus < 201103L
		{
			vector<int> temp;
			temp.push_back(distance(A, lower));
			temp.push_back(distance(A, prev(uppper)));
			return temp;
		}	
#else
			return vector<int> {distance(A, lower), distance(A, prev(uppper))};
#endif
	}
	template<typename ForwardIterator, typename T>
	ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, T value)
	{
			while (first != last)
			{
				auto mid = next(first, distance(first, last) / 2);
				if (value > *mid) first = ++mid;
				else last = mid;
			}
			return first;
	}
	template<typename ForwardIterator, typename T>
	ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, T value)
	{
			while (first != last)
			{
				auto mid = next(first, distance (first, last) / 2);
				if (value >= *mid) first = ++mid; // 与 lower_bound 仅此不同
				else last = mid;
			}
			return first;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Search for a range", "[Searching]"){
	Solution s;
	SECTION("Empty Input"){
		vector<int> result(2, -1);
		REQUIRE(s.searchRange(NULL, 0, 0) == result);
	}
	SECTION("Single Input"){
		vector<int> result(2, 1);
		int A[3] = {0, 1, 2};
		REQUIRE(s.searchRange(A, 3, 1) == result);
	}
	SECTION("Normal Input"){
		vector<int> result;
		result.push_back(1);
		result.push_back(5);
		int A[6] = {0, 5, 5, 5, 5, 5};
		REQUIRE(s.searchRange(A, 6, 5) == result);
	}
}