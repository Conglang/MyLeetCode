//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Write an algorithm to determine if a number is "happy".
* 
* A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
* 
* Example: 
* 
* Input: 19
* Output: true
* Explanation: 
* 1^2 + 9^2 = 82
* 8^2 + 2^2 = 68
* 6^2 + 8^2 = 100
* 1^2 + 0^2 + 0^2 = 1
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 不断生成下一个数字，是1就true，不是就继续。有一个最大次数限制。
class Solution {
public:
    bool isHappy(int n) {
        if (n < 0)
            return false;
        int count(100);
        int num(n);
        while (count) {
            if (num == 1)
                return true;
            num = get_next_number(num);
            --count;
        }
        return false;
    }
    
    int get_next_number(int num) {
        int result(0);
        while (num) {
            result += (num % 10) * (num % 10);
            num /= 10;
        }
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Happy_Number", "[Brute Force]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.isHappy(19) == true);
        REQUIRE(s.isHappy(85) == false);
        REQUIRE(s.isHappy(0) == false);
        REQUIRE(s.isHappy(-1) == false);
	}
}