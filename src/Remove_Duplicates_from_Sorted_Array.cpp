//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
* 
* Do not allocate extra space for another array, you must do this in place with constant memory.
* 
* For example,
* Given input array A = [1,1,2],
* 
* Your function should return length = 2, and A is now [1,2].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1
// 时间复杂度O(n)，空间复杂度O(1)。
// 是已经排序过的数组。
#ifdef W1
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (!A || !n) {return 0;}
		int index(0);
		for (int i = 1; i < n; ++i)
		{
			if (A[index] != A[i])
			{
				A[++index] = A[i];
			}
		}
		return index + 1;
	}
};
#endif
#ifdef W2
// 使用 STL，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		return distance(A, unique(A, A + n));
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Remove_Duplicates_from_Sorted_Array", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.removeDuplicates(NULL, 0) == 0);
	}
	SECTION("Normal Input"){
		int A[3] = {1,1,2};
		REQUIRE(s.removeDuplicates(A,3) == 2);
		REQUIRE(A[0] == 1);
		REQUIRE(A[1] == 2);
	}
}