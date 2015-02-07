//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/9
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Note:
Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ¡Ü b ¡Ü c ¡Ü d)
The solution set must not contain duplicate quadruplets.
For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

A solution set is:
(-1,  0, 0, 1)
(-2, -1, 1, 2)
(-2,  0, 0, 2)
//--------------------------------------------------------------------------------------------------------------*/
// My Way
class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		if (num.size() < 4) {return result;}
		sort(num.begin(), num.end());

		for(auto a = num.begin(); a < prev(num.end(),3);)
		{
			for(auto d = prev(num.end()); d > a;)
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
						result.push_back({*a, *b, *c, *d});
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