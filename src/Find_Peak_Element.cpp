//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* A peak element is an element that is greater than its neighbors.
* 
* Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.
* 
* The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
* 
* You may imagine that num[-1] = num[n] = -¡Þ.
* 
* For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
* 
* click to show spoilers.
* 
* Note:
* Your solution should be in logarithmic complexity.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

#define W1

#ifdef W1
// Sequencial
// time complexity O(n), space complexity O(1)
class Solution {
public:
    int findPeakElement(const vector<int> &num) {
        for(int i = 1; i < num.size(); i ++)
        {
            if(num[i] < num[i-1])
            {// <
                return i-1;
            }
        }
        return num.size()-1;
    }
};
#endif

#ifdef W2
// time complexity O(logn), space complexity O(1)
// Binary Search
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low < high)
        {
            int mid1 = (low+high)/2;
            int mid2 = mid1+1;
            if(nums[mid1] < nums[mid2])
                low = mid2;
            else
                high = mid1;
        }
        return low;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Find_Peak_Element", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int a[4] = {1,2,3,1};
		REQUIRE(s.findPeakElement(vector<int>(a,a+4)) == 2);
	}
}