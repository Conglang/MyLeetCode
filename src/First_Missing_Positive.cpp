//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/6
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an unsorted integer array, find the first missing positive integer.
* 
* For example,
* Given [1,2,0] return 3,
* and [3,4,-1,1] return 2.
* 
* Your algorithm should run in O(n) time and uses constant space.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// Ͱ����bucket sort��ÿ��A[i] != i+1ʱ����A[i]��A[A[i]-1]������
// ֱ���޷�����Ϊֹ����ֹ������A[i] == A[A[i]-1]��
// �����õ�����5�Ͱ����ŵ���1����5��λ���ϣ��������Ȼ�󿴿��Ǹ�λ���ϵ����ֲ���ȷ���ɡ�
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		bucket_sort(A, n);
		for (int i = 0; i < n; ++i)
		{
			if (A[i] != (i+1)) 
				return i+1;
		}
		return n+1;
	}
private:
	void bucket_sort(int A[], int n)
	{
		for (int i = 0; i < n; ++i)
		{
			while (A[i] != i + 1)
			{
				if (A[i] <= 0 || A[i] > n || A[i] == A[A[i] - 1])
				{
					break;
				}
				swap(A[i], A[A[i]-1]);
			}
		}
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("First_Missing_Positive", "[Sorting]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.firstMissingPositive(NULL,0) == 1);
	}
	SECTION("Normal Input"){
		int A1[3] = {1,2,0};
		int A2[4] = {3,4,-1,1};
		REQUIRE(sln.firstMissingPositive(A1,3) == 3);
		REQUIRE(sln.firstMissingPositive(A2,4) == 2);
	}
}