//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Write a program to solve a Sudoku puzzle by filling the empty cells.
* 
* Empty cells are indicated by the character '.'.
* 
* You may assume that there will be only one unique solution.
* |5 3 .|. 7 .|. . .|
* |6 . .|1 9 5|. . .|
* |. 9 8|. . .|. 6 .|
* |8 . .|. 6 .|. . 3|
* |4 . .|8 . 3|. . 1|
* |7 . .|. 2 .|. . 6|
* |. 6 .|. . .|2 8 .|
* |. . .|4 1 9|. . 5|
* |. . .|. 8 .|. 7 9|
* 
* A sudoku puzzle...
* 
* |5 3 4|6 7 8|9 1 2|
* |6 7 2|1 9 5|3 4 8|
* |1 9 8|3 4 2|5 6 7|
* |8 5 9|7 6 1|4 2 3|
* |4 2 6|8 5 3|7 9 1|
* |7 1 3|9 2 4|8 5 6|
* |9 6 1|5 3 7|2 8 4|
* |2 8 7|4 1 9|6 3 5|
* |3 4 5|2 8 6|1 7 9|
* 
* ...and its solution numbers marked in red.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(9^4)，空间复杂度 O(1)
class Solution {
public:
	bool solveSudoku(vector<vector<char> > &board) {
		for (int i = 0; i < 9; ++i)
		{
			for (int j = 0; j < 9; ++j)
			{
				if (board[i][j] == '.')
				{
					for (int k = 0; k < 9; ++k)
					{
						board[i][j] = '1' + k;
						if (isValid(board, i, j) && solveSudoku(board))
							return true;
						board[i][j] = '.';
					}
					return false;
				}
			}
		}
			return true;
	}
private:
	// 检查(x, y)是否合法
	bool isValid(const vector<vector<char> > &board, int x, int y) {
		int i, j;
		for (i = 0; i < 9; i++) // 检查y列
			if (i != x && board[i][y] == board[x][y])
				return false;
		for (j = 0; j < 9; j++) // 检查x行
			if (j != y && board[x][j] == board[x][y])
				return false;
		for (i = 3 * (x / 3); i < 3 * (x / 3 + 1); i++)
			for (j = 3 * (y / 3); j < 3 * (y / 3 + 1); j++)
				if ((i != x || j != y) && board[i][j] == board[x][y])
					return false;
		return true;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Sudoku_Solver", "[Depth-First Search]"){
	Solution sln;
	vector<char> temp(9, '.');
	vector<vector<char> > board(9, temp);
	vector<vector<char> > result(board);
	SECTION("") {
		board[0][0] = '5';
		board[0][1] = '3';
		board[0][4] = '7';
		board[1][0] = '6';
		board[1][3] = '1';
		board[1][4] = '9';
		board[1][5] = '5';
		board[2][1] = '9';
		board[2][2] = '8';
		board[2][7] = '6';
		board[3][0] = '8';
		board[3][4] = '6';
		board[3][8] = '3';
		board[4][0] = '4';
		board[4][3] = '8';
		board[4][5] = '3';
		board[4][8] = '1';
		board[5][0] = '7';
		board[5][4] = '2';
		board[5][8] = '6';
		board[6][1] = '6';
		board[6][6] = '2';
		board[6][7] = '8';
		board[7][3] = '4';
		board[7][4] = '1';
		board[7][5] = '9';
		board[7][8] = '5';
		board[8][4] = '8';
		board[8][7] = '7';
		board[8][8] = '9';
		sln.solveSudoku(board);
		char r1[9] = {'5','3','4','6','7','8','9','1','2'};
		char r2[9] = {'6','7','2','1','9','5','3','4','8'};
		char r3[9] = {'1','9','8','3','4','2','5','6','7'};
		char r4[9] = {'8','5','9','7','6','1','4','2','3'};
		char r5[9] = {'4','2','6','8','5','3','7','9','1'};
		char r6[9] = {'7','1','3','9','2','4','8','5','6'};
		char r7[9] = {'9','6','1','5','3','7','2','8','4'};
		char r8[9] = {'2','8','7','4','1','9','6','3','5'};
		char r9[9] = {'3','4','5','2','8','6','1','7','9'};
		result.clear();
		result.push_back(vector<char>(r1,r1+9));
		result.push_back(vector<char>(r2,r2+9));
		result.push_back(vector<char>(r3,r3+9));
		result.push_back(vector<char>(r4,r4+9));
		result.push_back(vector<char>(r5,r5+9));
		result.push_back(vector<char>(r6,r6+9));
		result.push_back(vector<char>(r7,r7+9));
		result.push_back(vector<char>(r8,r8+9));
		result.push_back(vector<char>(r9,r9+9));
		REQUIRE(board == result);
	}
}