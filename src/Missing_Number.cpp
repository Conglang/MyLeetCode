//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/07
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, 
* find the one that is missing from the array.
* 
* For example,
* Given nums = [0, 1, 3] return 2.
* 
* Note:
* Your algorithm should run in linear runtime complexity. 
* Could you implement it using only constant extra space complexity?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Time Complexity O(n), Space Complexity O(1)
#define W1

#ifdef W1
// XOR
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int res(nums.size());
		for (int i = 0; i < nums.size(); ++i)
		{
			res ^= i;
			res ^= nums[i];
		}
		return res;
	}
};
#endif
#ifdef W2
// Sum
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		int len(nums.size());
		int sum((0+len)*(len+1)/2);
		for (int i = 0; i < nums.size(); ++i)
		{
			sum -= nums[i];
		}
		return sum;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Missing_Number", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int a1[3] = {3,2,0};
		int a2[3] = {1,2,0};
		vector<int> v1;
		REQUIRE(s.missingNumber(v1) == 0);
		vector<int> v2(a1,a1+3);
		REQUIRE(s.missingNumber(v2) == 1);
		vector<int> v3(a2,a2+3);
		REQUIRE(s.missingNumber(v3) == 3);
		vector<int> v4(1,0);
		REQUIRE(s.missingNumber(v4) == 1);
		vector<int> v5(1,1);
		REQUIRE(s.missingNumber(v5) == 0);
	}
}
