//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/4
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
//--------------------------------------------------------------------------------------------------------------*/
// My way
class Solution {
public:
	int search(int A[], int n, int target) {
		if (!n) {return -1;}
		// find pivot
		int pivot(-1);
		for (int i = 1; i < n; ++i)
		{
			if (A[i-1] > A[i])
			{
				pivot = i;
				break;
			}
		}
		// if there is a pivot
		int l(0), r(n-1);
		if (pivot >= 0)
		{
			// exceed boundary
			if ((target > A[pivot - 1]) || (target < A[pivot])) {return -1;}
			// first binary
			int m(0);
			l = pivot;
			r = pivot-1;
			if (target == A[m]) {return m;}
			else if (target < A[m]) {r = n - 1;}
			else {l = 1;}
		}
		// binary search
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (target == A[m]) {return m;}
			else if (target < A[m]) {r = m - 1;}
			else {l = m + 1;}
		}
		// no find
		return -1;
	}
};
//---------------------------------------------------
// Better Way
class Solution {
public:
	int search(int A[], int n, int target) {
		int l(0),r(n);
		while (l != r)
		{
			int m = (l + r) / 2;
			if (A[m] == target) {return m;}
			if (A[l] < A[m])
			{
				if (target < A[m] && target >= A[l])
				{
					r = m;
				}else
				{
					l = m + 1;
				}
			}else
			{
				if (target > A[m] && target <= A[r-1])
				{
					l = m + 1;
				}else
				{
					r = m;
				}
			}
		}
		return -1;
	}
};