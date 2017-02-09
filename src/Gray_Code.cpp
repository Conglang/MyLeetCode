//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* The gray code is a binary numeral system where two successive values differ in only one bit.
* 
* Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code.
* A gray code sequence must begin with 0.
* 
* For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
* 
* 00 - 0
* 01 - 1
* 11 - 3
* 10 - 2
* Note:
* For a given n, a gray code sequence is not uniquely defined.
* 
* For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
* 
* For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 格雷码
// 不断增加最高位新前缀，与之前的所有已有结果或一遍。
// 内部的或循环注意是逆序的，这样才满足题目中顺序的要求。
// 时间复杂度O(2^n)，空间复杂度O(1)
class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> result;
		result.reserve(1<<n);
		result.push_back(0);
		for (int i = 0; i < n; ++i)
		{
			int highest_bit = 1<<i;
			for (int j = result.size() - 1; j >= 0; --j)
			{
				result.push_back(highest_bit | result[j]);
			}
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Gray_Code", "[Arrays]"){
	Solution s;
	vector<int> result;
	SECTION("Empty Input"){
		result.push_back(0);
		REQUIRE(s.grayCode(0) == result);
	}
	SECTION("Normal Input"){
		int temp[8] = {0,1,3,2,6,7,5,4};
		result.assign(temp, temp+8);
		REQUIRE(s.grayCode(3) == result);
	}
}