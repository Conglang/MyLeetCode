//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given n balloons, indexed from 0 to n-1. 
* Each balloon is painted with a number on it represented by array nums. 
* You are asked to burst all the balloons. 
* If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. 
* Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
* 
* Find the maximum coins you can collect by bursting the balloons wisely.
* 
* Note: 
* (1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
* (2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
* 
* Example:
* 
* Given [3, 1, 5, 8]
* 
* Return 167
* 
*     nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
*    coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/30746/share-some-analysis-and-explanations/2
/*
For the first we have nums[i-1]*nums[i]*nums[i+1] for the last we have nums[-1]*nums[i]*nums[n].
Think about n balloons if i is the last one to burst, what now?
We can see that the balloons is again separated into 2 sections.
But this time since the balloon i is the last balloon of all to burst, 
the left and right section now has well defined boundary and do not affect each other! 
Therefore we can do either recursive method with memoization or dp.
*/
#define W1

#ifdef W1
// Dynamic Programming
class Solution {
public:
    int maxCoins(vector<int>& iNums) {
        // including index -1 and iNums.size()
        vector<int> nums = iNums;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int n(nums.size());
		vector<vector<int>> dp(n, vector<int>(n,0));
        // k is the distance between left and right
        for (int k = 2; k < n; ++k)
        {
            for (int left = 0; left < n - k; ++left)
            {
                int right = left + k;
				// i is the current position between left and right
                for (int i = left + 1; i < right; ++i)
                {
                    dp[left][right] = max(dp[left][right], nums[left] * nums[i] * nums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n-1];
    }
};
#endif

#ifdef W2
// Devide and Conquer
// Time Limit Exceed
class Solution {
public:
    int maxCoins(vector<int>& iNums) {
        // including index -1 and iNums.size()
        vector<int> nums = iNums;
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        
        int n(nums.size());
        vector<vector<int>> memo(n, vector<int>(n,0));
        return burst(memo, nums, 0, n-1);
    }
private:
    int burst(vector<vector<int>> memo, vector<int> nums, int left, int right)
    {
        if (left + 1 == right) return 0;
        if (memo[left][right] > 0) return memo[left][right];
        int ans(0);
        for (int i = left + 1; i < right; ++i)
        {
            ans = max(ans, nums[left]*nums[i]*nums[right] + burst(memo, nums, left, i) + burst(memo, nums, i, right));
        }
        memo[left][right] = ans;
        return ans;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Burst_Balloons", "[Devide and Conquer]") {
	Solution s;
	SECTION("Normal Input") {
		int a[4] = {3,1,5,8};
		REQUIRE(s.maxCoins(vector<int>(a,a+4)) == 167);
	}
}
