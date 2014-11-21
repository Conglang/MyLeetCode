//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 递归法，会超时，有助于理解题意。
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (*p == '*')
		{
			while (*p == '*') {++p;}    // skip continuous *
			if (*p == '\0') {return true;}
			while (*s != '\0' && !isMatch(s, p)) {++s;}

			return *s != '\0';	// 对这里还有点不明白。
		}
		else if (*p == '\0' || *s == '\0') {return *p == *s;}
		else if (*p == '?' || *p == *s) {return isMatch(++s, ++p);}
		else {return false;}
	}
};

// 迭代法，空间复杂度O(1)，时间复杂度O(m*n)
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
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