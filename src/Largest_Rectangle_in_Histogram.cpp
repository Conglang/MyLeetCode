//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/24
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
			6
		5	#
		#	#
		#	#		3
2		#	#	2	#
#	1	#	#	#	#
#	#	#	#	#	#
Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

			6
		5	#
		@	@
		@@		3
2		@	@	2	#
#	1	@@	#	#
#	#	@	@	#	#
The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 从左向右扫描，遇到小的就把之前比自己大的一起清算。
// 于是维护一个栈，比栈顶元素大的就入栈，否则就比较。
// 比较时从前一个比自己大的开始，逐步向左扩展计算，直到遇到比自己还小的或者空停止。
// 还没有想得特别清楚。
class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		if (height.empty()) {return 0;}
		int rect_area(0);
		height.push_back(0);
		stack<int> index;

		for (int i = 0; i < height.size(); ++i)
		{
			while (!index.empty() && height[index.top()] >= height[i])
			{
				int h = height[index.top()];
				index.pop();

				int sidx = index.empty() ? -1 : index.top();
				rect_area = max(rect_area, h*(i-sidx-1));
			}
			index.push(i);
		}
		return rect_area;
	}
};