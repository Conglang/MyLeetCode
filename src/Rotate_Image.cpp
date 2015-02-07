//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 首先沿着副对角线翻转一次，然后沿着水平中线翻转一次。
class Solution {
public:
	void rotate(vector<vector<int> > &matrix) {
		int n = matrix.size();
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n - i; ++j)
			{
				swap(matrix[i][j], matrix[n - 1 - j][n - 1 - i]);
			}
		}
		for (int i = 0; i < n / 2; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				swap(matrix[i][j], matrix[n - 1 - i][j]);
			}
		}
	}
};
