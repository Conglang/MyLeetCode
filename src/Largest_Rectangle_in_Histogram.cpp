//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/24
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
* 			6
* 		5	#
* 		#	#
* 		#	#		3
* 2		#	#	2	#
* #	1	#	#	#	#
* #	#	#	#	#	#
* Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
* 
* 			6
* 		5	#
* 		~	~
* 		~	~		3
* 2		~	~	2	#
* #	1	~	~	#	#
* #	#	~	~	#	#
* The largest rectangle is shown in the shaded area, which has area = 10 unit.
* 
* For example,
* Given height = [2,1,5,6,2,3],
* return 10.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/*
*	��������ɨ�裬������֮ǰ��ľ���ջ����Ϊ�ܱ�֤֮ǰ�߶ȿ��԰����ھ����ڣ�
*	�������С�ģ�֮ǰ�ĸ߶Ȳ���ȷ����������Ҫ����һ�¾��β���¼��
*	�ӵ�ǰС�߶���ǰ���㣬ǰ�涼�ǵ����ĸ߶ȣ����μ���߶�*��������룬ȡ���ֵ��
*/
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		if (height.empty()) {return 0;}
		int rect_area(0);
		height.push_back(0);
		stack<int> indexes;

		for (int i = 0; i < height.size();)
		{
			if (indexes.empty() || height[i] > height[indexes.top()])
			{
				indexes.push(i++);
			}else{
				int temp = indexes.top();
				indexes.pop();
				rect_area = max(rect_area, height[temp] * (indexes.empty() ? i : i - indexes.top() - 1));
			}
		}
		return rect_area;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Largest_Rectangle_in_Histogram", "[Stacks]"){
	Solution sln;
	vector<int> height;
	SECTION("Empty Input"){
		REQUIRE(sln.largestRectangleArea(height) == 0);
	}
	SECTION("Normal Input"){
		int temp[6] = {2,1,5,6,2,3};
		height.assign(temp, temp+6);
		REQUIRE(sln.largestRectangleArea(height) == 10);
	}
}