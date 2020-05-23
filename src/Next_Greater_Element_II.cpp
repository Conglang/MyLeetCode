//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2017/02/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a circular array (the next element of the last element is the first element of the array), 
* print the Next Greater Number for every element. The Next Greater Number of a number x is
* the first greater number to its traversing-order next in the array,
* which means you could search circularly to find its next greater number.
* If it doesn't exist, output -1 for this number.
* 
* Example 1:
* Input: [1,2,1]
* Output: [2,-1,2]
* Explanation: The first 1's next greater number is 2; 
* The number 2 can't find next greater number; 
* The second 1's next greater number needs to search circularly, which is also 2.
* Note: The length of given array won't exceed 10000.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		// special cases
		vector<int> result;
		if (nums.empty()) return result;
		// initialize
		int n(nums.size());
		result.assign(n, -1);
		// copy array to end
		nums.reserve(2*n);
		copy(nums.begin(), nums.end(), back_inserter(nums));
		// tranver to find first greater
		for (int i = n-1; i >= 0; --i)
		{
			for (int j = i+1; j < 2*n; ++j)
			{
				if (nums[j] > nums[i])
				{
					result[i] = nums[j];
					break;
				}
			}
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Next_Greater_Element_II", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int t1[3] = {1,2,1};
		int t2[5] = {1,2,3,4,5};
		int t3[5] = {5,4,3,2,1};
		int t4[5] = {1,3,5,4,2};
		int t5[5] = {2,4,5,3,1};
		int t6[5] = {5,3,1,4,2};
		int t7[5] = {4,2,1,3,5};

		int r1[3] = {2,-1,2};
		int r2[5] = {2,3,4,5,-1};
		int r3[5] = {-1,5,5,5,5};
		int r4[5] = {3,5,-1,5,3};
		int r5[5] = {4,5,-1,4,2};
		int r6[5] = {-1,4,4,5,5};
		int r7[5] = {5,3,3,5,-1};

		vector<int> v1(t1,t1+3);
		REQUIRE(s.nextGreaterElements(v1) == vector<int>(r1,r1+3));
		vector<int> v2(t2,t2+5);
		REQUIRE(s.nextGreaterElements(v2) == vector<int>(r2,r2+5));
		vector<int> v3(t3,t3+5);
		REQUIRE(s.nextGreaterElements(v3) == vector<int>(r3,r3+5));
		vector<int> v4(t4,t4+5);
		REQUIRE(s.nextGreaterElements(v4) == vector<int>(r4,r4+5));
		vector<int> v5(t5,t5+5);
		REQUIRE(s.nextGreaterElements(v5) == vector<int>(r5,r5+5));
		vector<int> v6(t6,t6+5);
		REQUIRE(s.nextGreaterElements(v6) == vector<int>(r6,r6+5));
		vector<int> v7(t7,t7+5);
		REQUIRE(s.nextGreaterElements(v7) == vector<int>(r7,r7+5));
	}
}