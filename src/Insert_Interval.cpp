//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/8/21
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
#include "../include/include.h"
#define W2
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
*	�����������κϲ��������Ľ���
*	����Լ���startҲ���ڵ�ǰ��end�����Ҳ�ͣ����
*	����Լ���endС�ڵ�ǰ��start����ȫ���������ˣ�Ҳ����˵��ߵĶ��Ѿ��ϲ���������ˣ������㷨��
*	������������������㣬˵�����������Լ��н���֮����merge��ȡ�������˵���С���ֵ���������ҡ�
*/
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��Ч�ʵ͡�
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
// ֱ�Ӳ���startӦ�õ�λ�ú�endӦ�õ�ֵ���޸ĺ�Ĩȥ�м��ظ���Ԫ�ء�
// ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(1)
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
		// ����start��ֵ��Ѱ���б���start��һ�����ڲ���start��λ��
        auto iter1 = upper_bound(intervals.begin(), intervals.end(), newInterval.start, compare);
        int pos;	// ʵ�ʲ���/�޸ĵ�λ��
		// �������λ����vector�ף�����ǰһ����endС��Ҫ�����start���Ͳ��뵽���λ��
        if(iter1 == intervals.begin() || (iter1-1)->end < newInterval.start)
		{
            pos = iter1 - intervals.begin();
            intervals.insert(iter1, newInterval);
			// ���ֻ��һ�����ѣ����Ѹ�posҲ���²����IntervalĿǰ�ǲ������ģ�û�����Ҳ����
            // intervals[pos].end = intervals[pos].start;
        }
        else	// ��֮��ǰһ����end��Ҫ�����start��˵�����ص�֮��������λ����ǰŲһλ
		{
            pos = iter1 - 1 - intervals.begin();
        }
		// ����end��ֵ��Ѱ���б���end��һ�����ڲ���end��λ��
        auto iter2 = upper_bound(intervals.begin(), intervals.end(), newInterval.end, compare);
		// ��Ҫ�޸ĵ�λ�õ�end��Ϊ���ҵ�λ��ǰһλ��end
        intervals[pos].end = max(newInterval.end, (iter2-1)->end);
		// ɾ���м����б����ǵ�������
        intervals.erase(intervals.begin()+pos+1, iter2);
        return intervals;
    }
    static bool compare(const int val, const Interval& a){
        return val < a.start;
    }
};
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
TEST_CASE("Insert_Interval", "[Sorting]"){
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