//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string containing just the characters '(' and ')',
* find the length of the longest valid (well-formed) parentheses substring.
* 
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
* 
* Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 关键是注意到失败方式有两种，一种是(多，一种是)多。
#define W3

#ifdef W1
// 用栈，时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() < 2) {return 0;}
		int max_len(0), last(-1);	// last是上一次)出现的位置
		stack<int> lefts;	// 记录(位置的栈
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				lefts.push(i);
			}else
			{
				if (lefts.empty())	// 是多余的)破坏了连贯性
				{
					last = i;	// 记下此点，以后用它做开头
				}else
				{
					lefts.pop();
					if (lefts.empty())	// 如果没有多余的(，就不怪(，从当前位置到开头的距离
					{
						max_len = max(max_len, i - last);
					}else	// 有多余的(，那就怪它，从当前位置到栈顶最近的那个(的距离
					{
						max_len = max(max_len, i - lefts.top());
					}
				}
			}
		}
		return max_len;
	}
};
#endif

#ifdef W2
// 两遍扫描，时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() < 2) {return 0;}
		int answer = 0, depth = 0, start = -1;
		// from left to right, on condition ) is more than (
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				++depth;
			}else
			{
				--depth;
				if (depth < 0)
				{
					start = i;
					depth = 0;
				}else if (depth == 0)
				{
					answer = max(answer, i - start);
				}
			}
		}
		// from right to left, on condition ( is more than )
		depth = 0;
		start = s.size();
		for (int i = s.size() - 1; i > -1; --i)
		{
			if (s[i] == ')')
			{
				++depth;
			}else
			{
				--depth;
				if (depth < 0)
				{
					start = i;
					depth = 0;
				}else if (depth == 0)
				{
					answer = max(answer, start - i);
				}
			}
		}
		return answer;
	}
};
#endif

#ifdef W3
// 沿用Valid_Parentheses的方法，只不过遇到错误时不是直接返回，而是将计数清零。
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.empty())
			return 0;
		string left = "([{";
		string right = ")]}";
		stack<char> stk;
		int max_len(0);
		int cur_len(0);
		for (auto it = s.begin(); it != s.end(); ++it)
		{
			char c = *it;
			if (left.find(c) != string::npos)
			{
				stk.push(c);
			}else
			{
				if (stk.empty() || left[right.find(c)] != stk.top())
				{
					cur_len = 0;
				}else
				{
					stk.pop();
					cur_len += 2;
				}
			}
			max_len = max(max_len, cur_len);
		}
		return max_len;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Longest_Valid_Parentheses", "[Stacks]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.longestValidParentheses("") == 0);
	}
	SECTION("Normal Input"){
		REQUIRE(sln.longestValidParentheses("(()") == 2);
		REQUIRE(sln.longestValidParentheses(")()())") == 4);
		REQUIRE(sln.longestValidParentheses("(()))))") == 4);
	}
}