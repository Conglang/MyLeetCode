//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/30
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Rotate an array of n elements to the right by k steps.
* 
* For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
* 
* Note:
* Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.
* 
* [show hint]
* 
* Hint:
* Could you do it in-place with O(1) extra space?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2

#ifdef W1
// Ref: https://discuss.leetcode.com/topic/9406/3-lines-of-c-in-one-pass-using-swap/14
// Time complexity: O(n), Space complexity: O(1)
// 用swap旋转前k个，然后在剩下的r个数字中旋转r-k个，逐渐。
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int start(0), n(nums.size());
        for (; k %= n; n -= k, start +=k )
        {
            for (int i = 0; i < k; ++i)
            {
                swap(nums[start + i], nums[start + n - k + i]);
            }
        }
    }
};
#endif

#ifdef W2
// Ref: https://leetcode.com/articles/rotate-array/#approach-3-using-cyclic-replacements-accepted
/*
This approach is based on the fact that when we rotate the array k times,
k%n elements from the back end of the array come to the front 
and the rest of the elements from the front shift backwards.

In this approach, we firstly reverse all the elements of the array.
Then, reversing the first k elements followed by reversing the rest n-k elements gives us the required result.

Let n=7 and k=3.

Original List                   : 1 2 3 4 5 6 7
After reversing all numbers     : 7 6 5 4 3 2 1
After reversing first k numbers : 5 6 7 4 3 2 1
After revering last n-k numbers : 5 6 7 1 2 3 4 --> Result
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        reverse(nums.begin(), nums.begin()+nums.size());
        reverse(nums.begin(), nums.begin()+k);
        reverse(nums.begin()+k, nums.begin()+nums.size());
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Rotate_Array", "[Arrays]"){
	Solution s;
	SECTION("Normal Input 1 "){
		int t[7] = {1,2,3,4,5,6,7};
		int r[7] = {5,6,7,1,2,3,4};
		vector<int> result(t,t+7);
		s.rotate(result, 10);
		REQUIRE(result == vector<int>(r,r+7));
	}
	SECTION("Normal Input 2 "){
		int t[6] = {1,2,3,4,5,6};
		int r[6] = {6,1,2,3,4,5};
		vector<int> result(t,t+6);
		s.rotate(result, 1);
		REQUIRE(result == vector<int>(r,r+6));
	}
}
