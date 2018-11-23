//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/7
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of integers, find two numbers such that they add up to a specific target number.
* 
* The function twoSum should return indices of the two numbers such that they add up to the target,
* where index1 must be less than index2. Please note that your returned answers (both index1 and index2)
* are not zero-based.
* 
* You may assume that each input would have exactly one solution.
* 
* Input: numbers={2, 7, 11, 15}, target=9
* Output: index1=1, index2=2
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(n)。
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		unordered_map<int, int> hash;
		// 首先用一个哈希表记录下每个元素的序号。
		for (int i = 0; i < numbers.size(); ++i)
		{
			hash[numbers[i]] = i;
		}
		for(int i = 0; i < numbers.size(); ++i)
		{
			// 遍历，如果target减去当前值的值也属于列表，并且本值是两值中比较小的那个，记录。
			if (hash.find(target - numbers[i]) != hash.end() && hash[target - numbers[i]] > i)
			{
				result.push_back(i + 1);
				result.push_back(hash[target - numbers[i]] + 1);
				break;
			}
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Two_Sum", "[Arrays]"){
	Solution s;
	SECTION("Empty Input") {
		vector<int> num,result;
		REQUIRE(s.twoSum(num,0) == result);
	}
	SECTION("Normal Input") {
		int numbers[4] = {2, 7, 11, 15};
		vector<int> num(numbers, numbers+4);
		vector<int> result(1,1);
		result.push_back(2);
		REQUIRE(s.twoSum(num, 9) == result);
	}
}
