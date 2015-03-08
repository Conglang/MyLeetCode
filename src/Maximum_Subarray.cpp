//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
* 
* For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
* the contiguous subarray [4,-1,2,1] has the largest sum = 6.
* 
* click to show more practice.
* 
* More practice:
* If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1
#ifdef W1
// ��̬�滮��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
/*
*	��ͷ��β���������ʱ�򣬶����������һ��������������ѡ��
*	1. ����֮ǰ��SubArray����֮ǰ��SubArray����ʹ���0��ʱ����Ժ�������й��ס�
*	2. �Լ�����һ��SubArray����֮ǰ��SubArray�����С�ڻ����0ʱ�����Ϻ��ȡ�
*	����״̬ת�Ʒ���Ϊ��
*	��״̬Ϊf[i]����ʾ��Array[i]��β��������������к͡�
*	f[i] = max( f[i-1]+Array[i], Array[i] )
*	Ŀ������������f[i]��
*/
class Solution {
public:
	int maxSubArray(int A[], int n) {
		if (!A || !n) return 0;
		int result(A[0]);
		int f(0);
		for (int i = 0; i < n; ++i)
		{
			f = max(f+A[i], A[i]);
			result = max(result, f);
		}
		return result;
	}
};
#endif

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Maximum_Subarray", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.maxSubArray(NULL,0) == 0);
	}
	SECTION("Normal Input") {
		int A[] = {-2,1,-3,4,-1,2,1,-5,4};
		REQUIRE(sln.maxSubArray(A,9) == 6);
	}
}