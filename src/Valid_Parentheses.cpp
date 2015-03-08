//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* 
* The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(n)。
class Solution {
public:
	bool isValid(string s) {
		if (s.empty()) {return true;}
		string left = "([{";
		string right = ")]}";
		stack<char> stk;
#if __cplusplus < 201103L
		for (auto it = s.begin(); it != s.end(); ++it)
		{
			char c = *it;
#else
		for (auto c : s)
		{
#endif
			if (left.find(c) != string::npos)
			{
				stk.push(c);
			}else
			{
				if (stk.empty() || stk.top() != left[right.find(c)])
				{return false;}
				else {stk.pop();}
			}
		}
		return stk.empty();
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Valid_Parentheses", "[Stacks]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.isValid("") == true);
	}
	SECTION("Normal Input"){
		REQUIRE(sln.isValid("([{}])()[]{}") == true);
		REQUIRE(sln.isValid("((()()[}]})") == false);
		REQUIRE(sln.isValid("(()))))") == false);
	}
}