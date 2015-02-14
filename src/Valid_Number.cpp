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
* Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
#define W2
#ifdef W1
// Ҫ���ǵ���������Ƚ��鷳��
// �����Ǻܺõ�д����
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
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
// �����Զ�����ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)��
// д����ֱ�ۣ�Ҳ����ô����
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
			-1,	0,	3,	1,	2,	-1,	// next states for state 0����ǰ������
			-1,	8,	-1,	1,	4,	5,	// for state 1��ǰһλ������
			-1,	-1,	-1,	4,	-1,	-1,	// for state 2��ǰһλ��С����
			-1,	-1,	-1,	1,	2,	-1,	// for state 3��ǰһλ��+-����
			-1,	8,	-1,	4,	-1,	5,	// for state 4��ǰ����С���㣬ǰһλ������
			-1,	-1,	6,	7,	-1,	-1,	// for state 5��ǰ�������֣�ǰһλ��e
			-1,	-1,	-1,	7,	-1,	-1,	// for state 6��ǰ����e��ǰһλ��+-����
			-1,	8,	-1,	7,	-1,	-1, // for state 7��ǰ����e��ǰһλ������
			-1,	8,	-1,	-1,	-1,	-1,	// for state 8��ǰ���ǿո�Ҫ�����ֻ��ĩβȫ�ǿո�
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
		REQUIRE(s.isNumber('\0') == false);
	}
	SECTION("Normal Input"){
		// TODO
	}
}