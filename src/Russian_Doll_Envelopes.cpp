//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/12
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* You have a number of envelopes with widths and heights given as a pair of integers (w, h). 
* One envelope can fit into another if and only if both the width and height of one envelope is 
* greater than the width and height of the other envelope.
* 
* What is the maximum number of envelopes can you Russian doll? (put one inside other)
* 
* Example:
* Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 
* ([2,3] => [5,4] => [6,7]).
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1
// Ref: https://discuss.leetcode.com/topic/54643/two-solutions-in-c-well-explained/2
#ifdef W1
// 是题目Longest_Increasing_Subsequence的延续
/*
Actually here we are counting the longest increasing sequence as well except there are two dimensions
we need to consider. And also we should remember the o(nlogn) solution in LIS,
where the essential greedy concept is trying to

make the all the elements in the collector as small as possible,
especially the last one which is the gate to control the size of the collector - the longest length;
append the bigger ones to the collector;
But here we need to make some modifications since there are two dimensions to consider.
To ensure the two dimensions array can be compressed into one dimension and meantime
the requirements of the two conditions above are also properly met, just sorting is not enough here.

we need to convert this 2-dimentsion problem to a 1-dimension LIS:
first sort the array via the width in ascending order and then sort the sub-array with the same width
in descending order (the height) then the two conditions in LIS will also be met traversing from
the smallest width to the biggest: and the height will be used as that in LIS - the last element
will be updated to be as smaller as possible and meantime maintain the envelopes constraint since
its width order will always be valid, furthermore the condition 2 is also met just as that in LIS.

Note if we do not sort the sub-arrays (with the same width) in descending order,
the LIS in the height is then invalid. Suppose the sub-arrays are also sorted in ascending order,
the height in the same width will be appended in our LIS method, wrong result.
To sort the heights in the same width in descending order will avoid this case by updating the height
in the same width since we are using lower_bound.

Time complexity now becomes O(nlogn) taking up O(n) space.
*/
class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		vector<int> res;
		sort(envelopes.begin(), envelopes.end(), [](pair<int, int> a, pair<int, int> b){return (a.first < b.first) || (a.first == b.first && a.second > b.second);});
		for (int i = 0; i < envelopes.size(); ++i)
		{
			auto pos = lower_bound(res.begin(), res.end(), envelopes[i].second);
			if(pos == res.end())
			{
				res.push_back(envelopes[i].second);
			}else if (*pos > envelopes[i].second)
			{
				*pos = envelopes[i].second;
			}
		}
		return res.size();
	}
};
#endif

#ifdef W2
/*
sorting the envelopes first via its first value (width)
allocating an array to record the maximal amount for each envelope
(the maximal amount we can get ending with the current envelope)
Directly the time cost here will be o(nlogn+n^2) which is o(n^2) and meantime taking up o(n) extra space.
*/
class Solution {
public:
	int maxEnvelopes(vector<pair<int, int>>& envelopes) 
	{
		int size = envelopes.size();
		if(!size) return 0;
		sort(envelopes.begin(), envelopes.end());
		int maxrolls[size]{0}, maxroll = 1;
		maxrolls[0] = 1;
		for(int i = 1; i < size; ++i)
		{
			maxrolls[i] = 1;
			for(int j = i-1; j >= 0; --j)
				if(envelopes[i].first>envelopes[j].first && envelopes[i].second>envelopes[j].second)
					maxrolls[i] = max(maxrolls[i], maxrolls[j]+1);
			maxroll = max(maxroll, maxrolls[i]);
		}
		return maxroll;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Russian_Doll_Envelopes", "[Binary_Search]"){
	Solution s;
	SECTION("Normal Input"){
		vector<pair<int, int>> envelope;
		envelope.push_back(make_pair(2,100));
		envelope.push_back(make_pair(3,200));
		envelope.push_back(make_pair(4,300));
		envelope.push_back(make_pair(5,500));
		envelope.push_back(make_pair(5,400));
		envelope.push_back(make_pair(5,250));
		envelope.push_back(make_pair(6,370));
		envelope.push_back(make_pair(6,360));
		envelope.push_back(make_pair(7,380));
		REQUIRE(s.maxEnvelopes(envelope) == 5);
	}
}