//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/8
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
//--------------------------------------------------------------------------------------------------------------*/
#include "project/include.h"
// Learned Way
// 先排序，然后从两侧向中心逼近。
// 注意防止重复做的优化：排序后如果下一个和自己的值一样，就没有必要再对其重复自己做过的一切了。
// 如果不做这个优化会Time Limit Exceed.
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > res;
		if (num.size() <= 2) return res;
		sort(num.begin(), num.end());
		int twoSum;
		for (int i = 0; i < num.size() - 2;)
		{
			int l = i + 1, r = num.size() - 1;
			twoSum = 0 - num[i];
			while (l < r)
			{
				if (num[l] + num[r] < twoSum) {l++;}
				else if (num[l] + num[r] > twoSum) {r--;}
				else
				{
#if __cplusplus < 201103L
					int tmp[3] = {num[i], num[l], num[r]};
					vector<int> temp(tmp, tmp+3);
					res.push_back(temp);			
#else
					res.push_back({num[i], num[l], num[r]}); // Not Support by VS2010
#endif
					do { l++; }while (l < r && num[l - 1] == num[l]);	// 注意此处优化。先右移，判断和自己之前的相同否。
					do { r--; }while (l < r && num[r + 1] == num[r]);	// 优化。
				}
			}
			do{ i++; }while (i < num.size() - 1 && num[i - 1] == num[i]);	// 优化。
		}
		sort(res.begin(),res.end());	// 这样最终的结果不需要删除重复元素。
		return res;
	}
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("3Sum", "[3Sum]"){
	Solution s;
	SECTION("Empty Vector"){
		vector<int> num;
		REQUIRE(s.threeSum(num).empty() == true);
	}
	SECTION("Normal Vector"){
		int tmp[6] = {-1,0,1,2,-1,-4};
		int result1[3] = {-1, 0, 1};
		int result2[3] = {-1, -1, 2};
		vector<int> r1(result1, result1+3);
		vector<int> r2(result2, result2+3);
		vector<vector<int> > result;
		result.push_back(r1);
		result.push_back(r2);
		vector<int> num(tmp, tmp+6);
		vector<vector<int> > my(s.threeSum(num));
		sort(my.begin(), my.end());
		sort(result.begin(), result.end());
		REQUIRE(my == result);
	}
}