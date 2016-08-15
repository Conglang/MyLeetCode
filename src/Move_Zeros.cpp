//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array nums, write a function to move all 0's to the end of it
* while maintaining the relative order of the non-zero elements.
* 
* For example, given nums = [0, 1, 0, 3, 12], after calling your function,
* nums should be [1, 3, 12, 0, 0].
* 
* Note:
* You must do this in-place without making a copy of the array.
* Minimize the total number of operations.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)。
// Two Pointers
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if (nums.empty()) return;
        int index(0);
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i])
            {
                nums[index++] = nums[i];
            }
        }
        for (int i = index; i < nums.size(); ++i)
        {
            nums[i] = 0;
        }
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Move_Zeros", "[Arrays]"){
	Solution s;
	SECTION("Invalid Input"){
		vector<int> nums;
		s.moveZeroes(nums);
		REQUIRE(nums.empty() == true);
	}
	SECTION("Normal Input"){
		int t[5] = {0,1,0,3,12};
		vector<int> nums(t, t+5);
		int r[5] = {1,3,12,0,0};
		vector<int> result(r, r+5);
		s.moveZeroes(nums);
		REQUIRE(nums == result);
	}
}