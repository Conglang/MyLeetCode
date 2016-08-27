//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an unsorted array nums, reorder it such that nums[0] < nums[1] > nums[2] < nums[3]....
* 
* Example:
* (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
* (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
* 
* Note:
* You may assume all input has valid answer.
* 
* Follow Up:
* Can you do it in O(n) time and/or in-place with O(1) extra space?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/32929/o-n-o-1-after-median-virtual-indexing/2
/*
First I find a median using nth_element. That only guarantees O(n) average time complexity and
I don't know about space complexity. I might write this myself using O(n) time and O(1) space,
but that's not what I want to show here.

This post is about what comes after that. We can use three-way partitioning to arrange the
numbers so that those larger than the median come first, then those equal to the median come next,
and then those smaller than the median come last.

Ordinarily, you'd then use one more phase to bring the numbers to their final positions to
reach the overall wiggle-property. But I don't know a nice O(1) space way for this. Instead,
I embed this right into the partitioning algorithm. That algorithm simply works with
indexes 0 to n-1 as usual, but sneaky as I am, I rewire those indexes where I want the
numbers to actually end up. The partitioning-algorithm doesn't even know that I'm doing that,
it just works like normal (it just uses A(x) instead of nums[x]).

Let's say nums is [10,11,...,19]. Then after nth_element and ordinary partitioning,
we might have this (15 is my median):

index:     0  1  2  3   4   5  6  7  8  9
number:   18 17 19 16  15  11 14 10 13 12
I rewire it so that the first spot has index 5, the second spot has index 0, etc,
so that I might get this instead:

index:     5  0  6  1  7  2  8  3  9  4
number:   11 18 14 17 10 19 13 16 12 15
And 11 18 14 17 10 19 13 16 12 15 is perfectly wiggly. And the whole
partitioning-to-wiggly-arrangement (everything after finding the median)
only takes O(n) time and O(1) space.
*/
class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n(nums.size());
        
        // Find a median.
        // The element at the nth position is the element that would be in that position in a sorted sequence.
        auto midptr = nums.begin() + n / 2;
        nth_element(nums.begin(), midptr, nums.end());
        int mid = *midptr;
        
        // Index-rewiring.
        #define A(i) nums[(1+2*(i)) % (n|1)]
    
        // 3-way-partition-to-wiggly in O(n) time with O(1) space.
        int i = 0, j = 0, k = n - 1;
        while (j <= k) {
            if (A(j) > mid)
                swap(A(i++), A(j++));
            else if (A(j) < mid)
                swap(A(j), A(k--));
            else
                j++;
        }
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Wiggle_Sort_II", "[Sorting]"){
	Solution s;
	SECTION("Normal Input"){
		int t[10] = {10,11,12,13,14,15,16,17,18,19};
		int r[10] = {11, 18, 14, 17, 10, 19, 13, 16, 12, 15};
		vector<int> nums(t,t+10);
		vector<int> rs(r,r+10);
		s.wiggleSort(nums);
		bool result = (nums[0] < nums[1]) && (nums[1] > nums[2]) && (nums[2] < nums[3]) && (nums[3] > nums[4]) && (nums[4] < nums[5]) && (nums[5] > nums[6]) && (nums[6] < nums[7]) && (nums[7] > nums[8]) && (nums[8] < nums[9]);
		REQUIRE(result == true);
	}
}
