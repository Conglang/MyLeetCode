//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Reverse bits of a given 32 bits unsigned integer.
* 
* Example:
* 
* Input: 43261596
* Output: 964176192
* Explanation: 43261596 represented in binary as 00000010100101000001111010011100, 
*              return 964176192 represented in binary as 00111001011110000010100101000000.
* Follow up:
* If this function is called many times, how would you optimize it?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

// 32位bit，逐步反转。再之前基础上乘2再加上当前值。
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result(0);
        int count(0);
        while (count < 32) {
            int cur_bit = static_cast<int>((n & (1 << count)) != 0);
            result = (result << 1) + cur_bit;
            ++count;
        }
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Reverse_Bits", "[Bit Manipulation]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.reverseBits(43261596) == 964176192);
	}
}