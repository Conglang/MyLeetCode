//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/5
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// Important
// 这个问题的更通用形式是寻找两个排序数组中第k大的元素。
// 从O(log (m+n))想到二分。
// 比较两个数组k/2处的值，如果其中一方比较小，那么这一方0-k/2中一定不会有第k大元素，可以删掉。
// 递归该思路，每次删掉某数组的一半元素。
class Solution {
public:
	int find_kth(int A[], int m, int B[], int n, int k)
	{
		// assume m is smaller than n
		if (m > n) {return find_kth(B, n, A, m, k);}
		if (!m) {return B[k-1];}
		if (k == 1) {return min(A[0], B[0]);}

		int ia = min(k / 2, m);
		int ib = k - ia;
		if (A[ia - 1] == B[ib - 1]) {return A[ia - 1];}
		else if(A[ia - 1] < B[ib - 1]) {return find_kth(A+ia, m-ia, B, n, k-ia);}
		else {return find_kth(A, m, B+ib, n-ib, k-ib);}
	}
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		int total = m + n;
		if (total % 2)
		{
			return find_kth(A, m, B, n, total / 2 + 1);
		}else
		{
			return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
		}
	}
};