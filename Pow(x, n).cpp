//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/1/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Implement pow(x, n).
//--------------------------------------------------------------------------------------------------------------*/
#include "project/include.h"
// My Way
// ∑÷÷Œ∑®°£
class Solution {
public:
	double pow(double x, int n) {
		if (x == 0) return 0;
		if (n < 0) return 1.0 / power(x, -n);
		return power(x, n);
	}
private:
	double power(double x, int n)
	{
		if (n == 0) return 1.0;
		if (n == 1) return x;
		if (n == -1) return 1.0 / x;
		double flag(1.0);
		if (n % 2) {flag = x;}
		double temp = power(x, n/2);
		return temp * temp * flag;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Pow(x, n)", "[Devide and Conquer]"){
	Solution s;
	SECTION("x is 0") {
		REQUIRE(s.pow(0, -5) == 0);
	}
	SECTION("n is 0") {
		REQUIRE(s.pow(2.0, 0) == 1);
	}
	SECTION("n is 1") {
		REQUIRE(s.pow(2.0, 1) == 2.0);
	}
	SECTION("n is -1") {
		REQUIRE(s.pow(2.0, -1) == 1.0 / 2.0);
	}
	SECTION("n > 0") {
		REQUIRE(s.pow(2.5, 5) == pow(2.5, 5));
	}
	SECTION("n < 0") {
		REQUIRE(s.pow(2.5, -5) == pow(2.5, -5));
	}
}