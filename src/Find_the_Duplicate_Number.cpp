//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
* prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
* find the duplicate one.
* 
* Note:
* You must not modify the array (assume the array is read only).
* You must use only constant, O(1) extra space.
* Your runtime complexity should be less than O(n2).
* There is only one duplicate number in the array, but it could be repeated more than once.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(nlogn)，空间复杂度O(1)
// 利用二分查找的思想。从数组中选一个位置，然后遍历一遍看看比这个位置索引数小的有多少个。如果大于索引数，
// 根据题目定义，重复的一定在左边区间，反之则在右边区间。最终停下来的那个索引，不正常的索引，就是被重复的那个。
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left(1), right(nums.size());
        while (left < right)
        {
            int mid(left + ((right - left) >> 1));
            int count(0);
            for (int i = 0; i < nums.size(); ++i)
            {
                if (nums[i] <= mid) {++count;}
            }
            if (count <= mid) {left = mid + 1;}
            else {right = mid;}
        }
        return left;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Find_the_Duplicate_Number", "[Devide and Conquer]"){
	Solution s;
	SECTION("Normal Input"){
		int t1[2] = {1,1};
		int t2[6] = {1,3,2,5,4,3};
		vector<int> v1(t1,t1+2);
		vector<int> v2(t2,t2+6);
		REQUIRE(s.findDuplicate(v1) == 1);
		REQUIRE(s.findDuplicate(v2) == 3);
	}
}
