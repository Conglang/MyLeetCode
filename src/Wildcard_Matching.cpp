//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Implement wildcard pattern matching with support for '?' and '*'.
* 
* '?' Matches any single character.
* '*' Matches any sequence of characters (including the empty sequence).
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
* isMatch("aa", "*") → true
* isMatch("aa", "a*") → true
* isMatch("ab", "?*") → true
* isMatch("aab", "c*a*b") → false
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
#define W2

#ifdef W1
// 时间复杂度O(n!*m!)，空间复杂度O(n)
// 递归法，会超时，有助于理解题意。
class Solution {
public:
	bool isMatch2(const char *s, const char *p) {
		if (*p == '*')
		{
			while (*p == '*') {++p;}    // skip continuous *
			if (*p == '\0') {return true;}
			while (*s != '\0' && !isMatch2(s, p)) {++s;}

			return *s != '\0';	// 可知*p在这里不是*也不是\0，要求完全匹配，s也不能是\0。
		}
		else if (*p == '\0' || *s == '\0') {return *p == *s;}
		else if (*p == '?' || *p == *s) {return isMatch2(++s, ++p);}
		else {return false;}
	}
};
#endif

#ifdef W2
// 迭代法，时间复杂度O(m*n)，空间复杂度O(1)
class Solution {
public:
	bool isMatch2(const char *s, const char *p) {
		bool is_star = false;
		const char* str = s;
		const char* ptr = p;
		for (str = s, ptr = p; *str != '\0'; ++str, ++ptr)
		{
			switch (*ptr)
			{
			case '?':
				break;  // pass, next str and ptr
			case '*':
				is_star = true;
				s = str; p = ptr;   // record first unmatch char str in s, and the first char behind * in p
				while (*p == '*') {++p;}    // skip continuous *
				if (*p == '\0') {return true;}  // if * at the end, true
				str = s - 1;
				ptr = p - 1;    // as * appears, s get back to last place
				break;
			default:
				if (*str != *ptr)   // str and ptr are active pointers for compare, s and p are used for record
				{
					if (!is_star) {return false;}   // no * near ahead, false
					++s;            // s is sure to be matched in *, so go forward
					str = s - 1;    // str return to s
					ptr = p - 1;    // ptr goes back to the char behind *
				}
			}
		}
		while (*ptr == '*') {++ptr;}    // str is \0 now
		return (*ptr == '\0');
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Wildcard_Matching", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.isMatch2("","") == true);
		REQUIRE(s.isMatch2("a","") == false);
	}
	SECTION("Normal Input"){
		REQUIRE(s.isMatch2("aa","a") == false);
		REQUIRE(s.isMatch2("aa","aa") == true);
		REQUIRE(s.isMatch2("aaa","aa") == false);
		REQUIRE(s.isMatch2("aa","*") == true);
		REQUIRE(s.isMatch2("aa","a*") == true);
		REQUIRE(s.isMatch2("ab","?*") == true);
		REQUIRE(s.isMatch2("aab","c*a*b") == false);
		REQUIRE(s.isMatch2("kkkkb","k*kab") == false);
		REQUIRE(s.isMatch2("kkkkabc","*c") == true);
	}

}
