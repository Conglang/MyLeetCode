//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/1/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Implement int sqrt(int x).
* 
* Compute and return the square root of x.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 二分法。时间复杂度O(logn)，空间复杂度O(1)。
class Solution {
public:
	int sqrt(int x) {
		if (x == 0 || x == 1) return x;
		int start(1), end(x/2);
		int last_mid(start);
		while (start <= end)
		{
			int mid(start+(end-start)/2);
			int val(x / mid);
			if (mid < val) {start = mid+1;last_mid = mid;}
			else if (mid > val) {end = mid-1;}
			else {return mid;}
		}
		return last_mid;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Sqrt(x)", "[Devide and Conquer]") {
	Solution s;
	SECTION("x is special") {
		REQUIRE(s.sqrt(0) == 0);
		REQUIRE(s.sqrt(1) == 1);
	}
	SECTION("x is exact sqrtable") {
		REQUIRE(s.sqrt(4) == 2);
		REQUIRE(s.sqrt(25) == 5);
	}
	SECTION("x is approximate sqrtable") {
		REQUIRE(s.sqrt(5) == 2);
		REQUIRE(s.sqrt(30) == 5);
	}
}