//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a non-empty 2D matrix matrix and an integer k, 
* find the max sum of a rectangle in the matrix such that its sum is no larger than k.
* 
* Example:
* Given matrix = [
* [1,  0, 1],
* [0, -2, 3]
* ]
* k = 2
* The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and
* 2 is the max number no larger than k (k = 2).
* 
* Note:
* The rectangle inside the matrix must have an area > 0.
* What if the number of rows is much larger than the number of columns?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/48875/accepted-c-codes-with-explanation-and-references
// 对列两端各指定l和r边界，在这个范围内，求出每个row的sum(动态规划)，然后看符合条件的最大两个sum间的差值是多少。
class Solution {
public:
	int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		if (matrix.empty()) return 0;
		int row(matrix.size()), col(matrix[0].size()), res(INT_MIN);
		for (int l = 0; l < col; ++l)
		{
			vector<int> sums(row, 0);
			for (int r = l; r < col; ++r)
			{
				for (int i = 0; i < row; ++i)
				{
					sums[i] += matrix[i][r];
				}
				// Find the max subarray no more than K
				set<int> accuSet;
				accuSet.insert(0);
				int curSum(0), curMax(INT_MIN);
				for (auto s = sums.begin(); s != sums.end(); ++s)
				{
					int sum(*s);
					curSum += sum;
					set<int>::iterator it = accuSet.lower_bound(curSum - k);
					if (it != accuSet.end()) curMax = std::max(curMax, curSum - *it);
					accuSet.insert(curSum);
				}
				res = std::max(res, curMax);
			}
		}
		return res;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Max_Sum_of_Rectangle_No_Larger_Than_K", "[Binary_Search]"){
	Solution s;
	SECTION("Normal Input"){
		vector<vector<int>> matrix;
		int r1[3] = {1,0,1};
		int r2[3] = {0,-2,3};
		matrix.push_back(vector<int>(r1,r1+3));
		matrix.push_back(vector<int>(r2,r2+3));
		REQUIRE(s.maxSumSubmatrix(matrix, 2) == 2);
	}
}