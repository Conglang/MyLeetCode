//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* The n-queens puzzle is the problem of placing n queens on an n��n chessboard such that no two queens attack each other.
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
// ����+��֦��ʱ�临�Ӷ�O(n!)���ռ临�Ӷ�O(n)��
class Solution {
public:
	vector<vector<string> > solveNQueens(int n) {
		vector<vector<string> > result;
		// ���������
		if (n == 0) {return result;}
		if (n == 1) {result.assign(1,vector<string>(1,"Q")); return result;}
		// ��ʼ��֦������
		columns.assign(n,-1);	// n��columns��ÿ����δռ�ݣ�Ϊ-1��
		main_diag.assign(n*2-1,-1);	// 2n-1�����Խ��ߣ�ÿ����δռ�ݣ�Ϊ-1��
		anti_diag.assign(n*2-1,-1);	// 2n-1�����Խ��ߣ�ÿ����δռ�ݣ�Ϊ-1��

		vector<string> oneway;	// һ�ֿ��ܵķ�����
		dfs(result, oneway, n, 0);	// ������⡣
		// �����öԳ��Ի���û�гɹ���
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
	// �������������ڼ�֦��
	vector<int> columns;	// ��ʾ�Ѿ����õĻʺ�ռ������Щ�С�
	vector<int> main_diag;	// ռ������Щ���Խ��ߡ�
	vector<int> anti_diag;	// ռ������Щ���Խ��ߡ�

	// ���ѡ�
	void dfs(vector<vector<string> >& result, vector<string>& oneway, int n, int r)
	{
		int m = /*r==0 ? (n+1)/2 :*/ n;	// �����öԳ��Ի���û�гɹ���
		for (int j = 0; j < m; ++j)
		{
			if (is_valid(oneway, r, j, n))	// �жϵ�ǰ�����Ƿ�Ϸ���
			{
				string str(n,'.');
				str[j] = 'Q';
				oneway.push_back(str);	// ��ǰ�������뱾�С�
				// ��¼��֦�ñ�����
				columns[j] = r;
				main_diag[j-r+n-1] = r;
				anti_diag[j+r] = r;
				// ����ѵ���ĩ�У�����������
				if (r == n-1)
				{
					result.push_back(oneway);
				}else	// �����������һ�����ѡ�
				{
					dfs(result,oneway,n,r+1);
				}
				// �ָ�����״̬��
				oneway.pop_back();
				columns[j] = -1;
				main_diag[j-r+n-1] = -1;
				anti_diag[j+r] = -1;
			}
		}
	}
	// ���ݼ�֦�����жϵ�ǰ�����Ƿ�Ϸ���
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