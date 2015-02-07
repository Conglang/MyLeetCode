//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/8
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 ¡ú 2
[1,3,5,6], 2 ¡ú 1
[1,3,5,6], 7 ¡ú 4
[1,3,5,6], 0 ¡ú 0
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
class Solution {
public:
	int searchInsert(int A[], int n, int target) {
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