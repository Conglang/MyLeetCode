//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a triangle, find the minimum path sum from top to bottom.
* Each step you may move to adjacent numbers on the row below.
* 
* For example, given the following triangle
* [
*      [2],
*     [3,4],
*    [6,5,7],
*   [4,1,8,3]
* ]
* The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).
* 
* Note:
* Bonus point if you are able to do this using only O(n) extra space,
* where n is the total number of rows in the triangle.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ��̬�滮��ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(n)��
/*
*	0
*	0 1
*	0 1 2
*	0 1 2 3
*	�õ����ƹ�ϵf(row,column) = min( f(row-1,column), f(row-1,column-1) ) + T[row][column]��
*	��ʼf(0,0) = T[0][0]��
*	Ϊֻ��row��С����ռ䡣ÿ�μ���ʱ����������㡣
*/
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.empty()) return 0;
		const int n = triangle.size();	// n����������
#if __cplusplus < 201103L
		vector<int> f(n,0);
#else
		int f[n];
		fill_n(f,n,0);	// ���ڶ�̬�滮��������顣
#endif
		f[0] = triangle[0][0];	// ��ʼ����f[0]��
		for (int row = 1; row < n; ++row)	// ����ÿ�У������������μ�����롣
		{
			f[row] = f[row-1] + triangle[row][row];	// ÿ�����Ҷ˵ġ�
			for (int i = row-1; i > 0; --i)	// ÿ���м�ġ�
			{
				f[i] = min(f[i],f[i-1])+triangle[row][i];
			}
			f[0] = f[0] + triangle[row][0];	// ÿ������˵ġ�
		}
		int result(f[n-1]);
		for (int last_row_index = 0; last_row_index < n; ++last_row_index)	// �õ����һ���У���С��ֵ��
		{
			result = min(result, f[last_row_index]);
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Triangle", "[Dynamic Programming]"){
	Solution sln;
	vector<vector<int> > triangle;
	SECTION("Empty Input") {
		REQUIRE(sln.minimumTotal(triangle) == 0);
	}
	SECTION("Normal Input") {
		vector<int> row1(1,2);
		int t2[2] = {3,4};
		vector<int> row2(t2,t2+2);
		int t3[3] = {6,5,7};
		vector<int> row3(t3,t3+3);
		int t4[4] = {4,1,8,3};
		vector<int> row4(t4,t4+4);
		triangle.push_back(row1);
		triangle.push_back(row2);
		triangle.push_back(row3);
		triangle.push_back(row4);
		REQUIRE(sln.minimumTotal(triangle) == 11);
	}
}