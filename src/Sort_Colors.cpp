//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/7
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array with n objects colored red, white or blue, sort them so that objects of the
* same color are adjacent, with the colors in the order red, white and blue.
* 
* Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
* 
* Note:
* You are not suppose to use the library's sort function for this problem.
* 
* click to show follow up.
* 
* Follow up:
* A rather straight forward solution is a two-pass algorithm using counting sort.
* First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with
* total number of 0's, then 1's and followed by 2's.
* 
* Could you come up with an one-pass algorithm using only constant space?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W3

#ifdef W1
// 简洁。分治法。
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
	void sortColors(int A[], int n) {
		// 一个是red的index，一个是blue的index，两边往中间走。
		int red = 0, blue = n - 1;
		for (int i = 0; i < blue + 1;) {
			if (A[i] == 0)
				swap(A[i++], A[red++]);
			else if (A[i] == 2)
				swap(A[i], A[blue--]);
			else
				i++;
		}
	}
};
#endif

#ifdef W2
// use partition()
// 时间复杂度 O(n) ，空间复杂度 O(1)
class Solution {
public:
	void sortColors(int A[], int n) {
		partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n, bind1st(equal_to<int>(), 1));
	}
};
#endif

#ifdef W3
// 重新实现 partition()
// 时间复杂度 O(n) ，空间复杂度 O(1)
class Solution {
public:
	void sortColors(int A[], int n) {
		partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n, bind1st(equal_to<int>(), 1));
	}
private:
	template<typename ForwardIterator, typename UnaryPredicate>
	ForwardIterator partition(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)
	{
			auto pos = first;
			for (; first != last; ++first)
				if (pred(*first))
					swap(*first, *pos++);
			return pos;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Sort_Colors", "[Sorting]"){
	Solution sln;
	SECTION("Normal Input1")
	{
		int A[10] = {0,1,2,1,0,0,2,1,2,0};
		int r[10] = {0,0,0,0,1,1,1,2,2,2};
		sln.sortColors(A,10);
		REQUIRE(array_to_vector(A,10) == array_to_vector(r,10));
	}
	SECTION("Normal Input2")
	{
		int A[1] = {2};
		sln.sortColors(A,1);
		REQUIRE(array_to_vector(A,1) == array_to_vector(A,1));
	}
}