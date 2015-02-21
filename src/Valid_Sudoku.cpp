//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/2
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
* 
* The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
* 
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
* A partially filled sudoku which is valid.
* 
* Note:
* A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 时间复杂度O(n^2)，空间复杂度O(1)
// 细节实现，检查行、检查列、检查子格。
class Solution {
public:
	bool check_valid_9(vector<char> nums)
	{
		std::set<char> pre;
		for (int i = 0; i < nums.size(); ++i)
		{
			if (nums[i] != '.' && pre.find(nums[i]) != pre.end())
			{
				return false;
			}
			pre.insert(nums[i]);
		}
		return true;
	}

	bool isValidSudoku(vector<vector<char> > &board) {
		for (int i = 0; i < board.size(); ++i)	// row
		{
			if (!check_valid_9(board[i])) {return false;}
		}
		for (int i = 0; i < board.size(); ++i)	// colume
		{
			vector<char> colume;
			for (int j = 0; j < board.size(); ++j)
			{
				colume.push_back(board[j][i]);
			}
			if (!check_valid_9(colume)) {return false;}
		}
		for (int i = 0; i < board.size(); i += board.size()/3)	// box
		{
			for (int j = 0; j < board.size(); j += board.size()/3)
			{
				vector<char> box;
				for (int m = 0; m < board.size()/3; ++m)
				{
					for (int n = 0; n < board.size()/3; ++n)
					{
						box.push_back(board[i+m][j+n]);
					}
				}
				if (!check_valid_9(box)) {return false;}
			}
		}
		return true;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Valid_Sudoku", "[Arrays]"){
	Solution s;
	vector<char> temp(9, '.');
	vector<vector<char> > board(9, temp);
	SECTION("Error Input"){
		board[0][0] = '1';
		board[1][1] = '1';
		REQUIRE(s.isValidSudoku(board) == false);
	}
	SECTION("Valid Input"){
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
		REQUIRE(s.isValidSudoku(board) == true);
	}
}