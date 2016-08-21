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
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
// ����bucket sort�����������������ֵ����Сֵ������len-1��������������֮���ƽ��ֵ������������֮������ֵһ������ƽ��ֵ��
// �����ͱ�֤����������֮���������һ���ֱ�������bucket�С�ֻ���¼ÿ��bucket������ֵ����Сֵ����Ϊbucket�ڲ��Ĳ�ֵһ��
// С�ڲ�ͬbucket��ģ����Բ��üǡ�Ȼ���������(��bucket����С��ȥǰһbucket�����)�����ֵ���ɡ�
// ��Ϊ�����ֻ��һ����ֵ������û��Ҫȫ�����������˵����ʱ��Ϳռ�ĸ��Ӷ�Ҫ����O(n)�����뵽bucket sort��
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
