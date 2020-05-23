//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/29
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* Find the minimum element.
* 
* You may assume no duplicate exists in the array.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/6112/a-concise-solution-with-proof-in-the-comment/2
class Solution {
public:
    int findMin(vector<int>& nums) {
        int low(0), high(nums.size()-1);
        // loop invariant: 1. low < high
        //                 2. mid != high and thus A[mid] != A[high] (no duplicate exists)
        //                 3. minimum is between [low, high]
        // The proof that the loop will exit: after each iteration either the 'high' decreases
        // or the 'low' increases, so the interval [low, high] will always shrink.
        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (nums[mid] < nums[high])
            {
                // the mininum is in the left part
                high = mid;
            }else if (nums[mid] > nums[high])
            {
                // the mininum is in the right part
                low = mid + 1;
            }
        }
        return nums[low];
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Find_Minimum_in_Rotated_Sorted_Array", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int a[7] = {4,5,6,7,0,1,2};
		int b[7] = {1,2,3,4,5,6,7};
        vector<int> v1(a,a+7);
		REQUIRE(s.findMin(v1) == 0);
        vector<int> v2(b,b+7);
		REQUIRE(s.findMin(v2) == 1);
	}
}