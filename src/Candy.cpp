//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/13
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* There are N children standing in a line. Each child is assigned a rating value.
* 
* You are giving candies to these children subjected to the following requirements:
* 
* Each child must have at least one candy.
* Children with a higher rating get more candies than their neighbors.
* What is the minimum candies you must give?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1

// 两者的核心思想都是从左到右，从右到左各扫描一次。
// 取两次值大的那一个。
// 时间复杂度O(n)，空间复杂度O(n)。

#ifdef W1
// 迭代法
class Solution {
public:
	int candy(vector<int> &ratings) {
		if(ratings.empty()) {return 0;}
		if (ratings.size() == 1) {return 1;}
		const int n = ratings.size();
		vector<int> increment(n);
		// 左右各扫一遍
		for (int i = 1, inc = 1; i < n; ++i)
		{
			if (ratings[i] > ratings[i-1])
			{
				increment[i] = max(inc++, increment[i]);
			}else
			{
				inc = 1;
			}
		}
		for (int i = n - 2, inc = 1; i >= 0; --i)
		{
			if (ratings[i] > ratings[i+1])
			{
				increment[i] = max(inc++, increment[i]);
			}else
			{
				inc = 1;
			}
		}
		// 初始值为n，因为每个小朋友至少一颗糖。
#if __cplusplus < 201103L
		int sum(n);
		for_each(increment.begin(), increment.end(), [&](int n){sum+=n;});
		return sum;
#else
		return accumulate(increment.begin(), increment.end(), n);
#endif
	}
};
#endif
#ifdef W2
// 递归法，会超时。
class Solution {
public:
	int candy(vector<int> &ratings) {
		vector<int> candies(ratings.size());
		int sum(0);
		for (int i = 0; i < ratings.size(); ++i)
		{
			sum += candy_for_i(ratings, candies, i); 
		}
		return sum;
	}
private:
	int candy_for_i(vector<int>& ratings, vector<int>& candies, int i)
	{
		if (candies[i] == 0)
		{
			candies[i] = 1;
		}
		if (i > 0 && ratings[i] > ratings[i-1])
		{
			candies[i] = max(candy_for_i(ratings, candies, i-1) + 1, candies[i]);
		}
		if (i < ratings.size() - 2 && ratings[i] > ratings[i+1])
		{
			candies[i] = max(candy_for_i(ratings, candies, i+1) + 1, candies[i]);
		}
		return candies[i];
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Candy", "[Arrays]"){
	Solution s;
	vector<int> ratings;
	SECTION("Empty"){
		REQUIRE(s.candy(ratings) == 0);
		ratings.push_back(1);
		REQUIRE(s.candy(ratings) == 1);
	}
	SECTION("Normal"){
		ratings.assign(2,1);
		REQUIRE(s.candy(ratings) == 2);
		int temp[10] = {1,2,3,1,1,1,1,2,2,1};
		ratings.assign(temp,temp+10);
		REQUIRE(s.candy(ratings) == 15);
	}
}