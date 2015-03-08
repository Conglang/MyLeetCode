//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
* 
* For example, 
* Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
* 
* |         #
* |     #~~~##~#
* |   #~##~######
* 
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
/* 
	����ÿ�����ӣ��ҵ�������������ߵ����ӣ������������ɵ�������� min(max_left, max_right) - height�����ԣ�
	1. ɨ��һ�飬�ҵ���ߵ����ӣ�������ӽ������Ϊ���룻
	2. �������һ�룻
	3. �����ұ�һ�롣
*/
class Solution {
public:
	int trap(int A[], int n) {
		int water(0);
		if (n < 2) {return 0;}
		int max_index(0);
		for (int i = 0; i < n; ++i)
		{
			if (A[i] > A[max_index])
			{
				max_index = i;
			}
		}
		for (int i = 0, peak = 0; i < max_index; ++i)
		{
			if (A[i] > peak) {peak = A[i];}
			else {water += peak - A[i];}
		}
		for (int i = n - 1, peak = 0; i > max_index; --i)
		{
			if (A[i] > peak) {peak = A[i];}
			else {water += peak - A[i];}
		}
		return water;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Trapping_Rain_Water", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.trap(NULL, 0) == 0);
	}
	SECTION("Normal Input"){
		int A[12] = {0,1,0,2,1,0,1,3,2,1,2,1};
		REQUIRE(s.trap(A,12) == 6);
	}
}