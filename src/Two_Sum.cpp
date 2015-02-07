//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/7
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
//--------------------------------------------------------------------------------------------------------------*/
// My Way
// Important
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		unordered_map<int, int> hash;
		for (int i = 0; i < numbers.size(); ++i)
		{
			hash[numbers[i]] = i;
		}
		for(int i = 0; i < numbers.size(); ++i)
		{
			if (hash.find(target - numbers[i]) != hash.end() && hash[target - numbers[i]] > i)
			{
				result.push_back(i + 1);
				result.push_back(hash[target - numbers[i]] + 1);
			}
		}
		return result;
	}
};