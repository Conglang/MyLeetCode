//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an integer array nums, find the sum of the elements between indices i and j (i ≤ j), inclusive.
* 
* Example:
* Given nums = [-2, 0, 3, -5, 2, -1]
* 
* sumRange(0, 2) -> 1
* sumRange(2, 5) -> -1
* sumRange(0, 5) -> -3
* Note:
* You may assume that the array does not change.
* There are many calls to sumRange function.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class NumArray {
public:
	NumArray(vector<int> &nums) {
		for (auto it = nums.begin(); it != nums.end(); ++it)
		{
			int num = *it;
			sums.push_back((!sums.empty() ? sums.back() : 0) + num);
		}
	}

	int sumRange(int i, int j) {
		return sums[j] - (i ? sums[i-1] : 0);
	}
private:
	vector<int> sums;
};
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Range_Sum_Query_Immutable", "[Dynamic Programming]"){
	SECTION("Normal Input"){
		int t[6] = {-2, 0, 3, -5, 2, -1};
		NumArray numArray(vector<int>(t,t+6));
		REQUIRE(numArray.sumRange(0, 2) == 1);
		REQUIRE(numArray.sumRange(2, 5) == -1);
		REQUIRE(numArray.sumRange(0, 5) == -3);
	}
}