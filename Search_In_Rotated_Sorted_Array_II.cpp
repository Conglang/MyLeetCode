//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/5
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
//--------------------------------------------------------------------------------------------------------------*/
// 当A[l] == A[m]，无法确定方向时，单纯++l;
class Solution {
public:
	bool search(int A[], int n, int target) {
		int l(0),r(n);
		while (l != r)
		{
			int m = (l + r) / 2;
			if (A[m] == target) {return true;}
			if (A[l] < A[m])
			{
				if (target < A[m] && target >= A[l])
				{
					r = m;
				}else
				{
					l = m + 1;
				}
			}else if (A[l] > A[m])
			{
				if (target > A[m] && target <= A[r-1])
				{
					l = m + 1;
				}else
				{
					r = m;
				}
			}else
			{
				++l;
			}
		}
		return false;
	}
};