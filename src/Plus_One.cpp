//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a non-negative number represented as an array of digits, plus one to the number.
* 
* The digits are stored such that the most significant digit is at the head of the list.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)
// 不止1，加多少数都可以的方法。高精度加法。
class Solution {
public:
	vector<int> add_num(vector<int>& digits, int num)
	{
		vector<int> result;
		if (digits.empty() || !num) {return digits;}
		int plus = num;
		for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
		{
			int cur = *it + plus;
			plus = cur / 10;
			result.push_back(cur % 10);
		}
		if (plus) {result.push_back(1);}
		reverse(result.begin(), result.end());
		return result;
	}
	vector<int> plusOne(vector<int> &digits) {
		return add_num(digits, 1);
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Plus_One", "[Arrays]"){
	Solution s;
	vector<int> digits;
	vector<int> result;
	SECTION("Empty Input"){
		REQUIRE(s.plusOne(digits) == result);
	}
	SECTION("Normal Input"){
		digits.assign(3,9);
		result.assign(4,0);
		result[0] = 1;
		REQUIRE(s.plusOne(digits) == result);
		digits.assign(3,1);
		result.assign(3,1);
		result[2] = 2;
		REQUIRE(s.plusOne(digits) == result);
	}
}