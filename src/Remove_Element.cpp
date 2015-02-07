//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array and a value, remove all instances of that value in place and return the new length.
* 
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
#define W1

#ifdef W1
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int index = 0;
		for (int i = 0; i < n; ++i)
		{
			if (A[i] != elem)
			{
				A[index++] = A[i];
			}
		}
		return index;
	}
};
#endif

#ifdef W2
// 使用 remove()，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		return distance(A, remove(A, A+n, elem));
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Remove_Element", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.removeElement(NULL,0,0) == 0);
	}
	SECTION("Normal Input"){
		int A[5] = {2,1,3,1,5};
		REQUIRE(s.removeElement(A,5,1) == 3);
		REQUIRE(s.removeElement(A,5,4) == 5);
	}
}