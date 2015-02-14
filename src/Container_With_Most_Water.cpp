//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
* 
* Note: You may not slant the container.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 贪心法，两边逼近，计算面积。每次从最低的那段向中间逼近。
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
	int maxArea(vector<int> &height) {
		if (height.empty()) return 0;
		int max_area(0);
		int left(0), right(height.size()-1);
		while (left < right)
		{
			int area = (right - left) * min(height[left],height[right]);
			max_area = max(max_area, area);
			if (height[left] < height[right]) {++left;}
			else {--right;}
		}
		return max_area;
	}
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Container_With_Most_Water", "[]"){
	Solution sln;
	vector<int> height;
	SECTION("Empty Input") {
		REQUIRE(sln.maxArea(height) == 0);
	}
	SECTION("Normal Input1") {
		int temp[7] = {1,2,3,4,5,6,7};
		height.assign(temp,temp+7);
		REQUIRE(sln.maxArea(height) == 12);	// 3~7, 3*4=12
	}
	SECTION("Normal Input2") {
		int temp[5] = {1,2,3,2,2};
		height.assign(temp,temp+5);
		REQUIRE(sln.maxArea(height) == 6);
	}
}