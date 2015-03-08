//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
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
* 
* Given an integer n, return all distinct solutions to the n-queens puzzle.
* 
* Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
* 
* For example,
* There exist two distinct solutions to the 4-queens puzzle:
* 
* [
*  [".Q..",  // Solution 1
*   "...Q",
*   "Q...",
*   "..Q."],
* 
*  ["..Q.",  // Solution 2
*   "Q...",
*   "...Q",
*   ".Q.."]
* ]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 深搜+剪枝。时间复杂度O(n!)，空间复杂度O(n)。
class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > result;
		// 特殊情况。
		if (n == 0) {return result;}
		if (n == 1) {result.assign(1,vector<string>(1,"Q")); return result;}
		// 初始剪枝变量。
		columns.assign(n,-1);	// n个columns，每个均未占据，为-1。
		main_diag.assign(n*2-1,-1);	// 2n-1个主对角线，每个均未占据，为-1。
		anti_diag.assign(n*2-1,-1);	// 2n-1个副对角线，每个均未占据，为-1。

		vector<string> oneway;	// 一种可能的方法。
		dfs(result, oneway, n, 0);	// 深搜求解。
		// 想利用对称性化简，没有成功。
		/*if (!result.empty())
		{
			copy(result.begin(),result.end(),back_inserter(result));
			reverse(result.begin()+result.size()/2, result.end());
			for_each(result.begin()+result.size()/2, result.end(),
				[](vector<string>& line)
			{
				for_each(line.begin(),line.end(),[](string& row) {reverse(row.begin(),row.end());});
			});
		}*/
		return result;
	}
private:
	// 这三个变量用于剪枝。
	vector<int> columns;	// 表示已经放置的皇后占据了哪些列。
	vector<int> main_diag;	// 占据了哪些主对角线。
	vector<int> anti_diag;	// 占据了哪些副对角线。

	// 深搜。
	void dfs(vector<vector<string> >& result, vector<string>& oneway, int n, int r)
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
				// 如果已到最末行，加入结果集。
				if (r == n-1)
				{
					result.push_back(oneway);
				}else	// 否则继续对下一行深搜。
				{
					dfs(result,oneway,n,r+1);
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
TEST_CASE("N-Queens", "[Depth-First Search]"){
	Solution sln;
	vector<vector<string> > res;
	SECTION("Empty Input") {
		REQUIRE(sln.solveNQueens(0) == res);
	}
	SECTION("Normal Input") {
		res.assign(2,vector<string>(4,"...."));
		res[0][0][1] = 'Q';
		res[0][1][3] = 'Q';
		res[0][2][0] = 'Q';
		res[0][3][2] = 'Q';
		res[1][0][2] = 'Q';
		res[1][1][0] = 'Q';
		res[1][2][3] = 'Q';
		res[1][3][1] = 'Q';
		REQUIRE(sln.solveNQueens(4) == res);
	}
}