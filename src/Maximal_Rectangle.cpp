//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a 2D binary matrix filled with 0's and 1's,
* find the largest rectangle containing all ones and return its area.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/*
*	动态规划。从第一行开始逐行处理。在行i和列j上的最大矩形这样计算：
*	[right(i,j) - left(i,j)] * height(i,j)。
*	height是所在列已处理过的行上连续的1的数量。
*	left是包含当前点有height高度的最大矩形的左边界。
*	right是包含当前点有height高度的最大矩形的右边界。
*	递推关系如下：
*	left(i,j) = max(left(i-1,j), curleft)
*	right(i,j) = min(right(i-1, j), curright)
*	height(i,j) = height(i-1,j) + 1	如果matrix[i][j] == 1
*	height(i,j) = 0	如果matrix[i][j] == 0
*	对于每一行迭代计算出其最大矩形。
*	对于每一列，
*	到下一行如果还是1，就保持height，重新计算最右的left和最左的right。
*	到下一行如果是0，height清0，此列上之前的矩形信息清空，不再延续。
*/
// 时间复杂度O(n^2)，空间复杂度O(n)。
class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.empty()) return 0;
		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<int> left(n,0);
		vector<int> right(n,n);
		vector<int> height(n,0);
		int maxrect(0);
		for (int i = 0; i < m; ++i)
		{
			int curleft(0), curright(n);
			// 计算height，方向随意。
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '1') {++height[j];}
				else {height[j] = 0;}
			}
			// 计算left，从左到右。
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '1') { left[j] = max(left[j], curleft);}
				else {left[j] = 0; curleft = j+1;}
			}
			// 计算right，从右向左。
			for (int j = n-1; j >= 0; --j)
			{
				if (matrix[i][j] == '1') {right[j] = min(right[j], curright);}
				else {right[j] = n; curright = j;}
			}
			// 计算矩形面积，方向随意。
			for (int j = 0; j < n; ++j)
			{
				maxrect = max(maxrect, height[j]*(right[j]-left[j]));
			}
		}
		return maxrect;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Maximal_Rectangle", "[Dynamic Programming]"){
	Solution sln;
	vector<vector<char> > matrix;
	SECTION("Empty Input") {
		REQUIRE(sln.maximalRectangle(matrix) == 0);
	}
	SECTION("Normal Input1") {
		vector<char> temp(1,'1');
		matrix.push_back(temp);
		REQUIRE(sln.maximalRectangle(matrix) == 1);
	}
	SECTION("Normal Input2") {
		char t1[5] = {'0','1','0','0','1'};
		char t2[5] = {'0','1','1','1','1'};
		char t3[5] = {'1','1','1','1','0'};
		vector<char> r1(t1,t1+5);
		vector<char> r2(t2,t2+5);
		vector<char> r3(t3,t3+5);
		matrix.push_back(r1);
		matrix.push_back(r2);
		matrix.push_back(r3);
		REQUIRE(sln.maximalRectangle(matrix) == 6);
	}
}