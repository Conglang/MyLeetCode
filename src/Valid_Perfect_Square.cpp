//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a positive integer num, write a function which returns True if num is a perfect square else False.
* 
* Note: Do not use any built-in library function such as sqrt.
* 
* Example 1:
* 
* Input: 16
* Returns: True
* Example 2:
* 
* Input: 14
* Returns: False
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1
#ifdef W1
// Binary Search
class Solution {
public:
	bool isPerfectSquare(int num) {
		long long l = 0, r = num;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			long long sqmid = mid * mid;
			if (sqmid > num) r = mid - 1;
			else if (sqmid < num) l = mid + 1;
			else return true;
		}
		return false;
	}
};
#endif

#ifdef W2
// Newton's Method
class Solution {
public:
	bool isPerfectSquare(int num) {
		float diff;
		float x, x_prev = num;
		do{
			x = x_prev - (x_prev*x_prev - num)/(2*x_prev);
			diff = x_prev - x;
			x_prev = x;
		} 
		while(diff>=1);
		x = (int) x; // if n is a perfect square, its square root must be the floor of x
		if (x*x == num)
			return true;
		else 
			return false;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Valid_Perfect_Square", "[Binary_Search]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.isPerfectSquare(16) == true);
		REQUIRE(s.isPerfectSquare(14) == false);
		REQUIRE(s.isPerfectSquare(0) == true);
		REQUIRE(s.isPerfectSquare(1) == true);
		REQUIRE(s.isPerfectSquare(-1) == false);
	}
}