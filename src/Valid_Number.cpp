//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Validate if a given string is numeric.
* 
* Some examples:
* "0" => true
* " 0.1 " => true
* "abc" => false
* "1 a" => false
* "2e10" => true
* Note: It is intended for the problem statement to be ambiguous.
* You should gather all requirements up front before implementing one.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2
#ifdef W1
// 要考虑到所有情况比较麻烦。
// 并不是很好的写法。
// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
	bool isNumber(const char *s) {
		if (!s) {return false;}
		int i = 0;
		char c = s[0];
		int digit_num = 0;
		bool has_e = false;
		bool has_point = false;
		bool has_num_after_e = false;
		bool is_space_middle = false;
		bool has_sign = false;
		while (c)
		{
			if (c != ' ' && c != '.' && c != 'e' && (c < '0' || c > '9') && c != '+' && c != '-') {return false;}
			if (c == ' ' && (digit_num || has_point || has_e || has_sign)) {is_space_middle = true;}
			if (c == '-' && (digit_num || has_point)) {return false;}
			if (c == '+' && (digit_num || has_point)) {return false;}
			if (c == '-' && has_sign) {return false;}
			if (c == '+' && has_sign) {return false;}
			if (c == '-' && !digit_num) {has_sign = true;}
			if (c == '+' && !digit_num) {has_sign = true;}
			if (c == '.' && has_point) {return false;}
			if (c == '.' && !has_point) {has_point = true;}
			if (c == '.' && has_e) {return false;}
			if (c == '.' && is_space_middle) {return false;}
			if (c == 'e' && has_e) {return false;}
			if (c == 'e' && !digit_num) {return false;}
			if (c == 'e' && digit_num) {has_e = true; digit_num = 0; has_point = false; has_sign = false;}
			if (c == 'e' && is_space_middle) {return false;}
			if (c >= '0' && c <= '9') {++digit_num;}
			if (c >= '0' && c <= '9' && has_e) {has_num_after_e = true;}
			if (c >= '0' && c <= '9' && is_space_middle) {return false;}

			c = s[++i];
		}
		if (!digit_num) {return false;}
		if (has_e && !has_num_after_e) {return false;}
		return true;
	}
};
#endif

#ifdef W2
// 有限自动机。时间复杂度O(n)，空间复杂度O(n)。
// 写法不直观，也不怎么样。
class Solution {
public:
	bool isNumber(const char *s){
		if (!s) return false;
		enum InputType {
			INVALID, SPACE, SIGN, DIGIT, DOT, EXPONENT, NUM_INPUTS	// 0-6
			//0			1	2		3		4	5		6
		};
		const int transitionTable[][NUM_INPUTS] = {
			//0	1	2	3	4	5
			-1,	0,	3,	1,	2,	-1,	// next states for state 0，无前置条件
			-1,	8,	-1,	1,	4,	5,	// for state 1，前一位是数字
			-1,	-1,	-1,	4,	-1,	-1,	// for state 2，前一位是小数点
			-1,	-1,	-1,	1,	2,	-1,	// for state 3，前一位是+-符号
			-1,	8,	-1,	4,	-1,	5,	// for state 4，前面有小数点，前一位是数字
			-1,	-1,	6,	7,	-1,	-1,	// for state 5，前面有数字，前一位是e
			-1,	-1,	-1,	7,	-1,	-1,	// for state 6，前面有e，前一位是+-符号
			-1,	8,	-1,	7,	-1,	-1, // for state 7，前面有e，前一位是数字
			-1,	8,	-1,	-1,	-1,	-1,	// for state 8，前面是空格，要想符合只能末尾全是空格
		};
		int state(0);
		for (; *s != '\0'; ++s)
		{
			InputType input_type = INVALID;
			if (isspace(*s))				{input_type = SPACE;}
			else if (*s == '+' || *s == '-')	{input_type = SIGN;}
			else if (isdigit(*s))			{input_type = DIGIT;}
			else if (*s == '.')				{input_type = DOT;}
			else if (*s == 'e' || *s == 'E')	{input_type = EXPONENT;}

			// Get next state from current state and input symbol
			state = transitionTable[state][input_type];
			// invalid input
			if (state == -1) return false;
		}
		// if the current state belongs to one of the accepting final states,
		// the number is valid
		return state == 1 || state == 4 || state == 7 || state == 8;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Valid_Number", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.isNumber(NULL) == false);
		REQUIRE(s.isNumber("\0") == false);
	}
	SECTION("Normal Input"){
		REQUIRE(s.isNumber("1") == true);
		REQUIRE(s.isNumber("0.1") == true);
		REQUIRE(s.isNumber("-3") == true);
		REQUIRE(s.isNumber("   5") == true);
		REQUIRE(s.isNumber("1 a") == false);
		REQUIRE(s.isNumber("2e10") == true);
		REQUIRE(s.isNumber("a") == false);
		REQUIRE(s.isNumber("++1") == false);
		REQUIRE(s.isNumber("..6") == false);
		REQUIRE(s.isNumber("2e0.2") == false);
		REQUIRE(s.isNumber("2e-2") == true);
		REQUIRE(s.isNumber("  10  ") == true);
		REQUIRE(s.isNumber("0123") == true);
	}
}