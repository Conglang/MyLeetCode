//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/19
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array which consists of non-negative integers and an integer m, 
* you can split the array into m non-empty continuous subarrays. 
* Write an algorithm to minimize the largest sum among these m subarrays.
* 
* Note:
* Given m satisfies the following constraint: 1 ≤ m ≤ length(nums) ≤ 14,000.
* 
* Examples:
* 
* Input:
* nums = [7,2,5,10,8]
* m = 2
* 
* Output:
* 18
* 
* Explanation:
* There are four ways to split nums into two subarrays.
* The best way is to split it into [7,2,5] and [10,8],
* where the largest sum among the two subarrays is only 18.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/61395/c-fast-very-clear-explanation-clean-code-solution-with-greedy-algorithm-and-binary-search
// 这个值在最大的数和数据和之间，二分查找。然后用贪婪算法计算这个数能否用该cut数切割。
class Solution {
private:
    /* 
        Params:
            nums - The input array; 
            cuts - How many cuts are available (cuts = #groups - 1); 
            max - The maximum of the (sum of elements in one group);
        Rtn:
            Whether we can use at most 'cuts' number of cuts to segment the entire array, 
            such that the sum of each group will not exceed 'max'.
     */
    bool doable (const vector<int>& nums, int cuts, long long max) {
        // 'acc' is the temporary accumulator for the currently processed group.
        int acc = 0;
        //for (num : nums) {
		for (auto it = nums.begin(); it != nums.end(); ++it)
		{
			auto num = *it;
            // If the current processed element in this array is larger than 'max', we cannot segment the array.
            // (Reason is straightforward, if 'nums' is [10, 2, 3, 5] and 'max' is 6, even you can have 3 cuts
            // (by which you can cut array as [[10], [2], [3], [5]]), the group containing 10 will be larger than 6, 
            //  there is no way to do this).
            // Ps: This step is unnecessary in this solution. Because 'left' in the splitArray() function can assure 
            // 'max' will be larger than every single element. I just want to write a generalized doable() function :)
            if (num > max) return false;

            // If the (sum of the currently processed group) + (current element) is smaller than max, we can add current 
            // element into this group.
            else if (acc + num <= max) acc += num;
            
            // If not, we will make a cut before this element, and this element will be the first element in the new group.
            else {
                --cuts;
                acc = num;
                
                // If we've used up all cuts, this means this 'max' is not doable.
                if (cuts < 0) return false;
            }
        }
        
        // If we can reach here, this means we've used at most 'cuts' cut to segment the array, and the sum of each groups is
        // not larger than 'max'. Yeah!
        return true;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        // Use long long to avoid overflow.
        long long left = 0, right = 0;
        // The smallest possible value ('left') is the the value of the largest element in this array.
        // The largest possible value ('right') is the sum of all elements in this array.
        //for (num : nums) {
		for (auto it = nums.begin(); it != nums.end(); ++it)
		{
			auto num = *it;
            left = max(left, (long long)num);
            right += num;
        }
        
        // Use binary search, find the lower bound of the possible (minimum sum of groups within m - 1 cuts).
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (doable(nums, m - 1, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Split_Array_Largest_Sum", "[Binary_Search]"){
	Solution s;
	SECTION("Normal Input"){
		int nums[5] = {7,2,5,10,8};
		REQUIRE(s.splitArray(vector<int>(nums, nums+5), 2) == 18);
	}
}