//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Implement regular expression matching with support for '.' and '*'.
* 
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* 
* The matching should cover the entire input string (not partial).
* 
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* 
* Some examples:
* isMatch("aa","a") → false
* isMatch("aa","aa") → true
* isMatch("aaa","aa") → false
* isMatch("aa", "a*") → true
* isMatch("aa", ".*") → true
* isMatch("ab", ".*") → true
* isMatch("aab", "c*a*b") → true
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 用递归的方法。
class Solution {
public:
    bool isMatch(string s, string p) {
        if (p.empty())
            return s.empty();
        bool current_match = (!s.empty() && (s[0] == p[0] || p[0] == '.'));
		// x*结构。
        // 当前字符匹配上且后续与x*能匹配上，或没当前x*什么事
        if (p.size() >= 2 && p[1] == '*') {
            return (current_match && isMatch(s.substr(1), p)) ||
                isMatch(s, p.substr(2));
        }
		// 没有*的事就走之后流程
        return current_match && isMatch(s.substr(1), p.substr(1));
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Regular_Expression_Matching", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.isMatch("","") == true);
		REQUIRE(s.isMatch("a","") == false);
	}
	SECTION("Normal Input"){
		REQUIRE(s.isMatch("aa","a") == false);
		REQUIRE(s.isMatch("aa","aa") == true);
		REQUIRE(s.isMatch("aaa","aa") == false);
		REQUIRE(s.isMatch("aa","a*") == true);
		REQUIRE(s.isMatch("aa",".*") == true);
		REQUIRE(s.isMatch("ab",".*") == true);
		REQUIRE(s.isMatch("aab","c*a*b") == true);
		REQUIRE(s.isMatch("kkkkb","k*kabc") == false);
		REQUIRE(s.isMatch("kkkkabc","k*kabc") == true);
	}
}