//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 一定要注意优化，减法简直不能忍，应该每次就去掉一个数量级才对。
class Solution {
public:
	string intToRoman(int num) {
		string result;
		const int radix[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		const string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

		for (size_t i = 0; num > 0; ++i)
		{
			int count = num / radix[i];
			num %= radix[i];
			for (; count > 0; --count) {result += symbol[i];}
		}
		return result;
	}
};
