//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
* 
* Note that it is the kth smallest element in the sorted order, not the kth distinct element.
* 
* Example:
* 
* matrix = [
* [ 1,  5,  9],
* [10, 11, 13],
* [12, 13, 15]
* ],
* k = 8,
* 
* return 13.
* Note: 
* You may assume k is always valid, 1 ≤ k ≤ n^2.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/52865/my-solution-using-binary-search-in-c/18
// Because the loop invariant is left<=Solution<=right. The moment it quits the loop, we also know another condition is true: left>=right.
// left<=Solution<=right and left>=right means left==Solution==right.
// 求一个全局中间值，找到其在每行中比几个大，数量和与 k 比较。大说明这个中间值大了，小说明中间值小了。二分思路移动 l 和 r。
class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n(matrix.size());
		int l(matrix[0][0]), r(matrix[n-1][n-1]);
		while (l < r)
		{
			int mid(l + (r-l)/2);
			int num(0);
			for (int i = 0; i < n; ++i)
			{
				auto pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			if (num < k) {l = mid + 1;}
			else{r = mid;}
		}
		return l;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Kth_Smallest_Element_in_a_Sorted_Matrix", "[Binary_Search]"){
	Solution s;
	SECTION("Normal Input"){
		vector<vector<int>> amatrix;
		int a[3] = {1,5,9};
		int b[3] = {10,11,13};
		int c[3] = {12,13,15};
		amatrix.push_back(vector<int>(a,a+3));
		amatrix.push_back(vector<int>(b,b+3));
		amatrix.push_back(vector<int>(c,c+3));
		REQUIRE(s.kthSmallest(amatrix, 8) == 13);
	}
}