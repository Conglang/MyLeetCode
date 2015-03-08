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
// 如果后一位不是*的话，正常比较，双双进行到下一个。
// 如果后一位是*，要耗尽s里所有和p*之前字符一样的所有字符，然后再将下一个不一样的和p*之后的字符比较。
// 因为*表示任意个，所以也可以是0个。所以下一个是*的时候，当前p字符与s字符不一样不是否定条件。
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') {return *s == '\0';}

		// next char is not '*', then must match current character
		if (*(p+1) != '*')
		{
			if (*p == *s || (*p == '.' && *s != '\0'))
			{
				return isMatch(s+1, p+1);
			}else {return false;}
		}else // next char is '*'
		{
			while (*p == *s || (*p == '.' && *s != '\0'))
			{
				if (isMatch(s, p+2))	// 去掉当前这个重复s，剩下的s和p中*之后的字符串如果匹配，那就是匹配了。
				{
					return true;
				}
				++s;	// 没匹配上，再去一个重复s。
			}
			return isMatch(s, p+2);	// 重复的都去了，再比较剩下的s和p中*之后的字符串。
		}
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