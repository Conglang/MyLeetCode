//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/11/06
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* A sequence of numbers is called a wiggle sequence if the differences between successive numbers 
* strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative.
* A sequence with fewer than two elements is trivially a wiggle sequence.
* 
* For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are 
* alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, 
* the first because its first two differences are positive and the second because its last difference 
* is zero.
* 
* Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. 
* A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence,
* leaving the remaining elements in their original order.
* 
* Examples:
* Input: [1,7,4,9,2,5]
* Output: 6
* The entire sequence is a wiggle sequence.
* 
* Input: [1,17,5,10,13,15,10,5,16,8]
* Output: 7
* There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
* 
* Input: [1,2,3,4,5,6,7,8,9]
* Output: 2
* Follow up:
* Can you do it in O(n) time?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2
// ref: https://discuss.leetcode.com/topic/51893/two-solutions-one-is-dp-the-other-is-greedy-8-lines/2
#ifdef W1
// DP
// 两个vector分别跟踪以大数结尾和以小数结尾的情况
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n(nums.size());
		if (!n) return 0;
		vector<int> ends_small(n, 1);
		vector<int> ends_big(n, 1);
		for (int r = 1; r < n; ++r)
		{
			for (int l = 0; l < r; ++l)
			{
				if (nums[r] > nums[l]) {ends_big[r] = max(ends_big[r], ends_small[l]+1);}
				else if (nums[r] < nums[l]) {ends_small[r] = max(ends_small[r], ends_big[l]+1);}
			}
		}
		return max(ends_small.back(), ends_big.back());
	}
};
#endif

#ifdef W2
// Greedy Technique
class Solution {
public:
	int wiggleMaxLength(vector<int>& nums) {
		int n(nums.size());
		if (!n) return 0;
		int big(1), small(1);
		for (int i = 1; i < n; ++i)
		{
			if (nums[i] > nums[i-1]) {big = small + 1;}
			else if (nums[i] < nums[i-1]) {small = big + 1;}
		}
		return max(big, small);
	}
};
#endif

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Wiggle_Subsequence", "[Dynamic Programming]"){
	Solution s;
	SECTION("Normal Input"){
		int a[6] = {1,7,4,9,2,5};
		int b[10] = {1,17,5,10,13,15,10,5,16,8};
		int c[9] = {1,2,3,4,5,6,7,8,9};
		REQUIRE(s.wiggleMaxLength(vector<int>(a,a+6)) == 6);
		REQUIRE(s.wiggleMaxLength(vector<int>(b,b+10)) == 7);
		REQUIRE(s.wiggleMaxLength(vector<int>(c,c+9)) == 2);
	}
}