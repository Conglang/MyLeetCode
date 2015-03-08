//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/*
*	判断三点是否在一条直线，可以看任意两个点组成的斜率是否相同。
*	最小的时间复杂度只能是O(n^2)，因为必须计算任意两个点之间的斜率。
*	选取任意一点A，计算其他所有点和点A的斜率，只有三种情况。
*	1. 某点和A点在同一坐标。
*	2. 某点和A点x轴坐标相同，得到一个正无穷的斜率。
*	3. 通常情况。计算斜率。
*	将斜率存在一个哈希表里。于是可以遍历得到过点A相同斜率通过的点有哪些。
*	同样计算B、C，得到的最大值就是结果。
*/
// 时间复杂度O(n^2)，空间复杂度O(n)。
/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.empty()) return 0;
        int max_point(0);
        unordered_map<double, int> slopes;
        for (auto ita = points.begin(); ita != points.end(); ++ita)
        {
            int same_point(1);
            slopes.clear();
            auto pa = *ita;
            for (auto itb = ita+1; itb != points.end(); ++itb)
            {
                auto pb = *itb;
                if (pb.x == pa.x && pb.y == pa.y) {++same_point;}
                else if (pb.x == pa.x) {++slopes[INT_MAX];}
                else {++slopes[double(pb.y-pa.y) / double(pb.x-pa.x)];}
            }
            int local_max(0);
            for_each(slopes.begin(), slopes.end(), [&](pair<double,int> apair){local_max = max(local_max, apair.second);});
            local_max += same_point;
            max_point = max(max_point, local_max);
        }
        return max_point;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Max_Points_on_a_Line", "[Brute Force]"){
	Solution sln;
	vector<Point> points;
	SECTION("Empty Input") {
		REQUIRE(sln.maxPoints(points) == 0);
	}
	SECTION("Normal Input1") {
		Point a(0,0),b(0,0);
		points.push_back(a);
		points.push_back(b);
		REQUIRE(sln.maxPoints(points) == 2);
	}
	SECTION("Normal Input2") {
		Point ps[9] = {Point(84,250), Point(0,0), Point(1,0), Point(0,-70), Point(0,-70), Point(1,-1), Point(21,10), Point(42,90), Point(-42,-230)};
		points.assign(ps,ps+9);
		REQUIRE(sln.maxPoints(points) == 6);
	}
}