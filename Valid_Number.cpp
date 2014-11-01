//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
//--------------------------------------------------------------------------------------------------------------*/
// My Way. 要考虑到所有情况比较麻烦。
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