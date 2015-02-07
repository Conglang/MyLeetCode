//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/9
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
* 
* For example, given array S = {-1 2 1 -4}, and target = 1.
* 
* The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 时间复杂度O(n^2)，空间复杂度O(1)。
// 先排序，通过遍历让三个数求和变成两个数求和，然后从两侧向中间逼近。
class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		if (num.size() < 3) {return 0;}
		if (num.size() == 3) {return num[0]+num[1]+num[2];}
		sort(num.begin(), num.end());
		int close_sum(num[0]+num[1]+num[2]);
		for (auto a = num.begin(); a < prev(num.end(), 2);)
		{
			auto b = next(a);
			auto c = prev(num.end());
			while (b < c)
			{
				int sum = *a + *b + *c;
				if (abs(sum - target) < abs(close_sum - target))
				{
					close_sum = sum;
				}
				if (sum < target)
				{
					do{++b;} while(b < c && *(b-1) == *b);
				}else
				{
					do{--c;} while(b < c && *(c+1) == *b);
				}
			}
			do{++a;} while(a < num.end()-1 && *(a-1) == *a);
		}
		return close_sum;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("3Sum_Closest", "[Arrays]"){
	Solution s;
	SECTION("Empty Vector"){
		vector<int> num;
		REQUIRE(s.threeSumClosest(num, 0) == 0);
	}
	SECTION("Normal Vector"){
		int S[4] = {-1, 2, 1, -4};
		vector<int> num(S,S+4);
		REQUIRE(s.threeSumClosest(num,1) == 2);
	}
}