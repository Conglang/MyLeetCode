//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of integers that is already sorted in ascending order,
* find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that
* they add up to the target, where index1 must be less than index2.
* Please note that your returned answers (both index1 and index2) are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)
// Two Pointers。两个指针逐渐向中间逼近。
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> result;
        if (numbers.size() < 2) return result;
        int left(0), right(numbers.size()-1);
        while(left < right)
        {
            int remain(target - numbers[left]);
            while(left < right)
            {
                if (numbers[right] == remain)
                {
                    result.push_back(left+1);
                    result.push_back(right+1);
                    return result;
                }else if (numbers[right] > remain) {--right;}
                else {break;}
            }
            ++left;
        }
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Two_Sum_II_Input_Array_is_Sorted", "[Arrays]"){
	Solution s;
	SECTION("Invalid Input"){
		vector<int> v;
		REQUIRE(s.twoSum(v, 10) == v);
	}
	SECTION("Normal Input"){
		int n[4] = {2,7,11,15};
		vector<int> numbers(n,n+4);
		int r[2] = {1,2};
		vector<int> result(r,r+2);
		REQUIRE(s.twoSum(numbers, 9) == result);
	}
}
