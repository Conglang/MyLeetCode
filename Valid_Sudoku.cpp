//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/2
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled with the character '.'.


A partially filled sudoku which is valid.

Note:
A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
//--------------------------------------------------------------------------------------------------------------*/
// My way
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