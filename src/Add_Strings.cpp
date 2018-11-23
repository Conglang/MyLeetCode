//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/24
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
* 
* Note:
* 
* The length of both num1 and num2 is < 5100.
* Both num1 and num2 contains only digits 0-9.
* Both num1 and num2 does not contain any leading zero.
* You must not use any built-in BigInteger library or convert the inputs to integer directly.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

// string反转过来逐位加和。最后记得加上plus即可。
class Solution {
public:
    string addStrings(string num1, string num2) {
        if (num1.empty() || num2.empty())
            return "0";
        
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        
        int plus(0);
        string result;
        
        for (int i = 0; i < max(num1.size(), num2.size()); ++i) {
            int n1 = i >= num1.size() ? 0 : num1[i] - '0';
            int n2 = i >= num2.size() ? 0 : num2[i] - '0';
            int sum(n1 + n2 + plus);
            plus = sum / 10;
            result += to_string(sum % 10);
        }
        
        if (plus) {
            result += to_string(plus);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Add_Strings", "[String]"){
	Solution s;
	SECTION("Normal Input") {
		REQUIRE(s.addStrings("999","99") == "1098");
        REQUIRE(s.addStrings("9999999999999999999999999999","99") == "10000000000000000000000000098");
	}
}