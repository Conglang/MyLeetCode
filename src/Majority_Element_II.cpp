//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/06
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.
* The algorithm should run in linear time and in O(1) space.
* 
* Hint:
* 
* How many majority elements could it possibly have?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Time complexity O(n), Space complexity O(1)
// 先遍历一遍，确定有希望的两个数，然后再遍历一遍得到计数，然后看计数是否满足要求。
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) return result;
        int first(INT_MAX), second(INT_MAX);
        int c1(0), c2(0);
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (first == *it) {++c1;}
            else if (second == *it) {++c2;}
            else if (c1 == 0) {first = *it; c1 = 1;}
            else if (c2 == 0) {second = *it; c2 = 1;}
            else{--c1; --c2;}
        }
        c1 = c2 = 0;
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (*it == first) {++c1;}
            else if (*it == second) {++c2;}
        }
        if (c1 > nums.size() / 3) result.push_back(first);
        if (c2 > nums.size() / 3) result.push_back(second);
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Majority_Element_II", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int a1[7] = {1,2,3,3,2,1,3};
		int a2[4] = {1,1,1,1};
		int a3[4] = {1,1,2,1};
		int a4[4] = {2,1,1,1};
		int a5[2] = {1,2};
		int a6[3] = {1,1,2};
		int a7[6] = {1,2,3,1,2,3};
		int r1[2] = {1,2};
		REQUIRE(s.majorityElement(vector<int>()) == vector<int>());
		REQUIRE(s.majorityElement(vector<int>(a1,a1+7)) == vector<int>(1,3));
		REQUIRE(s.majorityElement(vector<int>(a2,a2+4)) == vector<int>(1,1));
		REQUIRE(s.majorityElement(vector<int>(a3,a3+4)) == vector<int>(1,1));
		REQUIRE(s.majorityElement(vector<int>(a4,a4+4)) == vector<int>(1,1));
		REQUIRE(s.majorityElement(vector<int>(a5,a5+2)) == vector<int>(r1,r1+2));
		REQUIRE(s.majorityElement(vector<int>(a6,a6+3)) == vector<int>(1,1));
		REQUIRE(s.majorityElement(vector<int>(a7,a7+6)) == vector<int>());
	}
}