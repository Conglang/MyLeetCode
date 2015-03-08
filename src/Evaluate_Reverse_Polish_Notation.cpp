//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Evaluate the value of an arithmetic expression in Reverse Polish Notation.
* http://en.wikipedia.org/wiki/Reverse_Polish_notation
* 
* Valid operators are +, -, *, /. Each operand may be an integer or another expression.
* 
* Some examples:
* ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
* ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(logn)。
class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		if (tokens.empty()) return 0;
		stack<string> cal_stack;	// 栈中存字符串
#if __cplusplus < 201103L
		for (auto it = tokens.begin(); it != tokens.end(); ++it)
		{
			string token = *it;
#else
		for (auto token : tokens)
		{
#endif
			if (!is_operator(token))
			{
				cal_stack.push(token);
			}else
			{
				int y = stoi(cal_stack.top());	// stoi
				cal_stack.pop();
				int x = stoi(cal_stack.top());
				cal_stack.pop();
				if (token[0] == '+') { x += y;}	// 用自增操作，少一个变量
				else if (token[0] == '-') { x -= y;}
				else if (token[0] == '*') { x *= y;}
				else if (token[0] == '/') { x /= y;}
				cal_stack.push(to_string((long double)x));	// to_string
			}
		}
		return stoi(cal_stack.top());
	}
private:
	bool is_operator(const string& op)
	{
		return op.size() == 1 && string("+-*/").find(op) != string::npos;	// 这种写法很好，判断某string在不在若干选择之中
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Evaluate_Reverse_Polish_Notation", "[Stacks]"){
	Solution sln;
	vector<string> tokens;
	SECTION("Empty Input"){
		REQUIRE(sln.evalRPN(tokens) == 0);
	}
	SECTION("Normal Input1"){
		string temp[5] = {"2", "1", "+", "3", "*"};
		tokens.assign(temp, temp+5);
		REQUIRE(sln.evalRPN(tokens) == 9);
	}
	SECTION("Normal Input2"){
		string temp[5] = {"4", "13", "5", "/", "+"};
		tokens.assign(temp, temp+5);
		REQUIRE(sln.evalRPN(tokens) == 6);
	}
}