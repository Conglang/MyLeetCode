//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given numRows, generate the first numRows of Pascal's triangle.
* 
* For example, given numRows = 5,
* Return
* 
* [
* [1],
* [1,1],
* [1,2,1],
* [1,3,3,1],
* [1,4,6,4,1]
* ]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1

#ifdef W1
// 从左到右
// 下一行第一个元素和最后一个元素赋值为1，中间的每个元素，等于上一行的左上角和右上角元素之和。
// 时间复杂度O(n^2)，空间复杂度O(n)。
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result;
		if (numRows == 0) return result;
		result.push_back(vector<int>(1,1));	// 第一行
		for (int i = 2; i <= numRows; ++i)
		{
			vector<int> current(i,1);	// 本行
			const vector<int>& prev = result[i-2];	// 上一行
			for (int j = 1; j < i-1; ++j)
			{
				current[j] = prev[j-1] + prev[j];	// 左上角和右上角之和
			}
			result.push_back(current);
		}
		return result;
	}
};
#endif

#ifdef W2
// 从右到左
// 时间复杂度O(n^2)，空间复杂度O(n)。
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result;
		if (numRows == 0) return result;
		vector<int> array;
		for (int i = 1; i <= numRows; ++i)
		{
			for (int j = i-2; j > 0; --j)
			{
				// 从右向左，覆盖处理数组。不修改第0位的1，不包括新增的最后一位的。
				array[j] = array[j-1] + array[j];
			}
			array.push_back(1);	// 新增最后一位1。
			result.push_back(array);
		}
		return result;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Pascal's Triangle", "[Detail]"){
	Solution sln;
	vector<vector<int> > result;
	SECTION("Empty Input"){
		REQUIRE(sln.generate(0) == result);
	}
	SECTION("Normal Input"){
		vector<int> r1(1,1);
		vector<int> r2(2,1);
		int t3[3] = {1,2,1};
		vector<int> r3(t3, t3+3);
		int t4[4] = {1,3,3,1};
		vector<int> r4(t4, t4+4);
		int t5[5] = {1,4,6,4,1};
		vector<int> r5(t5, t5+5);
		result.push_back(r1);
		result.push_back(r2);
		result.push_back(r3);
		result.push_back(r4);
		result.push_back(r5);
		REQUIRE(sln.generate(5) == result);
	}
}