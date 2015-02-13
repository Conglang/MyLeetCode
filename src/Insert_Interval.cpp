//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/12
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
* 
* You may assume that the intervals were initially sorted according to their start times.
* 
* Example 1:
* Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
* 
* Example 2:
* Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
* 
* This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
#define W1
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
#ifdef W1
/*
*	从左向右依次合并。
*	如果自己的start也大于当前的end，向右不停留。
*	如果自己的end小于当前的start，完全不必向右了，也就是说左边的都已经合并处理完毕了，结束算法。
*	如果以上两个都不满足，说明此区间与自己有交叠之处，merge，取两者两端的最小最大值，继续向右。
*/
// 时间复杂度O(n)，空间复杂度O(1)。会超时。
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval>::iterator it = intervals.begin();
		while (it != intervals.end())
		{
			if (newInterval.end < it->start)
			{
				intervals.insert(it, newInterval);
				return intervals;
			}else if (newInterval.start > it->end)
			{
				it++;
				continue;
			}else
			{
				newInterval.start = min(newInterval.start, it->start);
				newInterval.end = max(newInterval.end, it->end);
				it = intervals.erase(it);
			}
		}
		intervals.insert(intervals.end(), newInterval);
		return intervals;
    }
};
#endif

#ifdef W2
#endif
//--------------------------------------------------------------------------------------------------------------
vector<int> change_to_int(vector<Interval> intervals)
{
	vector<int> result;
	for (auto it = intervals.begin(); it != intervals.end(); ++it)
	{
		result.push_back(it->start);
		result.push_back(it->end);
	}
	return result;
}
TEST_CASE("Insert_Interval", "[Detail]"){
	Solution sln;
	vector<Interval> intervals;
	vector<int> result;
	SECTION("Empty Input"){
		Interval newinterval(5,7);
		int res[2] = {5,7};
		result.assign(res, res+2);
		REQUIRE(change_to_int(sln.insert(intervals, newinterval)) == result);
	}
	SECTION("Normal Input1") {
		Interval temp[4] = {Interval(2,4), Interval(5,7), Interval(8,10), Interval(11,13)};
		intervals.assign(temp, temp+4);
		Interval newinterval(3,8);
		int res[4] = {2,10,11,13};
		result.assign(res, res+4);
		REQUIRE(change_to_int(sln.insert(intervals, newinterval)) == result);
	}
	SECTION("Normal Input2") {
		Interval temp(1,5);
		intervals.assign(1,temp);
		Interval newinterval(2,7);
		int res[2] = {1,7};
		result.assign(res, res+2);
		REQUIRE(change_to_int(sln.insert(intervals, newinterval)) == result);
	}
	SECTION("Normal Input3") {
		Interval temp[2] = {Interval(1,5), Interval(6,8)};
		intervals.assign(temp, temp+2);
		Interval newinterval(0,9);
		int res[2] = {0,9};
		result.assign(res, res+2);
		REQUIRE(change_to_int(sln.insert(intervals, newinterval)) == result);
	}
	SECTION("Normal Input4") {
		Interval temp[2] = {Interval(3,5), Interval(12,15)};
		intervals.assign(temp, temp+2);
		Interval newinterval(6,6);
		int res[6] = {3,5,6,6,12,15};
		result.assign(res, res+6);
		REQUIRE(change_to_int(sln.insert(intervals, newinterval)) == result);
	}
}