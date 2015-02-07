//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
* 
* click to show follow up.
* 
* Follow up:
* Did you use extra space?
* A straight forward solution using O(mn) space is probably a bad idea.
* A simple improvement uses O(m + n) space, but still not the best solution.
* Could you devise a constant space solution?
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
/*
*	空间复杂度O(m+n)的方法是记录bool，m行和n列中是否有0。
*	
*	空间复杂度O(1)的方法要复用矩阵第一行和第一列。
*	首先检查第一行和第一列有没有0，记录
*	随后检查每一行和每一列，如果有0的话都记录到第一行和第一列
*	再次遍历整个，如果第一行或列有0的话就整行或列置为0
*	回顾当初第一行或列的标记，如果是有0就把第一行或列置为0
 */
// 时间复杂度O(m*n)，空间复杂度O(1)
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
		if (matrix.empty() || matrix[0].empty()) return;
		bool zero_in_row0 = false;
		bool zero_in_col0 = false;
		for (int i = 0; i < matrix[0].size(); ++i)
		{
			if (matrix[0][i] == 0)
			{
				zero_in_row0 = true;
				break;
			}
		}
		for (int j = 0; j < matrix.size(); ++j)
		{
			if (matrix[j][0] == 0)
			{
				zero_in_col0 = true;
				break;
			}
		}
		for (int i = 1; i < matrix.size(); ++i)
		{
			for (int j = 1; j < matrix[0].size(); ++j)
			{
				if (matrix[i][j] == 0)
				{
					matrix[0][j] = 0;
					matrix[i][0] = 0;
				}
			}
		}
		for (int i = 1; i < matrix.size(); ++i)
		{
			for (int j = 1; j < matrix[0].size(); ++j)
			{
				if (matrix[i][0] == 0 || matrix[0][j] == 0)
				{
					matrix[i][j] = 0;
				}
			}
		}
		if (zero_in_row0)
		{
			for (int j = 0; j < matrix[0].size(); ++j)
			{
				matrix[0][j] = 0;
			}
		}
		if (zero_in_col0)
		{
			for (int i = 0; i < matrix.size(); ++i)
			{
				matrix[i][0] = 0;
			}
		}
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Set_Matrix_Zeros", "[Arrays]"){
	Solution s;
	vector<vector<int> > matrix;
	vector<vector<int> > result;
	SECTION("Empty Input"){
		s.setZeroes(matrix);
		REQUIRE(matrix == result);
	}
	SECTION("Normal Input"){
		vector<int> temp(3,1);
		matrix.push_back(temp);
		temp[0] = 0;
		matrix.push_back(temp);
		temp[1] = 0;
		matrix.push_back(temp);
		temp.assign(3,0);
		result.assign(3, temp);
		result[0][2]=1;
		s.setZeroes(matrix);
		REQUIRE(matrix == result);
	}
}