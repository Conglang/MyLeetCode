//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/29
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner
* (row1, col1) and lower right corner (row2, col2).
* 
* 3	0	1	4	2
* 5	6	3	2	1
* 1	[2	0	1]	5
* 4	[1	0	1]	7
* 1	[0	3	0]	5
* 
* The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3),
* which contains sum = 8.
* 
* Example:
* Given matrix = [
* [3, 0, 1, 4, 2],
* [5, 6, 3, 2, 1],
* [1, 2, 0, 1, 5],
* [4, 1, 0, 1, 7],
* [1, 0, 3, 0, 5]
* ]
* 
* sumRegion(2, 1, 4, 3) -> 8
* sumRegion(1, 1, 2, 2) -> 11
* sumRegion(1, 2, 2, 4) -> 12
* Note:
* You may assume that the matrix does not change.
* There are many calls to sumRegion function.
* You may assume that row1 ¡Ü row2 and col1 ¡Ü col2.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class NumMatrix {
public:
	NumMatrix(vector<vector<int>> &matrix) {
		if (matrix.empty()) return;
		int m(matrix.size()), n(matrix[0].size());
		sums.assign(m, vector<int>(n, 0));
		for (int i = 0; i < m; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				int top = i ? sums[i-1][j] : 0;
				int left = j ? sums[i][j-1] : 0;
				int diag = i && j ? sums[i-1][j-1] : 0;
				sums[i][j] = top + left - diag + matrix[i][j];
			}
		}
	}

	int sumRegion(int row1, int col1, int row2, int col2) {
		if (sums.empty()) return 0;
		int top = row1 > 0 ? sums[row1-1][col2] : 0;
		int left = col1 > 0 ? sums[row2][col1-1] : 0;
		int diag = row1 > 0 && col1 > 0 ? sums[row1-1][col1-1] : 0;
		return sums[row2][col2] - top - left + diag;
	}
private:
	vector<vector<int>> sums;
};

// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Range_Sum_Query_2D_Immutable", "[Dynamic_Programming]"){
	SECTION("Normal Input"){
		int l1[5] = {3, 0, 1, 4, 2};
		int l2[5] = {5, 6, 3, 2, 1};
		int l3[5] = {1, 2, 0, 1, 5};
		int l4[5] = {4, 1, 0, 1, 7};
		int l5[5] = {1, 0, 3, 0, 5};
		vector<vector<int>> mat;
		mat.push_back(vector<int>(l1,l1+5));
		mat.push_back(vector<int>(l2,l2+5));
		mat.push_back(vector<int>(l3,l3+5));
		mat.push_back(vector<int>(l4,l4+5));
		mat.push_back(vector<int>(l5,l5+5));
		NumMatrix numMatrix(mat);
		REQUIRE(numMatrix.sumRegion(2, 1, 4, 3) == 8);
		REQUIRE(numMatrix.sumRegion(1, 1, 2, 2) == 11);
		REQUIRE(numMatrix.sumRegion(1, 2, 2, 4) == 12);
	}
}