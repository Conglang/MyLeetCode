//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a triangle, find the minimum path sum from top to bottom.
* Each step you may move to adjacent numbers on the row below.
* 
* For example, given the following triangle
* [
*      [2],
*     [3,4],
*    [6,5,7],
*   [4,1,8,3]
* ]
* The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
* 
* Note:
* Bonus point if you are able to do this using only O(n) extra space,
* where n is the total number of rows in the triangle.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 动态规划。时间复杂度O(nlogn)，空间复杂度O(n)。
/*
*	0
*	0 1
*	0 1 2
*	0 1 2 3
*	得到递推关系f(row,column) = min( f(row-1,column), f(row-1,column-1) ) + T[row][column]。
*	起始f(0,0) = T[0][0]。
*	为只用row大小额外空间。每次计算时从右向左计算。
*/
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty()) return 0;
		const int n = triangle.size();	// n就是总行数
#if __cplusplus < 201103L
		vector<int> f(n,0);
#else
		int f[n];
		fill_n(f,n,0);	// 用于动态规划计算的数组。
#endif
		f[0] = triangle[0][0];	// 起始条件f[0]。
		for (int row = 1; row < n; ++row)	// 对于每行，从右向左依次计算距离。
		{
			f[row] = f[row-1] + triangle[row][row];	// 每行最右端的。
			for (int i = row-1; i > 0; --i)	// 每行中间的。
			{
				f[i] = min(f[i],f[i-1])+triangle[row][i];
			}
			f[0] = f[0] + triangle[row][0];	// 每行最左端的。
		}
		int result(f[n-1]);
		for (int last_row_index = 0; last_row_index < n; ++last_row_index)	// 得到最后一行中，最小的值。
		{
			result = min(result, f[last_row_index]);
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Triangle", "[Dynamic Programming]"){
	Solution sln;
	vector<vector<int> > triangle;
	SECTION("Empty Input") {
		REQUIRE(sln.minimumTotal(triangle) == 0);
	}
	SECTION("Normal Input") {
		vector<int> row1(1,2);
		int t2[2] = {3,4};
		vector<int> row2(t2,t2+2);
		int t3[3] = {6,5,7};
		vector<int> row3(t3,t3+3);
		int t4[4] = {4,1,8,3};
		vector<int> row4(t4,t4+4);
		triangle.push_back(row1);
		triangle.push_back(row2);
		triangle.push_back(row3);
		triangle.push_back(row4);
		REQUIRE(sln.minimumTotal(triangle) == 11);
	}
}