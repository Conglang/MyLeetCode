//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of size n, find the majority element.
* The majority element is the element that appears more than ⌊ n/2 ⌋ times.
* 
* You may assume that the array is non-empty and the majority element always exist in the array.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2

#ifdef W1
// 排序，比较慢。
// 时间复杂度O(nlogn)，空间复杂度O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return *(nums.begin() + nums.size()/2);
    }
};
#endif

#ifdef W2
// Ref: http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorElem(nums[0]), count(1);
        for (int i = 1; i < nums.size(); ++i)
        {
            if (count == 0)
            {
                majorElem = nums[i];
                ++count;
            }else if (majorElem == nums[i])
            {
                ++count;
            }else
            {
                --count;
            }
        }
        return majorElem;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Majority_Element", "[Devide and Conquer]"){
	Solution s;
	SECTION("Normal Input"){
		int a1[9] = {1,5,3,4,5,6,5,5,5};
        vector<int> v(a1,a1+9);
		REQUIRE(s.majorityElement(v) == 5);
	}
}