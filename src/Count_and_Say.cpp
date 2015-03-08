//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* The count-and-say sequence is the sequence of integers beginning as follows:
* 1, 11, 21, 1211, 111221, ...
* 
* 1 is read off as "one 1" or 11.
* 11 is read off as "two 1s" or 21.
* 21 is read off as "one 2, then one 1" or 1211.
* Given an integer n, generate the nth sequence.
* 
* Note: The sequence of integers will be represented as a string.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n^2)，空间复杂度O(n)
class Solution {
public:
	string countAndSay(int n) {
		if(n < 1) {return "";}
		string s("1");
		while (--n)	// 生成长为n的序列
			s = getNext(s);
		return s;
	}
	string getNext(const string &s) {
		stringstream ss;
		for (auto i = s.begin(); i != s.end(); ) {
			auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
			ss << distance(i, j) << *i;	// 到下次不同之间的距离和本值
			i = j;
		}
		return ss.str();
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Count_and_Say", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.countAndSay(0) == "");
		REQUIRE(s.countAndSay(-1) == "");
	}
	SECTION("Normal Input"){
		REQUIRE(s.countAndSay(1) == "1");
		REQUIRE(s.countAndSay(2) == "11");
		REQUIRE(s.countAndSay(3) == "21");
		REQUIRE(s.countAndSay(4) == "1211");
		REQUIRE(s.countAndSay(5) == "111221");
	}
}