//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/9
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
* Find all unique quadruplets in the array which gives the sum of target.
* 
* Note:
* Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
* The solution set must not contain duplicate quadruplets.
* For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
* 
* A solution set is:
* (-1,  0, 0, 1)
* (-2, -1, 1, 2)
* (-2,  0, 0, 2)
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n^3)，空间复杂度O(1)。
// 先排序，通过两次遍历让四个数求和变成两个数求和，然后从两侧逼近。
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		if (num.size() < 4) {return result;}
		sort(num.begin(), num.end());

		for(auto a = num.begin(); a < prev(num.end(),3);)
		{
			for(auto d = prev(num.end()); d > next(a,2);)
			{
				auto b = next(a);
				auto c = prev(d);
				while (b < c)
				{
					int sum(*a + *b + *c + *d);
					if (sum < target)
					{
						do{++b;} while(b < c && *(b-1) == *b);
					}else if (sum > target)
					{
						do{--c;} while(b < c && *(c+1) == *c);
					}else
					{
#if __cplusplus < 201103L
						int temp[4] = {*a, *b, *c, *d};
						result.push_back(vector<int>(temp, temp+4));
#else
						result.push_back({*a, *b, *c, *d});
#endif
						do{++b;} while(b < c && *(b-1) == *b);
						do{--c;} while(b < c && *(c+1) == *c);
					}
				}
				do{--d;} while(d > a && *(d+1) == *d);
			}
			do{++a;} while(a < prev(num.end(),3) && *(a-1) == *a);
		}
		sort(result.begin(), result.end());
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("4Sum", "[Arrays]"){
	Solution s;
	SECTION("Empty Vector"){
		vector<int> num;
		vector<vector<int> > result;
		REQUIRE(s.fourSum(num, 0) == result);
	}
	SECTION("Normal Vector"){
		int S[6] = {1, 0, -1, 0, -2, 2};
		vector<int> num(S,S+6);
		vector<int> temp(4,0);
		vector<vector<int> > result(3,temp);
		result[0][0] = -1;
		result[0][3] = 1;
		result[1][0] = -2;
		result[1][1] = -1;
		result[1][2] = 1;
		result[1][3] = 2;
		result[2][0] = -2;
		result[2][3] = 2;
		sort(result.begin(), result.end());
		REQUIRE(s.fourSum(num,0) == result);
	}
}