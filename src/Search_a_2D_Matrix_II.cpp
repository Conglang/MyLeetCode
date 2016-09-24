//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/24
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
* 
* Integers in each row are sorted in ascending from left to right.
* Integers in each column are sorted in ascending from top to bottom.
* For example,
* 
* Consider the following matrix:
* 
* [
*   [1,   4,  7, 11, 15],
*   [2,   5,  8, 12, 19],
*   [3,   6,  9, 16, 22],
*   [10, 13, 14, 17, 24],
*   [18, 21, 23, 26, 30]
* ]
* Given target = 5, return true.
* 
* Given target = 20, return false.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        int i(row-1), j(0);
        while(i >= 0 && j <= col-1)
        {
            if(target > matrix[i][j])
            {
                j++;
            }
            else if(target < matrix[i][j])
            {
                i--;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Search_a_2D_Matrix_II", "[Devide and Conquer]") {
	Solution s;
	SECTION("Normal Input") {
		int r1[5] = {1,4,7,11,15};
		int r2[5] = {2,5,8,12,19};
		int r3[5] = {3,6,9,16,22};
		int r4[5] = {10,13,14,17,24};
		int r5[5] = {18,21,23,26,30};
		vector<vector<int>> matrix;
		matrix.push_back(vector<int>(r1,r1+5));
		matrix.push_back(vector<int>(r2,r2+5));
		matrix.push_back(vector<int>(r3,r3+5));
		matrix.push_back(vector<int>(r4,r4+5));
		matrix.push_back(vector<int>(r5,r5+5));
		REQUIRE(s.searchMatrix(matrix, 1) == true);
		REQUIRE(s.searchMatrix(matrix, 8) == true);
		REQUIRE(s.searchMatrix(matrix, 14) == true);
		REQUIRE(s.searchMatrix(matrix, 26) == true);
		REQUIRE(s.searchMatrix(matrix, 30) == true);
		REQUIRE(s.searchMatrix(matrix, 18) == true);
		REQUIRE(s.searchMatrix(matrix, 150) == false);
		REQUIRE(s.searchMatrix(matrix, 25) == false);
		REQUIRE(s.searchMatrix(matrix, 20) == false);
		REQUIRE(s.searchMatrix(matrix, 27) == false);
		REQUIRE(s.searchMatrix(matrix, 0) == false);
	}
}