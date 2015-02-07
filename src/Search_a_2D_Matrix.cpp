//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/8
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
For example,

Consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
//--------------------------------------------------------------------------------------------------------------*/
// My Way
// 先比较每行头，再在该行找。较繁琐，易出错。
class Solution {
public:
	bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if (matrix.empty()) return false;
		int m = matrix[0].size();
		int n = matrix.size();
		if (target < matrix[0][0] || target > matrix[n-1][m-1]) return false;

		vector<int> rows;
		for (int i = 0; i < n; ++i)
		{
			rows.push_back(matrix[i][0]);
		}
		int row = find_insert_pos(rows, 0, n, target);
		if (row < n && target == matrix[row][0]) return true;
		--row;

		int num = find_insert_pos(matrix[row], 0, m, target);
		if (target == matrix[row][num]) return true;
		return false;
	}
private:
	int find_insert_pos(vector<int> num, int start, int end, int target)
	{
		while (start != end)
		{
			int mid = start + (end - start) / 2;
			if (target > num[mid]) start = ++mid;
			else end = mid;
		}
		return start;
	}
};

// Learned Way
// 直接看成一个大数组来二分。
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