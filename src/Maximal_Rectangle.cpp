//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/*
*	��̬�滮���ӵ�һ�п�ʼ���д�������i����j�ϵ��������������㣺
*	[right(i,j) - left(i,j)] * height(i,j)��
*	height���������Ѵ����������������1��������
*	left�ǰ�����ǰ����height�߶ȵ������ε���߽硣
*	right�ǰ�����ǰ����height�߶ȵ������ε��ұ߽硣
*	���ƹ�ϵ���£�
*	left(i,j) = max(left(i-1,j), curleft)
*	right(i,j) = min(right(i-1, j), curright)
*	height(i,j) = height(i-1,j) + 1	���matrix[i][j] == 1
*	height(i,j) = 0	���matrix[i][j] == 0
*	����ÿһ�е���������������Ρ�
*	����ÿһ�У�
*	����һ���������1���ͱ���height�����¼������ҵ�left�������right��
*	����һ�������0��height��0��������֮ǰ�ľ�����Ϣ��գ�����������
*/
// ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)��
class Solution {
public:
	int maximalRectangle(vector<vector<char> > &matrix) {
		if (matrix.empty()) return 0;
		const int m = matrix.size();
		const int n = matrix[0].size();
		vector<int> left(n,0);
		vector<int> right(n,n);
		vector<int> height(n,0);
		int maxrect(0);
		for (int i = 0; i < m; ++i)
		{
			int curleft(0), curright(n);
			// ����height���������⡣
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '1') {++height[j];}
				else {height[j] = 0;}
			}
			// ����left�������ҡ�
			for (int j = 0; j < n; ++j)
			{
				if (matrix[i][j] == '1') { left[j] = max(left[j], curleft);}
				else {left[j] = 0; curleft = j+1;}
			}
			// ����right����������
			for (int j = n-1; j >= 0; --j)
			{
				if (matrix[i][j] == '1') {right[j] = min(right[j], curright);}
				else {right[j] = n; curright = j;}
			}
			// �������������������⡣
			for (int j = 0; j < n; ++j)
			{
				maxrect = max(maxrect, height[j]*(right[j]-left[j]));
			}
		}
		return maxrect;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Maximal_Rectangle", "[Dynamic Programming]"){
	Solution sln;
	vector<vector<char> > matrix;
	SECTION("Empty Input") {
		REQUIRE(sln.maximalRectangle(matrix) == 0);
	}
	SECTION("Normal Input1") {
		vector<char> temp(1,'1');
		matrix.push_back(temp);
		REQUIRE(sln.maximalRectangle(matrix) == 1);
	}
	SECTION("Normal Input2") {
		char t1[5] = {'0','1','0','0','1'};
		char t2[5] = {'0','1','1','1','1'};
		char t3[5] = {'1','1','1','1','0'};
		vector<char> r1(t1,t1+5);
		vector<char> r2(t2,t2+5);
		vector<char> r3(t3,t3+5);
		matrix.push_back(r1);
		matrix.push_back(r2);
		matrix.push_back(r3);
		REQUIRE(sln.maximalRectangle(matrix) == 6);
	}
}