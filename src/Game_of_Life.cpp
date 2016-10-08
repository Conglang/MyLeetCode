//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/08
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* According to the Wikipedia's article: "The Game of Life, also known simply as Life,
* is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
* 
* Given a board with m by n cells, each cell has an initial state live (1) or dead (0).
* Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules
* (taken from the above Wikipedia article):
* 
* Any live cell with fewer than two live neighbors dies, as if caused by under-population.
* Any live cell with two or three live neighbors lives on to the next generation.
* Any live cell with more than three live neighbors dies, as if by over-population..
* Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
* Write a function to compute the next state (after one update) of the board given its current state.
* 
* Follow up: 
* Could you solve it in-place? Remember that the board needs to be updated at the same time:
* You cannot update some cells first and then use their updated values to update other cells.
* In this question, we represent the board using a 2D array. In principle, the board is infinite,
* which would cause problems when the active area encroaches the border of the array.
* How would you address these problems?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class Solution {
public:
	void gameOfLife(vector<vector<int>>& board) {
		if (board.empty()) return;
		int m(board.size()), n(board[0].size());
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				unordered_multiset<bool> neighbors;
				neighbors.insert((i==0 || j==0 || board[i-1][j-1]==0 || board[i-1][j-1]==2) ? 0 : 1);
				neighbors.insert((i==0 || board[i-1][j]==0 || board[i-1][j]==2) ? 0: 1);
				neighbors.insert((i==0 || j==n-1 || board[i-1][j+1]==0 || board[i-1][j+1]==2) ? 0 : 1);
				neighbors.insert((j==0 || board[i][j-1]==0 || board[i][j-1]==2) ? 0 : 1);
				neighbors.insert((j==n-1 || board[i][j+1]==0 || board[i][j+1]==2) ? 0 : 1);
				neighbors.insert((i==m-1 || j==0 || board[i+1][j-1]==0 || board[i+1][j-1]==2) ? 0 : 1);
				neighbors.insert((i==m-1 || board[i+1][j]==0 || board[i+1][j]==2) ? 0 : 1);
				neighbors.insert((i==m-1 || j==n-1 || board[i+1][j+1]==0 || board[i+1][j+1]==2) ? 0 : 1);
				if (board[i][j] == 1 && neighbors.count(true) < 2) {board[i][j] = 3;}
				if (board[i][j] == 1 && neighbors.count(true) > 3) {board[i][j] = 3;}
				if (board[i][j] == 0 && neighbors.count(true) == 3) {board[i][j] = 2;}
			}
		}
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (board[i][j] == 2) board[i][j] = 1;
				if (board[i][j] == 3) board[i][j] = 0;
			}
		}
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Game_of_Life", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		vector<vector<int>> board1(3, vector<int>(3,0));
		board1[0][2] = board1[1][0] = board1[1][1] = 1;
		vector<vector<int>> board2(3, vector<int>(3,1));
		
		vector<vector<int>> result2(3, vector<int>(3,0));
		result2[0][1] = result2[1][1] = 1;
		vector<vector<int>> result1(3, vector<int>(3,0));
		result1[0][0] = result1[0][2] = result1[2][0] = result1[2][2] = 1;
		
		s.gameOfLife(board1);
		s.gameOfLife(board2);
		REQUIRE(board1 == result2);
		REQUIRE(board2 == result1);
	}
}