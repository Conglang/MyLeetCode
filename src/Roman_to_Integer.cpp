//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a roman numeral, convert it to an integer.
* 
* Input is guaranteed to be within the range from 1 to 3999.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"

class Solution {
public:
	inline int map(const char c) {
		switch (c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		default: return 0;
		}
	}
	int romanToInt(string s) {
		int result = 0;
		for (size_t i = 0; i < s.size(); ++i) {
			if (i > 0 && map(s[i]) > map(s[i - 1])) {
				result += (map(s[i]) - 2 * map(s[i - 1]));
			} else {
				result += map(s[i]);
			}
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Roman_to_Integer", "[Strings]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.romanToInt("") == 0);
		REQUIRE(s.romanToInt("I") == 1);
		REQUIRE(s.romanToInt("X") == 10);
		REQUIRE(s.romanToInt("C") == 100);
		REQUIRE(s.romanToInt("M") == 1000);
		REQUIRE(s.romanToInt("V") == 5);
		REQUIRE(s.romanToInt("L") == 50);
		REQUIRE(s.romanToInt("D") == 500);
		REQUIRE(s.romanToInt("III") == 3);
		REQUIRE(s.romanToInt("IV") == 4);
		REQUIRE(s.romanToInt("VI") == 6);
		REQUIRE(s.romanToInt("XIX") == 19);
		REQUIRE(s.romanToInt("XX") == 20);
		REQUIRE(s.romanToInt("XLV") == 45);
		REQUIRE(s.romanToInt("MCMLXXX") == 1980);
	}
}