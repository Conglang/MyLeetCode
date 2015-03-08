//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/13
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.
* 
* A region is captured by flipping all 'O's into 'X's in that surrounded region.
* 
* For example,
* X X X X
* X O O X
* X X O X
* X O X X
* After running your function, the board should be:
* 
* X X X X
* X X X X
* X X X X
* X O X X
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 广度优先搜索。时间复杂度O(n)，空间复杂度O(n)。
/*
1. Find all O on the edge of the grid
2. For each of the above, do BFS traversal (note, recursion will give for large tests) replacing 'O' with 'o' - marking free 'O' cells
3. Go over the whole grid and replace O=>X and o=>O
*/
class Solution {
	int m_rows;
	int m_cols;

public:
	void solve(vector<vector<char> > &board) {
		if (board.size() < 3 || board[0].size() < 3) return;

		m_rows = board.size();
		m_cols = board[0].size();

		// find all O not surrounded, and replace them with o.
		for (int i = 0; i <m_rows; ++i)
		{
			mark_free(board, i, 0);
			mark_free(board, i, m_cols-1);
		}
		for (int j = 1; j < m_cols-1; ++j)
		{
			mark_free(board, 0, j);
			mark_free(board, m_rows-1, j);
		}

		// go over the whole grid and replace O->X and o->O.
		for (int i = 0; i < m_rows; ++i)
		{
			for (int j = 0; j < m_cols; ++j)
			{
				if (board[i][j] == 'O') board[i][j] = 'X';
				else if (board[i][j] == 'o') board[i][j] = 'O';
			}
		}
	}

	void mark_free(vector<vector<char> > &board, int ii, int ij)
	{
		// first find all O on the edge of the grid.
		stack<pair<int, int> > items;
		items.push(make_pair(ii,ij));
		while (!items.empty())
		{
			pair<int, int> p = items.top();
			items.pop();
			int i = p.first;
			int j = p.second;

			if (board[i][j] == 'X' || board[i][j] == 'o') continue;

			// for each of the O not surrounded, do BFS traversal replacing O with o - marking free O cells.
			if (board[i][j] == 'O') {board[i][j] = 'o';}

			if (i < m_rows-1) items.push(make_pair(i+1, j));
			if (j < m_cols-1) items.push(make_pair(i, j+1));
			if (i > 0) items.push(make_pair(i-1, j));
			if (j > 0) items.push(make_pair(i, j-1));
		}
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Surrounded_Regions", "[Breadth-First Search]"){
	Solution sln;
	vector<vector<char> > board;
	vector<vector<char> > result;
	SECTION("Empty Input") {
		sln.solve(board);
		REQUIRE(board == result);
	}
	SECTION("Normal Input1") {
		int r1[4] = {'O','X','O','O'};
		int r2[4] = {'O','O','X','X'};
		board.push_back(vector<char>(r1,r1+4));
		board.push_back(vector<char>(r2,r2+4));
		result = board;
		sln.solve(board);
		REQUIRE(board == result);
	}
	SECTION("Normal Input2") {
		board.push_back(vector<char>(4,'X'));
		board.push_back(vector<char>(4,'X'));
		board.push_back(vector<char>(4,'X'));
		board.push_back(vector<char>(4,'X'));
		board[3][1] = 'O';
		result = board;
		board[1][1] = 'O';
		board[1][2] = 'O';
		board[2][2] = 'O';
		sln.solve(board);
		REQUIRE(board == result);
	}
}
