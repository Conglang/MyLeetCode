//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given n non-negative integers representing an elevation map where the width of each bar is 1,
* compute how much water it is able to trap after raining.
* 
* For example, 
* Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
* 
* |         #
* |     #~~~##~#
* |   #~##~######
* 
* The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
* In this case, 6 units of rain water (blue section) are being trapped.
* Thanks Marcos for contributing this image!
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1
#ifdef W1
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
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
#endif

#ifdef W2
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
// ��������ɨһ�飬���������ұ����ӱȽϸߵĴ�ˮ����Ȼ���ٴ��ҵ���ɨһ�顣��������W1��
class Solution {
public:
	int trap(int A[], int n) {
		if (!A || !n) return 0;
		int water(0);
		for (int l = 0; l < n-1;)
		{
			for (int r = l+1; r < n; ++r)
			{
				if (A[r] >= A[l])
				{
					int sum(0);
					for_each(A+l, A+r, [&](int n){sum+=n;});
					water += (A[l]*(r-l) - sum/*accumulate(A+l, A+r, 0)*/);
					l = r-1;
					break;
				}
			}
			++l;
		}
		for (int l = n-1; l > 0;)
		{
			for (int r = l-1; r >= 0; --r)
			{
				if (A[r] == A[l])
				{
					l = r+1;
					break;
				}
				if (A[r] > A[l])
				{
					int sum(0);
					for_each(A+r+1, A+l+1, [&](int n){sum+=n;});
					water += (A[l]*(l-r) - sum/*accumulate(A+r+1, A+l+1, 0)*/);
					l = r+1;
					break;
				}
			}
			--l;
		}
		return water;
	}
};
#endif
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