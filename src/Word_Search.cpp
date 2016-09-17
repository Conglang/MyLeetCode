//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a 2D board and a word, find if the word exists in the grid.
* 
* The word can be constructed from letters of sequentially adjacent cell,
* where "adjacent" cells are those horizontally or vertically neighboring.
* The same letter cell may not be used more than once.
* 
* For example,
* Given board =
* 
* [
*   ["ABCE"],
*   ["SFCS"],
*   ["ADEE"]
* ]
* word = "ABCCED", -> returns true,
* word = "SEE", -> returns true,
* word = "ABCB", -> returns false.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 深搜，递归
// 时间复杂度O(n^2*m^2)，空间复杂度O(n^2)。
class Solution {
public:
	bool exist(vector<vector<char> > &board, string word) {
		if (word.empty()) return true;
		if (board.empty() || board[0].empty()) return false;
		const int m = board.size();
		const int n = board[0].size();
		vector<vector<bool> > visited(m, vector<bool>(n, false));
		for (int i = 0; i < m; ++i)
			for (int j = 0; j < n; ++j)
				if (dfs(board, word, 0, i, j, visited))
					return true;
		return false;
	}
private:
	bool dfs(const vector<vector<char> > &board, const string &word, int index, int x, int y, vector<vector<bool> > &visited) {
		if (index == word.size())
			return true; // 收敛条件
		if (x < 0 || y < 0 || x >= board.size() || y >= board[0].size())
			return false; // 越界，终止条件
		if (visited[x][y]) return false; // 已经访问过，剪枝
		if (board[x][y] != word[index]) return false; // 不相等，剪枝
		visited[x][y] = true;
		bool ret = dfs(board, word, index + 1, x - 1, y, visited) || // 上
			dfs(board, word, index + 1, x + 1, y, visited) || // 下
			dfs(board, word, index + 1, x, y - 1, visited) || // 左
			dfs(board, word, index + 1, x, y + 1, visited); // 右
		visited[x][y] = false;
		return ret;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Word_Search", "[Depth-First Search]"){
	Solution sln;
	vector<vector<char> > board;
	SECTION("Empty Input") {
		REQUIRE(sln.exist(board,"") == true);
		REQUIRE(sln.exist(board,"A") == false);
	}
	SECTION("Normal Input") {
		char r1[5] = "ABCE";
		char r2[5] = "SFCS";
		char r3[5] = "ADEE";
		board.push_back(vector<char>(r1,r1+4));
		board.push_back(vector<char>(r2,r2+4));
		board.push_back(vector<char>(r3,r3+4));
		REQUIRE(sln.exist(board,"ABCCED") == true);
		REQUIRE(sln.exist(board,"SEE") == true);
		REQUIRE(sln.exist(board,"ABCB") == false);
	}
}