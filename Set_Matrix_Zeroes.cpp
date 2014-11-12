//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.

click to show follow up.

Follow up:
Did you use extra space?
A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// �ռ临�Ӷ�O(m+n)�ķ����Ǽ�¼bool��m�к�n�����Ƿ���0.
// �ռ临�Ӷ�O(1)�ķ���Ҫ���þ����һ�к͵�һ�С�
// ���ȼ���һ�к͵�һ����û��0����¼
// �����ÿһ�к�ÿһ�У������0�Ļ�����¼����һ�к͵�һ��
// �ٴα��������������һ�л�����0�Ļ������л�����Ϊ0
// �ع˵�����һ�л��еı�ǣ��������0�Ͱѵ�һ�л�����Ϊ0
class Solution {
public:
	void setZeroes(vector<vector<int> > &matrix) {
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