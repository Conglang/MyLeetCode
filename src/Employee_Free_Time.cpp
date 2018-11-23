//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/24
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* We are given a list schedule of employees, which represents the working time for each employee.
* 
* Each employee has a list of non-overlapping Intervals, and these intervals are in sorted order.
* 
* Return the list of finite intervals representing common, positive-length free time for all employees, also in sorted order.
* 
* Example 1:
* Input: schedule = [[[1,2],[5,6]],[[1,3]],[[4,10]]]
* Output: [[3,4]]
* Explanation:
* There are a total of three employees, and all common
* free time intervals would be [-inf, 1], [3, 4], [10, inf].
* We discard any intervals that contain inf as they aren't finite.
*  
* 
* Example 2:
* Input: schedule = [[[1,3],[6,7]],[[2,4]],[[2,5],[9,12]]]
* Output: [[5,6],[7,9]]
*  
* 
* (Even though we are representing Intervals in the form [x, y], the objects inside are Intervals, not lists or arrays. For example, schedule[0][0].start = 1, schedule[0][0].end = 2, and schedule[0][0][0] is not defined.)
* 
* Also, we wouldn't include intervals like [5, 5] in our answer, as they have zero length.
* 
* Note:
* 1. schedule and schedule[i] are lists with lengths in range [1, 50].
* 2. 0 <= schedule[i].start < schedule[i].end <= 10^8.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

// 先对所有区间按start排序，然后遍历。比较之间记录的end和当前Interval的start就可以。

class Solution {
public:
    vector<Interval> employeeFreeTime(vector<vector<Interval>>& schedule) {
        vector<Interval> time_spans;
        vector<Interval> result;
        
        for (auto vec : schedule) {
            time_spans.insert(time_spans.end(), vec.begin(), vec.end());
        }
        sort(time_spans.begin(), time_spans.end(), [](Interval a, Interval b){return (a.start < b.start) || (a.start == b.start && a.end < b.end);});
        
        int end(time_spans[0].end);
        for (auto span : time_spans) {
            if (span.start > end) {
                result.push_back(Interval(end, span.start));
            }
            end = max(end, span.end);
        }
        
        return result;
    }
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Employee_Free_Time", "[Detail]"){
	Solution s;
	SECTION("Normal Input") {
        vector<vector<Interval>> schedule1 = {{{1,2},{5,6}},{{1,3}},{{4,10}}};   // [[3,4]]
        vector<vector<Interval>> schedule2 = {{{1,3},{6,7}},{{2,4}},{{2,5},{9,12}}};    // [[5,6],[7,9]]
        vector<Interval> result1 = s.employeeFreeTime(schedule1);
        vector<Interval> result2 = s.employeeFreeTime(schedule2);
        string res1, res2;
        for_each(result1.begin(), result1.end(), [&res1](auto interval){res1 += interval.serialize();});
        for_each(result2.begin(), result2.end(), [&res2](auto interval){res2 += interval.serialize();});
		REQUIRE(res1 == "[3,4]");
        REQUIRE(res2 == "[5,6][7,9]");
	}
}