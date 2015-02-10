//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an integer, convert it to a roman numeral.
* 
* Input is guaranteed to be within the range from 1 to 3999.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 一定要注意优化，减法简直不能忍，应该每次就去掉一个数量级才对。
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
	string intToRoman(int num) {
		string result;
		const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

		for (size_t i = 0; num > 0; ++i)
		{
			int count = num / radix[i];
			num %= radix[i];
			for (; count > 0; --count) {result += symbol[i];}
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Integer_to_Roman", "[Strings]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.intToRoman(0) == "");
		REQUIRE(s.intToRoman(1) == "I");
		REQUIRE(s.intToRoman(10) == "X");
		REQUIRE(s.intToRoman(100) == "C");
		REQUIRE(s.intToRoman(1000) == "M");
		REQUIRE(s.intToRoman(5) == "V");
		REQUIRE(s.intToRoman(50) == "L");
		REQUIRE(s.intToRoman(500) == "D");
		REQUIRE(s.intToRoman(3) == "III");
		REQUIRE(s.intToRoman(4) == "IV");
		REQUIRE(s.intToRoman(6) == "VI");
		REQUIRE(s.intToRoman(19) == "XIX");
		REQUIRE(s.intToRoman(20) == "XX");
		REQUIRE(s.intToRoman(45) == "XLV");
		REQUIRE(s.intToRoman(1980) == "MCMLXXX");
	}
}