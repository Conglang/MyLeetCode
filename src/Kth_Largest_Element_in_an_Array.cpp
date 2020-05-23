//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Find the kth largest element in an unsorted array.
* Note that it is the kth largest element in the sorted order, not the kth distinct element.
* 
* For example,
* Given [3,2,1,5,6,4] and k = 2, return 5.
* 
* Note: 
* You may assume k is always valid, 1 �� k �� array's length.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// quick sort
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, 0, nums.size(), k-1);
    }
private:
    int findKthLargest(vector<int>& nums, int start, int end, int k)
    {
        int pos = partition(nums, start, end);
        if (pos-start == k)     {return nums[pos];}
        else if (pos-start > k) {return findKthLargest(nums, start, pos, k);}
        else                    {return findKthLargest(nums, pos+1, end, k-(pos-start)-1);}
    }
    int partition(vector<int>& nums, int start, int end)
    {
        int curValue = nums[start];
        int left(start+1), right(end-1);
        while (left <= right)
        {
            while(left <= right && nums[left] > curValue) {++left;}
            while(left <= right && nums[right] <= curValue) {--right;}
            if (left < right)
            {
                swap(nums[left], nums[right]);
            }
        }
        if (right > start)
            swap(nums[start], nums[right]);
        return right;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Kth_Largest_Element_in_an_Array", "[Devide and Conquer]") {
	Solution s;
	SECTION("Normal Input") {
		int a1[7] = {7,6,5,4,3,2,1};
        vector<int> v(a1,a1+7);
		REQUIRE(s.findKthLargest(v, 5) == 3);
	}
}
