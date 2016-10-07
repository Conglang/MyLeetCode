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
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
        {
			if (nums[i] < nums.size())
				swap(nums[i], nums[nums[i]]);
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i != nums[i])
                return i;
        }
        return -1;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Missing_Number", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int a1[3] = {2,3,0};
		int a2[3] = {1,2,0};
		REQUIRE(s.missingNumber(vector<int>()) == -1);
		REQUIRE(s.missingNumber(vector<int>(a1,a1+3)) == 1);
		REQUIRE(s.missingNumber(vector<int>(a2,a2+3)) == -1);
	}
}
