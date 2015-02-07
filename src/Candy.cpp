//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/13
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 两者的核心思想都是从左到右，从右到左各扫描一次。
// 去两次值大的那一个。
// 迭代法
class Solution {
public:
	int candy(vector<int> &ratings) {
		const int n = ratings.size();
		vector<int> increment(n);
		for (int i = 0, inc = 1; i < n; ++i)
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
		return accumulate(increment.begin(), increment.end(), n);
	}
};

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