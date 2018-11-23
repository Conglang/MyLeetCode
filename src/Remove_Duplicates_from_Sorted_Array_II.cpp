//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/4
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Follow up for "Remove Duplicates":
* What if duplicates are allowed at most twice?
* 
* For example,
* Given sorted array A = [1,1,1,2,2,3],
* 
* Your function should return length = 5, and A is now [1,1,2,2,3].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)。
// 是已排序的数组。
class Solution {
public:
	int removeDuplicates_2(int A[], int n) {
		if (n <= 2) {return n;}
		int index(2);
		for (int i = 2; i < n; ++i)
		{
			if (A[i] != A[index-2])
			{
				A[index++] = A[i];
			}
		}
		return index;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Remove_Duplicates_from_Sorted_Array_II", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.removeDuplicates_2(NULL, 0) == 0);
	}
	SECTION("Normal Input"){
		int A[3] = {1,1,2};
		REQUIRE(s.removeDuplicates_2(A,3) == 3);
		REQUIRE(A[0] == 1);
		REQUIRE(A[1] == 1);
		REQUIRE(A[2] == 2);
		int B[3] = {1,1,1};
		REQUIRE(s.removeDuplicates_2(B,3) == 2);
		REQUIRE(B[0] == 1);
		REQUIRE(B[1] == 1);
	}
}