//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Follow up for N-Queens problem.
* 
* Now, instead outputting board configurations, return the total number of distinct solutions.
* 
*	   a b c d e f g h
*	 8 . . . K . . . . 8
*	 7 . . . . . . K . 7
*	 6 . . K . . . . . 6
*	 5 . . . . . . . K 5
*	 4 . K . . . . . . 4
*	 3 . . . . K . . . 3
*	 2 K . . . . . . . 2
*	 1 . . . . . K . . 1
*	   a b c d e f g h
* One solution to the eight queens puzzle.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 只要求数量，沿用上题算法。但是一定有更简单的解法。
// 深搜+剪枝。时间复杂度O(n!)，空间复杂度O(n)。
class Solution {
public:
	int totalNQueens(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		// 初始剪枝变量。
		columns.assign(n,-1);	// n个columns，每个均未占据，为-1。
		main_diag.assign(n*2-1,-1);	// 2n-1个主对角线，每个均未占据，为-1。
		anti_diag.assign(n*2-1,-1);	// 2n-1个副对角线，每个均未占据，为-1。

		int count(0);
		vector<string> oneway;	// 一种可能的方法。
		dfs(count, oneway, n, 0);	// 深搜求解。
		return count;
	}
private:
	// 这三个变量用于剪枝。
	vector<int> columns;	// 表示已经放置的皇后占据了哪些列。
	vector<int> main_diag;	// 占据了哪些主对角线。
	vector<int> anti_diag;	// 占据了哪些副对角线。

	// 深搜。
	void dfs(int& count, vector<string>& oneway, int n, int r)
	{
		int m = /*r==0 ? (n+1)/2 :*/ n;	// 想利用对称性化简，没有成功。
		for (int j = 0; j < m; ++j)
		{
			if (is_valid(oneway, r, j, n))	// 判断当前方案是否合法。
			{
				string str(n,'.');
				str[j] = 'Q';
				oneway.push_back(str);	// 当前方案加入本行。
				// 记录剪枝用变量。
				columns[j] = r;
				main_diag[j-r+n-1] = r;
				anti_diag[j+r] = r;
				// 如果已到最末行，计数加1。
				if (r == n-1)
				{
					++count;
				}else	// 否则继续对下一行深搜。
				{
					dfs(count,oneway,n,r+1);
				}
				// 恢复各种状态。
				oneway.pop_back();
				columns[j] = -1;
				main_diag[j-r+n-1] = -1;
				anti_diag[j+r] = -1;
			}
		}
	}
	// 根据剪枝变量判断当前方案是否合法。
	bool is_valid(const vector<string>& board, int x, int y, int n)
	{
		bool is_column = columns[y] == -1;
		bool is_main_diag = main_diag[y-x+n-1] == -1;
		bool is_anti_diag = anti_diag[x+y] == -1;
		return is_column && is_main_diag && is_anti_diag;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("N-Queens_II", "[Depth-First Search]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.totalNQueens(0) == 0);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.totalNQueens(2) == 0);
		REQUIRE(sln.totalNQueens(4) == 2);
	}
}