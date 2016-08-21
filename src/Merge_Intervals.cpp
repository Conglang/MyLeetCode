//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a collection of intervals, merge all overlapping intervals.
* 
* For example,
* Given [1,3],[2,6],[8,10],[15,18],
* return [1,6],[8,10],[15,18].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& ins) {
        if (ins.empty()) return vector<Interval>();
        vector<Interval> res;
        sort(ins.begin(), ins.end(), [](Interval a, Interval b){return a.start < b.start;});
        res.push_back(ins[0]);
        for (int i = 1; i < ins.size(); i++)
        {
            if (res.back().end < ins[i].start)
                res.push_back(ins[i]);
            else
                res.back().end = max(res.back().end, ins[i].end);
        }
        return res;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Merge_Intervals", "[Sorting]"){
	Solution s;
	SECTION("Normal Input1"){
		Interval t[4] = {Interval(1,3), Interval(2,6), Interval(8,10), Interval(15,18)};
		vector<Interval> input(t, t+4);
		vector<Interval> output(s.merge(input));
		int s[6] = {1,6,8,10,15,18};
		vector<int> should(s, s+6);
		vector<int> result;
		for (int i = 0; i < output.size(); ++i)
		{
			result.push_back(output[i].start);
			result.push_back(output[i].end);
		}
		REQUIRE(result == should);
	}
	SECTION("Normal Input2"){
		Interval t[2] = {Interval(1,4), Interval(4,5)};
		vector<Interval> input(t, t+2);
		vector<Interval> output(s.merge(input));
		int s[2] = {1,5};
		vector<int> should(s, s+2);
		vector<int> result;
		for (int i = 0; i < output.size(); ++i)
		{
			result.push_back(output[i].start);
			result.push_back(output[i].end);
		}
		REQUIRE(result == should);
	}
}
