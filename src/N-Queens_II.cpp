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
// ֻҪ�����������������㷨������һ���и��򵥵Ľⷨ��
// ����+��֦��ʱ�临�Ӷ�O(n!)���ռ临�Ӷ�O(n)��
class Solution {
public:
	int totalNQueens(int n) {
		if (n == 0) return 0;
		if (n == 1) return 1;
		// ��ʼ��֦������
		columns.assign(n,-1);	// n��columns��ÿ����δռ�ݣ�Ϊ-1��
		main_diag.assign(n*2-1,-1);	// 2n-1�����Խ��ߣ�ÿ����δռ�ݣ�Ϊ-1��
		anti_diag.assign(n*2-1,-1);	// 2n-1�����Խ��ߣ�ÿ����δռ�ݣ�Ϊ-1��

		int count(0);
		vector<string> oneway;	// һ�ֿ��ܵķ�����
		dfs(count, oneway, n, 0);	// ������⡣
		return count;
	}
private:
	// �������������ڼ�֦��
	vector<int> columns;	// ��ʾ�Ѿ����õĻʺ�ռ������Щ�С�
	vector<int> main_diag;	// ռ������Щ���Խ��ߡ�
	vector<int> anti_diag;	// ռ������Щ���Խ��ߡ�

	// ���ѡ�
	void dfs(int& count, vector<string>& oneway, int n, int r)
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
				// ����ѵ���ĩ�У�������1��
				if (r == n-1)
				{
					++count;
				}else	// �����������һ�����ѡ�
				{
					dfs(count,oneway,n,r+1);
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