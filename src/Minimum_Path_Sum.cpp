//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
* 
* Note: You can only move either down or right at any point in time.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 动态规划，时间复杂度O(n^2)，空间复杂度O(n)。
// 对于i行j列的位置，其经过的路程长度的递推关系式为：f[i,j] = min(f[i-1,j], f[i,j-1]) + grid[i][j]。
// 起始条件为f[0,0] = grid[0][0]
// 复用数组，变二维条件为一维，如下解法。
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (grid.empty()) return 0;
		const int m = grid.size();
		const int n = grid[0].size();
		vector<int> f(n, 0);
		f[0] = grid[0][0];	// 初始条件。
		for (int col = 1; col < n; ++col)
		{
			f[col] = f[col-1] + grid[0][col];	// 第一行。
		}
		for (int i = 1; i < m; ++i)
		{
			f[0] += grid[i][0];	// 第一列。
			for (int j = 1; j < n; ++j)
			{
				f[j] = min(f[j], f[j-1]) + grid[i][j];	// 其余行列位置。
			}
		}
		return f[n-1];
	}
};//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Minimum_Path_Sum", "[Dynamic Programming]"){
	Solution sln;
	vector<vector<int> > grid;
	SECTION("Empty Input")
	{
		REQUIRE(sln.minPathSum(grid) == 0);
	}
	SECTION("Normal Input") {
		int t1[2] = {1,2};
		vector<int> r1(t1,t1+2);
		vector<int> r2(2,1);
		grid.push_back(r1);
		grid.push_back(r2);
		REQUIRE(sln.minPathSum(grid) == 3);
	}
}