//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/5
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
* 
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
* 
* Example 1:
* nums1 = [1, 3]
* nums2 = [2]
* 
* The median is 2.0
* Example 2:
* nums1 = [1, 2]
* nums2 = [3, 4]
* 
* The median is (2 + 3)/2 = 2.5
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 这个问题的更通用形式是寻找两个排序数组中第k大的元素。
// 从O(log (m+n))想到二分。
// 比较两个数组k/2处的值，如果其中一方比较小，那么这一方0-k/2中一定不会有第k大元素，可以删掉。
// 递归该思路，每次删掉某数组的一半元素。
class Solution {
public:
    double find_kth(vector<int>::iterator first, int m, vector<int>::iterator second, int n, int k)
    {
        if (m > n)  {return find_kth(second, n, first, m, k);}
        if (!m)     {return *(second+k-1);}
        if (k == 1) {return min(*first, *second);}
        
        int ia = min(m, k/2);
        int ib = k - ia;
        
        if (*(first+ia-1) == *(second+ib-1))
        {
            return *(first+ia-1);
        }
        else if (*(first+ia-1) < *(second+ib-1))
        {
            return find_kth(first+ia, m-ia, second, n, k-ia);
        }
        else
        {
            return find_kth(first, m, second+ib, n-ib, k-ib);
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		if (nums1.empty() && nums2.empty())
			return 0.0;
        int total = nums1.size() + nums2.size();
        if (total % 2)
        {
            return find_kth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), total / 2 + 1);
        }else
        {
            return (find_kth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), total / 2) +
            find_kth(nums1.begin(), nums1.size(), nums2.begin(), nums2.size(), total / 2 + 1)) / 2.0;
        }
    }
};

/*
class Solution {
public:
	int find_kth(int A[], int m, int B[], int n, int k)
	{
		// assume m is smaller than n
		if (m > n)	{return find_kth(B, n, A, m, k);}
		if (!m)		{return B[k-1];}
		if (k == 1)	{return min(A[0], B[0]);}

		int ia = min(k / 2, m);
		int ib = k - ia;
		if		(A[ia - 1] == B[ib - 1])	{return A[ia - 1];}
		else if	(A[ia - 1] < B[ib - 1])		{return find_kth(A+ia, m-ia, B, n, k-ia);}
		else								{return find_kth(A, m, B+ib, n-ib, k-ib);}
	}

	double findMedianSortedArrays(int A[], int m, int B[], int n)
	{
		int total = m + n;
		if (total % 2)
		{
			return find_kth(A, m, B, n, total / 2 + 1);
		}else
		{
			return (find_kth(A, m, B, n, total / 2) + find_kth(A, m, B, n, total / 2 + 1)) / 2.0;
		}
	}
};*/

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Median_of_Two_Sorted_Arrays", "[Arrays]"){
	Solution s;
	SECTION("Empty") {
		vector<int> num1;
		vector<int> num2;
		REQUIRE(s.findMedianSortedArrays(num1, num2) == 0.0);
	}
	SECTION("Normal Odd") {
		int A[2] = {1,3};
		int B[1] = {2};
		vector<int> num1(A, A+2);
		vector<int> num2(B, B+1);
		REQUIRE(s.findMedianSortedArrays(num1, num2) == 2.0);
	}
	SECTION("Normal Even") {
		int A[2] = {1,2};
		int B[2] = {3,4};
		vector<int> num1(A, A+2);
		vector<int> num2(B, B+2);
		REQUIRE(s.findMedianSortedArrays(num1, num2) == 2.5);
	}
}