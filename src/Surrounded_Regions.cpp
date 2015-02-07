//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/13
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
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

	void mark_free(vector<vector<char>> &board, int ii, int ij)
	{
		// first find all O on the edge of the grid.
		stack<pair<int, int>> items;
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
