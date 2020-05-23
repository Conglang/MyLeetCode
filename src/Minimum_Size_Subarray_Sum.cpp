//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of n positive integers and a positive integer s,
* find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
* 
* For example, given the array [2,3,1,2,4,3] and s = 7,
* the subarray [4,3] has the minimal length under the problem constraint.
* 
* More practice:
* If you have figured out the O(n) solution, try coding another solution of which the
* time complexity is O(n log n).
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/17063/4ms-o-n-8ms-o-nlogn-c
#define W1
#ifdef W1
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty() || s <= 0) return 0;
        int n = nums.size(), start = 0, sum = 0, minlen = INT_MAX;
        for (int i = 0; i < n; ++i)
		{ 
            sum += nums[i]; 
            while (sum >= s)
			{
                minlen = min(minlen, i - start + 1);
                sum -= nums[start++];
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
#endif

#ifdef W2
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty() || s <= 0) return 0;
        int n = nums.size(), left = 0, right = 0, sum = 0, minlen = INT_MAX;
        while (right < n)
		{
            do sum += nums[right++];
            while (right < n && sum < s);
            while (left < right && sum - nums[left] >= s)
                sum -= nums[left++];
            if (sum >= s)
				minlen = min(minlen, right - left);
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
};
#endif

#ifdef W3
// 时间复杂度O(nlogn)，空间复杂度O(1)
/*
The idea is to first maintain an array of accumulated summations of elements in nums.
Specifically, for nums = [2, 3, 1, 2, 4, 3] in the problem statement,sums = [0, 2, 5, 6, 8, 12, 15].
Then for each element in sums, if it is not less than s, we search for the first element that
is greater than sums[i] - s (in fact, this is just what the upper_bound function does) in sums
using binary search.

Let's do an example.
Suppose we reach 12 in sums, which is greater than s = 7.
We then search for the first element in sums that is greater than sums[i] - s = 12 - 7 = 5 and we find 6.
Then we know that the elements in nums that correspond to 6, 8, 12 sum to a number 12 - 5 = 7 which is not less than s = 7.
Let's check for that: 6 in sums corresponds to 1 in nums, 8 in sums corresponds to 2 in nums,
12 in sums corresponds to 4 in nums. 1, 2, 4 sum to 7, which is 12 in sums minus 5 in sums.

We add a 0 in the first position of sums to account for cases like nums = [3], s = 3.
*/
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		if (nums.empty() || s <= 0) return 0;
        vector<int> sums = accumulate(nums);
        int n = nums.size(), minlen = INT_MAX;
        for (int i = 1; i <= n; i++)
		{ 
            if (sums[i] >= s)
			{
                int p = upper_bound(sums, 0, i, sums[i] - s);
                if (p != -1)
					minlen = min(minlen, i - p + 1);
            }
        }
        return minlen == INT_MAX ? 0 : minlen;
    }
private:
    vector<int> accumulate(vector<int>& nums)
	{
        int n = nums.size();
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; i++) 
            sums[i] = nums[i - 1] + sums[i - 1];
        return sums;
    }
    int upper_bound(vector<int>& sums, int left, int right, int target) {
        int l = left, r = right;
        while (l < r)
		{
            int m = l + ((r - l) >> 1);
            if (sums[m] <= target)
				l = m + 1;
            else
				r = m;
        }
        return sums[r] > target ? r : -1;
    }
};  
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Minimum_Size_Subarray_Sum", "[Arrays]"){
	Solution s;
	SECTION("Invalid Input"){
		vector<int> nums;
		REQUIRE(s.minSubArrayLen(10, nums) == 0);
		nums.push_back(2);
		REQUIRE(s.minSubArrayLen(-1, nums) == 0);
	}
	SECTION("Normal Input"){
		int n[6] = {2,3,1,2,4,3};
        vector<int> v1(n,n+6);
		REQUIRE(s.minSubArrayLen(7, v1) == 2);
		int m[5] = {1,2,3,4,5};
        vector<int> v2(m,m+5);
		REQUIRE(s.minSubArrayLen(11, v2) == 3);
		int l[5] = {1,5,2,3,4};
        vector<int> v3(l,l+5);
		REQUIRE(s.minSubArrayLen(11, v3) == 4);
	}
}