//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/8
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
* 
* Integers in each row are sorted from left to right.
* The first integer of each row is greater than the last integer of the previous row.
* For example,
* 
* Consider the following matrix:
* 
* [
*   [1,   3,  5,  7],
*   [10, 11, 16, 20],
*   [23, 30, 34, 50]
* ]
* Given target = 3, return true.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"

// 直接看成一个大数组来二分。
// 时间复杂度O(logn)，空间复杂度O(1)
class Solution {
public:
	bool searchMatrix(const vector<vector<int>>& matrix, int target) {
		if (matrix.empty()) return false;
		const size_t m = matrix.size();
		const size_t n = matrix.front().size();
		int first = 0;
		int last = m * n;
		while (first < last) {
			int mid = first + (last - first) / 2;
			int value = matrix[mid / n][mid % n];
			if (value == target)
				return true;
			else if (value < target)
				first = mid + 1;
			else
				last = mid;
		}
		return false;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Search_a_2D_Matrix", "[Searching]"){
	Solution sln;
	vector<vector<int> > matrix;
	SECTION("Empty Input"){
		REQUIRE(sln.searchMatrix(matrix,10) == false);
	}
	SECTION("Normal Input"){
		int r1[4] = {1,3,5,7};
		int r2[4] = {10,11,16,20};
		int r3[4] = {23,30,34,50};
		vector<int> row1(r1,r1+4);
		vector<int> row2(r2,r2+4);
		vector<int> row3(r3,r3+4);
		matrix.push_back(row1);
		matrix.push_back(row2);
		matrix.push_back(row3);
		REQUIRE(sln.searchMatrix(matrix,10) == true);
		REQUIRE(sln.searchMatrix(matrix,1) == true);
		REQUIRE(sln.searchMatrix(matrix,50) == true);
		REQUIRE(sln.searchMatrix(matrix,16) == true);
		REQUIRE(sln.searchMatrix(matrix,0) == false);
		REQUIRE(sln.searchMatrix(matrix,15) == false);
		REQUIRE(sln.searchMatrix(matrix,51) == false);
	}
}
