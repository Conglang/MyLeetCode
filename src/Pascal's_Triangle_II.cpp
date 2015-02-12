//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an index k, return the kth row of the Pascal's triangle.
* 
* For example, given k = 3,
* Return [1,3,3,1].
* 
* Note:
* Could you optimize your algorithm to use only O(k) extra space?
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 时间复杂度O(n^2)，空间复杂度O(n)。
// 从右向左轮换数值。
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result;
		if (rowIndex < 0) return result;
		result.push_back(1);
		for (int i = 0; i < rowIndex; ++i)
		{
			int size = result.size();
			for (int j = size - 1; j > 0; --j)
			{
				result[j] = result[j] + result[j-1];
			}
			result.push_back(1);
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Pascal's Triangle II", "[Detail]"){
	Solution sln;
	vector<int> result;
	SECTION("Empty Input"){
		REQUIRE(sln.getRow(-1) == result);
	}
	SECTION("Normal Input"){
		int t5[5] = {1,4,6,4,1};
		result.assign(t5, t5+5);
		REQUIRE(sln.getRow(4) == result);
	}
}