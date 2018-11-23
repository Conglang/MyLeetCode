//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2017/02/12
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order
as shown in the below image.

Example:
Input:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
Output:  [1,2,4,7,5,3,6,8,9]
Explanation:

Note:
The total number of elements of the given matrix will not exceed 10,000.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 先化简为从左下角依次往右上角遍历的问题，然后在遍历的过程中通过一个flag反向。
class Solution {
public:
	vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		// special cases
		if (matrix.empty() || matrix[0].empty())
			return result;
		// for all number at left and bottom borderline
		// go up and right
		// keep a direction flag to reverse
		int m(matrix.size()), n(matrix[0].size());
		int i(0), j(0);
		bool rev(false);
		while (i < m && j < n)
		{
			int a(i), b(j);
			vector<int> part;
			while (a > -1 && b < n)
			{
				part.push_back(matrix[a][b]);
				--a; ++b;
			}
			if (rev)
				reverse(part.begin(), part.end());
			copy(part.begin(), part.end(), back_inserter(result));
			j = i == m-1 ? j+1 : j;
			i = i == m-1 ? i : i+1;
			rev = !rev;
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Diagnal_Traverse", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int l1[3] = {1,2,3};
		int l2[3] = {4,5,6};
		int l3[3] = {7,8,9};
		vector<vector<int>> input;
		input.push_back(vector<int>(l1,l1+3));
		input.push_back(vector<int>(l2,l2+3));
		input.push_back(vector<int>(l3,l3+3));
		int result[9] = {1,2,4,7,5,3,6,8,9};
		REQUIRE(s.findDiagonalOrder(input) == vector<int>(result, result+9));
	}
}