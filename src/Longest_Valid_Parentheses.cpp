//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
* 
* For "(()", the longest valid parentheses substring is "()", which has length = 2.
* 
* Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// �ؼ���ע�⵽ʧ�ܷ�ʽ�����֣�һ����(�࣬һ����)�ࡣ
#define W2

#ifdef W1
// ��ջ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.size() < 2) {return 0;}
		int max_len(0), last(-1);	// last����һ��)���ֵ�λ��
		stack<int> lefts;	// ��¼(λ�õ�ջ
		for (int i = 0; i < s.size(); ++i)
		{
			if (s[i] == '(')
			{
				lefts.push(i);
			}else
			{
				if (lefts.empty())	// �Ƕ����)�ƻ���������
				{
					last = i;	// ���´˵㣬�Ժ���������ͷ
				}else
				{
					lefts.pop();
					if (lefts.empty())	// ���û�ж����(���Ͳ���(���ӵ�ǰλ�õ���ͷ�ľ���
					{
						max_len = max(max_len, i - last);
					}else	// �ж����(���Ǿ͹������ӵ�ǰλ�õ�ջ��������Ǹ�(�ľ���
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
// ����ɨ�裬ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
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