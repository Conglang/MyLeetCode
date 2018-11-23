//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* A message containing letters from A-Z is being encoded to numbers using the following mapping:
* 
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
* Given an encoded message containing digits, determine the total number of ways to decode it.
* 
* For example,
* Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
* 
* The number of ways decoding "12" is 2.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 动态规划，时间复杂度O(n)，空间复杂度O(1)。
// 类似上楼梯(Climbing Stairs)。两种可能情况，情况1是与前一个拼合，情况2是自己独自解析。
// 可能的情境数就是两者之和。
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;
		int prev(0),cur(1);
		for (size_t i = 1; i <= s.length(); ++i)
		{
			// 这个情况不能独自解析，情况2不通。
			if (s[i-1] == '0') {cur = 0;}
			// 这些情况不能与前一个拼合，情况1不通。
			if (i < 2 || !(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')))
			{
				prev = 0;
			}
			swap(prev, cur);
			cur += prev;	// 与上楼梯类似，当前=情况1+情况2
		}
		return cur;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Decode_Ways", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.numDecodings("") == 0);
		REQUIRE(sln.numDecodings("0") == 0);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.numDecodings("12") == 2);
		REQUIRE(sln.numDecodings("127") == 2);
		REQUIRE(sln.numDecodings("111") == 3);
	}
}