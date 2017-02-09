//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2017/02/09
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.
* 
* Note:
* 
* The length of both num1 and num2 is < 110.
* Both num1 and num2 contains only digits 0-9.
* Both num1 and num2 does not contain any leading zero.
* You must not use any built-in BigInteger library or convert the inputs to integer directly.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2
#ifdef W1
// 干嘛遍历两遍，可以想清楚，一遍就可以。差评。
class Solution {
public:
	string multiply(string num1, string num2) {
		// special cases
		if (num1.empty() || num2.empty()) return "0";
		if ((num1.size() == 1 && num1 == "0") || (num2.size() == 1 && num2 == "0")) return "0";
		// get every sub string
		vector<string> substrings;
		for (int j = num2.size() - 1; j >= 0; --j)
		{
			int n2(num2.at(j) - '0');
			int plus(0);
			string cur_num("");
			for (int i = num1.size() - 1; i >= 0; --i)
			{
				int n1(num1.at(i) - '0');
				int mul_num(n2 * n1 + plus);
				cur_num.insert(cur_num.begin(), '0' + mul_num % 10);
				plus = mul_num / 10;
			}
			if (plus != 0) {cur_num.insert(cur_num.begin(), '0' + plus);}
			substrings.push_back(cur_num + string(num2.size() - j - 1, '0'));
		}
		// add substring
		string result;
		int radix(0), plus(0);
		while (radix < substrings.size())
		{
			int sum(0);
			radix = 0;
			for (string& str : substrings)
			{
				if (!str.empty())
				{
					sum += (str.back() - '0');
					str.pop_back();
				}
				if (str.empty())
				{
					++radix;
				}
			}
			sum += plus;
			result.insert(result.begin(), '0' + sum % 10);
			plus = sum / 10;
		}
		if (plus != 0) {result.insert(result.begin(), '0' + plus);}
		return result;
	}
};
#endif

#ifdef W2
/*
This is the standard manual multiplication algorithm.
We use two nested for loops, working backward from the end of each input number.
We pre-allocate our result and accumulate our partial result in there.
One special case to note is when our carry requires us to write to our sum string outside of our for loop.

At the end, we trim any leading zeros, or return 0 if we computed nothing but zeros.

注意到i + j + 1这个关系。
*/
class Solution {
public:
	string multiply(string num1, string num2) {
		string sum(num1.size() + num2.size(), '0');

		for (int i = num1.size() - 1; 0 <= i; --i)
		{
			int carry = 0;
			for (int j = num2.size() - 1; 0 <= j; --j)
			{
				int tmp = (sum[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
				sum[i + j + 1] = tmp % 10 + '0';
				carry = tmp / 10;
			}
			sum[i] += carry;
		}

		size_t startpos = sum.find_first_not_of("0");
		if (string::npos != startpos) {
			return sum.substr(startpos);
		}
		return "0";
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Multiply_Strings", "[Strings]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.multiply("", "") == "0");
		REQUIRE(s.multiply("999", "0") == "0");
		REQUIRE(s.multiply("9999999999999", "999999999999") == "9999999999989000000000001");
		REQUIRE(s.multiply("12", "345") == "4140");
	}
}