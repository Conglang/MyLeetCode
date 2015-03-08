//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/5
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Follow up for "Search in Rotated Sorted Array":
* What if duplicates are allowed?
* 
* Would this affect the run-time complexity? How and why?
* 
* Write a function to determine if a given target is in the array.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)��
// ���ֲ���
// ��A[l] == A[m]���޷�ȷ������ʱ������++l;
class Solution {
public:
	bool search2(int A[], int n, int target) {
		int l(0),r(n);	// ����[l,r)
		while (l != r)
		{
			int m = (l + r) / 2;
			if (A[m] == target) {return true;}
			if (A[l] < A[m])	// ������߲�������ת��
			{
				if (target < A[m] && target >= A[l])	// ������ȶ�����������
				{
					r = m;
				}else
				{
					l = m + 1;
				}
			}else if (A[l] > A[m]) // ������߰�����ת��
			{
				if (target > A[m] && target <= A[r-1])	// ������ȶ��������Ұ��
				{
					l = m + 1;
				}else
				{
					r = m;
				}
			}else	// �������ȷ����ת���������l++��������п���
			{
				++l;
			}
		}
		return false;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Search_in_Rotated_Sorted_Array_II", "[Arrays]"){
	Solution s;
	int A[7] = {4,5,6,7,0,1,2};
	int B[5] = {1,3,1,1,1};
	int C[5] = {1,1,1,3,1};
	SECTION("Empty Input"){
		REQUIRE(s.search2(NULL, 0, 3) == false);
	}
	SECTION("Find")	{
		REQUIRE(s.search2(A, 7, 2) == true);
		REQUIRE(s.search2(B, 5, 3) == true);
		REQUIRE(s.search2(C, 5, 3) == true);
	}
	SECTION("Not Find") {
		REQUIRE(s.search2(A, 7, 3) == false);
		REQUIRE(s.search2(B, 5, 2) == false);
		REQUIRE(s.search2(C, 5, 2) == false);
	}
}
