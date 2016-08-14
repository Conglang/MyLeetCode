//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/7/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Example:
* Given num = 16, return true. Given num = 5, return false.
* 
* Follow up: Could you solve it without loops/recursion?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2
#ifdef W1
// 时间复杂度O(n/4), 空间复杂度O(1)。
class Solution {
public:
    bool isPowerOfFour(int num) {
        if (num == 0) return false;
        int remain(num);
        while (remain != 1)
        {
            if (remain % 4) return false;
            remain /= 4;
        }
        return true;
    }
};
#endif
#ifdef W2
// 时间复杂度O(1)，空间复杂度O(1)。
class Solution {
public:
    bool isPowerOfFour(int num) {
		if (!num) return false;
		bitset<32> binary_num(num);
        bitset<32> mask("01010101010101010101010101010101");
		if (num & mask.flip().to_ulong() || binary_num.count() != 1) {return false;}
        return true;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Power_of_Four", "[Detail]"){
	Solution s;
	SECTION("Accept") {
		REQUIRE(s.isPowerOfFour(1) == true);
		REQUIRE(s.isPowerOfFour(4) == true);
		REQUIRE(s.isPowerOfFour(256) == true);
	}
	SECTION("Denail") {
		REQUIRE(s.isPowerOfFour(0) == false);
		REQUIRE(s.isPowerOfFour(2) == false);
		REQUIRE(s.isPowerOfFour(8) == false);
		REQUIRE(s.isPowerOfFour(255) == false);
	}
}