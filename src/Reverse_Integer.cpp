//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Reverse digits of an integer.
* 
* Example1: x = 123, return 321
* Example2: x = -123, return -321
* 
* click to show spoilers.
* 
* Have you thought about this?
* Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
* 
* If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
* 
* Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
* 
* Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(logn)，空间复杂度O(1)。
class Solution {
public:
	int reverse (int x) {
		int r = 0;
		for (; x; x /= 10)
			r = r * 10 + x % 10;
		return r;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Reverse_Integer", "[Detail]"){
	Solution sln;
	SECTION("Normal Input"){
		REQUIRE(sln.reverse(0) == 0);
		REQUIRE(sln.reverse(-0) == 0);
		REQUIRE(sln.reverse(10) == 1);
		REQUIRE(sln.reverse(123) == 321);
		REQUIRE(sln.reverse(-123) == -321);
	}
}