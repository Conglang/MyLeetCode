//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/8/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
* 
* Try to solve it in linear time/space.
* 
* Return 0 if the array contains less than 2 elements.
* 
* You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(n)
// 利用bucket sort，求出整个区间的最大值和最小值，除以len-1，就是相邻两数之差的平均值，而相邻两数之差的最大值一定大于平均值，
// 这样就保证，相邻两数之差的两个数一定分别在两个bucket中。只需记录每个bucket里的最大值和最小值，因为bucket内部的差值一定
// 小于不同bucket间的，所以不用记。然后遍历计算(本bucket的最小减去前一bucket的最大)的最大值即可。
// 因为所求的只是一个极值，所以没必要全部排序，题干中说到对时间和空间的复杂度要求是O(n)，联想到bucket sort。
class Solution {
public:
    //bucket sort
    int maximumGap(vector<int>& nums) {
        int len(nums.size());
        if(len < 2){return 0;}
        
        int minValue = INT_MAX;
        int maxValue = INT_MIN;
        for(int i = 0; i < nums.size(); ++i)
        {
            int v(nums[i]);
            minValue = min(minValue, v);
            maxValue = max(maxValue, v);
        }
        int gap = ceil(double((maxValue - minValue))/ (len - 1));
        vector<int> minGaps(len - 1, INT_MAX);// the minmum value of each bucket
        vector<int> maxGaps(len - 1, INT_MIN);
        for(int i = 0; i < nums.size(); ++i)// fill in the bucket
        {
            int v(nums[i]);
            if(v == minValue || v == maxValue)
            {
                continue;
            }
            int gapidx = (v - minValue) / gap;
            minGaps[gapidx] = min(minGaps[gapidx], v);
            maxGaps[gapidx] = max(maxGaps[gapidx], v);
        }
        int pre(minValue), ans(INT_MIN);
        for(int i = 0; i < len - 1; ++i)
        {
            if(minGaps[i] == INT_MAX && maxGaps[i] == INT_MIN)
            {
                continue;
            }
            ans = max(ans, minGaps[i] - pre);
            pre = maxGaps[i];
        }
        ans = max(ans, maxValue - pre);
        return ans;
    }
};//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Maximum_Gap", "[Sorting]"){
	Solution s;
	SECTION("Normal Input1"){
		int t[5] = {15,1,2,3,4};
		vector<int> input(t,t+5);
		REQUIRE(s.maximumGap(input) == 11);
	}
}
