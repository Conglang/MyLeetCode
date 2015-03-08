//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/31
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two sorted integer arrays A and B, merge B into A as one sorted array.
* 
* Note:
* You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ʱ�临�Ӷ�O(m+n)���ռ临�Ӷ�O(1)��
// ��������AB����Ԫ��ʱ����A��B�нϴ��Ԫ�ظ��Ƶ�A�����Ҷ˿��е�λ�á�
// ���B�л���ʣ�࣬�������ƣ����A����ʣ�����ô�����Ϊ�����Ѿ���Ӧ�õ�λ�����ˡ�
class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int ia = m - 1, ib = n - 1, icur = m + n - 1;
		while (ia >= 0 && ib >= 0)
		{
			A[icur--] = A[ia] >= B[ib] ? A[ia--] : B[ib--];
		}
		while (ib >= 0)
		{
			A[icur--] = B[ib--];
		}
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Merge_Sorted_Array", "[Sorting]"){
	Solution sln;
	SECTION("Normal Input"){
		int A[8] = {1,5,7};
		int B[5] = {2,3,4,6,8};
		int r[8] = {1,2,3,4,5,6,7,8};
		vector<int> result(r,r+8);
		sln.merge(A,3,B,5);
		REQUIRE(array_to_vector(A,8) == result);
	}
}