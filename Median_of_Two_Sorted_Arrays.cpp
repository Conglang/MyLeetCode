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
// �������ĸ�ͨ����ʽ��Ѱ���������������е�k���Ԫ�ء�
// ��O(log (m+n))�뵽���֡�
// �Ƚ���������k/2����ֵ���������һ���Ƚ�С����ô��һ��0-k/2��һ�������е�k��Ԫ�أ�����ɾ����
// �ݹ��˼·��ÿ��ɾ��ĳ�����һ��Ԫ�ء�
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