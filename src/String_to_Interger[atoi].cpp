//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Implement atoi to convert a string to an integer.
* 
* Hint: Carefully consider all possible input cases. If you want a challenge,
* please do not see below and ask yourself what are the possible input cases.
* 
* Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
* You are responsible to gather all the input requirements up front.
* 
* spoilers alert... click to show requirements for atoi.
* 
* Requirements for atoi:
* The function first discards as many whitespace characters as necessary until the first non-whitespace
* character is found. Then, starting from this character, takes an optional initial plus or minus sign
* followed by as many numerical digits as possible, and interprets them as a numerical value.
* 
* The string can contain additional characters after those that form the integral number, which are
* ignored and have no effect on the behavior of this function.
* 
* If the first sequence of non-whitespace characters in str is not a valid integral number, or if no
* such sequence exists because either str is empty or it contains only whitespace characters,
* no conversion is performed.
* 
* If no valid conversion could be performed, a zero value is returned. If the correct value is out of
* the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
//--------------------------------------------------------------------------------------------------------------*/
/*
*	细节题。注意几个测试用例：
*	1. 不规则输入，但是有效，"-3924x8fc"，"+413",
*	2. 无效格式，"++c", "++1"
*	3. 溢出数据，"2147483648"
*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
	int atoi(const char *str) {
		if (!str) return 0;
		bool is_negative(false);
		int num(0);
		const int n(strlen(str));
		int i(0);

		// 先除空格
		while (str[i] == ' ') i++;

		// 再看符号
		if (str[i] == '+')
		{
			is_negative = false;
			i++;
		}
		else if (str[i] == '-')
		{
			is_negative = true;
			i++;
		}

		// 处理数字
		for (; i < n; ++i)
		{
			// 是不是数字
			if (str[i] < '0' || str[i] > '9'){break;}
			// 是否溢出
			if (num > INT_MAX / 10 || (num == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
					return is_negative ? INT_MIN : INT_MAX;
			}
			// 正常数字
			num = num * 10 + str[i] - '0';
		}
		return num * (is_negative ? -1 : 1);
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("String_to_Interger(atoi)", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.atoi(NULL) == 0);
	}
	SECTION("Normal Input"){
		char a[] = "-3924x8fc";
		REQUIRE(s.atoi(a) == -3924);
		char b[] = "+413";
		REQUIRE(s.atoi(b) == 413);
		REQUIRE(s.atoi("   0") == 0);
		REQUIRE(s.atoi("++c") == 0);
		REQUIRE(s.atoi("--1") == 0);
	}
}