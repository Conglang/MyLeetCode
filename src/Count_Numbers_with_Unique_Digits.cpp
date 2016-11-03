//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/11/03
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a non-negative integer n, count all numbers with unique digits, x, where 0 ¡Ü x < 10n.
* 
* Example:
* Given n = 2, return 91. (The answer should be the total numbers in the range of 0 ¡Ü x < 100,
* excluding [11,22,33,44,55,66,77,88,99])
* 
* Hint:
* 1. A direct way is to use the backtracking approach.
* 2. Backtracking should contains three states which are (the current number,
* number of steps to get that number and a bitmask which represent which number is marked as visited 
* so far in the current number). Start with state (0,0,0) and count all valid number till
* we reach number of steps equals to 10n.
* 3. This problem can also be solved using a dynamic programming approach and some knowledge of 
* combinatorics.
* 4. Let f(k) = count of numbers with unique digits with length equals k.
* 5. f(1) = 10, ..., f(k) = 9 * 9 * 8 * ... (9 - k + 2) [The first factor is 9 
* because a number cannot start with 0].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// DP, According to Hint.
class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		if (!n) return 1;
		int result(10);
		int unique_digits(9);
		int available_number(9);
		while (n-- > 1 && available_number > 0)
		{
			unique_digits *= available_number;
			result += unique_digits;
			--available_number;
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Count_Numbers_with_Unique_Digits", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.countNumbersWithUniqueDigits(2) == 91);
		REQUIRE(s.countNumbersWithUniqueDigits(5) == 32491);
		REQUIRE(s.countNumbersWithUniqueDigits(10) == 8877691);
	}
}