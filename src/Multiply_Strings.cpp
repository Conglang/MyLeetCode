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