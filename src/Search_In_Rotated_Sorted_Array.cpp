//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/4
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* You are given a target value to search. If found in the array return its index, otherwise return -1.
* 
* You may assume no duplicate exists in the array.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)��
// ���ֲ���
class Solution {
public:
	int search(int A[], int n, int target) {
		int l(0),r(n);	// ����[l,r)
		while (l != r)
		{
			int m = (l + r) / 2;
			if (A[m] == target) {return m;}
			if (A[l] < A[m])	// ������߲�������ת��
			{
				if (target < A[m] && target >= A[l])	// ������ȶ�����������
				{
					r = m;
				}else
				{
					l = m + 1;
				}
			}else // ������߰�����ת��
			{
				if (target > A[m] && target <= A[r-1])	// ������ȶ��������Ұ��
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
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Search_in_Rotated_Sorted_Array", "[Arrays]"){
	Solution s;
	int A[7] = {4,5,6,7,0,1,2};
	SECTION("Empty Input"){
		REQUIRE(s.search(NULL, 0, 3) == -1);
	}
	SECTION("Find")	{
		REQUIRE(s.search(A, 7, 2) == 6);
	}
	SECTION("Not Find") {
		REQUIRE(s.search(A, 7, 3) == -1);
	}
}
