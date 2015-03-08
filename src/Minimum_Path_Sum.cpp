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
// ��̬�滮��ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)��
// ����i��j�е�λ�ã��侭����·�̳��ȵĵ��ƹ�ϵʽΪ��f[i,j] = min(f[i-1,j], f[i,j-1]) + grid[i][j]��
// ��ʼ����Ϊf[0,0] = grid[0][0]
// �������飬���ά����Ϊһά�����½ⷨ��
class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		if (grid.empty()) return 0;
		const int m = grid.size();
		const int n = grid[0].size();
		vector<int> f(n, 0);
		f[0] = grid[0][0];	// ��ʼ������
		for (int col = 1; col < n; ++col)
		{
			f[col] = f[col-1] + grid[0][col];	// ��һ�С�
		}
		for (int i = 1; i < m; ++i)
		{
			f[0] += grid[i][0];	// ��һ�С�
			for (int j = 1; j < n; ++j)
			{
				f[j] = min(f[j], f[j-1]) + grid[i][j];	// ��������λ�á�
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