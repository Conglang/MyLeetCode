//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/07
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of n integers where n > 1, nums, return an array output such that output[i] 
* is equal to the product of all the elements of nums except nums[i].
* 
* Solve it without division and in O(n).
* 
* For example, given [1,2,3,4], return [24,12,8,6].
* 
* Follow up:
* Could you solve it with constant space complexity? 
* (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ref: https://discuss.leetcode.com/topic/18864/simple-java-solution-in-o-n-without-extra-space/8
// 第一次遍历把左边的乘起来，第二次遍历把右边的乘起来，两个乘在一起。
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n(nums.size());
        vector<int> product(n, 1);
        for (int i = 1; i < n; ++i)
        {
            product[i] = product[i-1] * nums[i-1];
        }
        for (int i = n-1, r = 1; i >= 0; r *= nums[i--])
        {
            product[i] *= r;
        }
        return product;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Product_of_Array_Except_Self", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int a[4] = {1,2,3,4};
		int r[4] = {24,12,8,6};
		REQUIRE(s.productExceptSelf(vector<int>()) == vector<int>());
		REQUIRE(s.productExceptSelf(vector<int>(a,a+4)) == vector<int>(r,r+4));
	}
}