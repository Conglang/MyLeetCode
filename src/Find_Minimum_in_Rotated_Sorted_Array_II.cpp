//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/29
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Follow up for "Find Minimum in Rotated Sorted Array":
* What if duplicates are allowed?
* 
* Would this affect the run-time complexity? How and why?
* Suppose a sorted array is rotated at some pivot unknown to you beforehand.
* 
* (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
* 
* Find the minimum element.
* 
* The array may contain duplicates.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class Solution {
public:
    int findMin2(vector<int>& nums) {
        int low(0), high(nums.size()-1);
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
            }else
            {
                --high;
            }
        }
        return nums[low];
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Find_Minimum_in_Rotated_Sorted_Array_II", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int a[5] = {0,1,1,1,6};
		int b[6] = {7,0,1,1,1,6};
		int c[10] = {5,6,7,0,0,1,1,1,2,3};
		int d[7] = {1,1,0,1,1,1,1};
		REQUIRE(s.findMin2(vector<int>(a,a+5)) == 0);
		REQUIRE(s.findMin2(vector<int>(b,b+6)) == 0);
		REQUIRE(s.findMin2(vector<int>(c,c+10)) == 0);
		REQUIRE(s.findMin2(vector<int>(d,d+7)) == 0);
	}
}