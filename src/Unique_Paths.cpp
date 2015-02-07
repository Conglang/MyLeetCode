//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).

The robot can only move either down or right at any point in time. The robot is trying to reach the bottom-right corner of the grid (marked 'Finish' in the diagram below).

How many possible unique paths are there?


Above is a 3 x 7 grid. How many possible unique paths are there?

Note: m and n will be at most 100.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way 1
// 会超时。时间复杂度O(n^4)，空间复杂度O(n)
class Solution
{
public:
	int uniquePaths(int m, int n)
	{
		if (m < 1 || n < 1) return 0;
		if (m == 1 && n == 1) return 1;
		return uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
	}
};

// Learned Way 2
// 深度搜索 + 缓存，备忘录法。
// 时间复杂度O(n^2)，空间复杂度O(n^2)
class Solution {
public:
	int uniquePaths(int m, int n) {
		m_memory.assign(m+1, vector<int>(n+1, 0));	// 0行和0列未使用
		return dfs(m, n);
	}
private:
	vector<vector<int> > m_memory;

	int dfs(int m, int n)
	{
		if (m < 1 || n < 1) return 0;
		if (m == 1 && n == 1) return 1;
		return get_or_update(m - 1, n) + get_or_update(m, n - 1);
	}

	int get_or_update(int x, int y)
	{
		if (m_memory[x][y] > 0) return m_memory[x][y];
		else return m_memory[x][y] = dfs(x, y);
	}
};

// Learned Way 3
// 既然可以用备忘录法自顶向下解决，也一定可以用动规自底向上解决。
// 设状态为f[i][j]，表示从起点(1 , 1)到达( i, j )的路线条数，则状态转移方程为：
// f[i][j]=f[i-1][j]+f[i][j-1]
// 时间复杂度O(n^2) ，空间复杂度O(n)
class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<int> f(n, 0);
		f[0] = 1;
		for (int i = 0; i < m; ++i)
		{
			for (int j = 1; j < n; ++j)
			{
				// 左边的f[j]，表示更新后的f[j]，与公式中的f[i][j]对应
				// 右边的f[j]，表示老的f[j]，与公式中的f[i-1][j]对应
				f[j] = f[j-1] + f[j];
			}
		}
		return f[n-1];
	}
};
