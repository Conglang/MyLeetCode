//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Follow up for "Unique Paths":

Now consider if some obstacles are added to the grids. How many unique paths would there be?

An obstacle and empty space is marked as 1 and 0 respectively in the grid.

For example,
There is one obstacle in the middle of a 3x3 grid as illustrated below.

[
[0,0,0],
[0,1,0],
[0,0,0]
]
The total number of unique paths is 2.

Note: m and n will be at most 100.
//--------------------------------------------------------------------------------------------------------------*/
// My Way
// ����¼����ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n^2)
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.empty()) return 0;
		int m(obstacleGrid.size());
		int n(obstacleGrid[0].size());
		m_memory.assign(m, vector<int>(n, 0));
		return dfs(obstacleGrid, m - 1, n - 1);
	}
private:
	vector<vector<int> > m_memory;

	int dfs(const vector<vector<int> >& obstacleGrid, int m, int n)
	{
		bool is_left(true), is_up(true);
		if (m < 0 || n < 0) return 0;
		if (obstacleGrid[m][n]) return 0;
		if (m == 0 && n == 0) return 1;
		return get_or_update(obstacleGrid, m - 1, n) + get_or_update(obstacleGrid, m, n - 1);
	}

	int get_or_update(const vector<vector<int> >& obstacleGrid,int x, int y)
	{
		if (x < 0 || y < 0) return 0;
		if (m_memory[x][y] > 0) return m_memory[x][y];
		else return m_memory[x][y] = dfs(obstacleGrid, x, y);
	}
};

// Learned Way 1
// ��̬�滮��ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		const int m = obstacleGrid.size();
		const int n = obstacleGrid[0].size();
		if (obstacleGrid[0][0] || obstacleGrid[m-1][n-1]) return 0;
		vector<int> f(n, 0);
		f[0] = obstacleGrid[0][0] ? 0 : 1;
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				f[j] = obstacleGrid[i][j] ? 0 : (j == 0 ? 0 : f[j - 1]) + f[j];
		return f[n - 1];
	}
};