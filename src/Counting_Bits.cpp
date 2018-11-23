//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/11/01
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num 
* calculate the number of 1's in their binary representation and return them as an array.
* 
* Example:
* For num = 5 you should return [0,1,1,2,1,2].
* 
* Follow up:
* 	It is very easy to come up with a solution with run time O(n*sizeof(integer)).
* But can you do it in linear time O(n) /possibly in a single pass?
* 	Space complexity should be O(n).
* 	Can you do it like a boss? Do it without using any builtin function
* like __builtin_popcount in c++ or in any other language.
* 
* Hint:
* 
* 	You should make use of what you have produced already.
* 	Divide the numbers in ranges like [2-3], [4-7], [8-15] and so on.
* And try to generate new range from previous.
* 	Or does the odd/even status of the number help you in calculating the number of 1s?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/40162/three-line-java-solution
// f[i] = f[i / 2] + i % 2
class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> dp(num+1, 0);
		for (int i = 1; i <= num; ++i)
		{
			dp[i] = dp[i >> 1] + (i & 1);
		}
		return dp;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Counting_Bits", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		int r1[3] = {0,1,1};
		int r2[6] = {0,1,1,2,1,2};
		int r3[9] = {0,1,1,2,1,2,2,3,1};
		int r4[5] = {0,1,1,2,1};
		REQUIRE(s.countBits(2) == vector<int>(r1,r1+3));
		REQUIRE(s.countBits(5) == vector<int>(r2,r2+6));
		REQUIRE(s.countBits(8) == vector<int>(r3,r3+9));
		REQUIRE(s.countBits(4) == vector<int>(r4,r4+5));
	}
}