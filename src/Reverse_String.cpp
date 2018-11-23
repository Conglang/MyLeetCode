//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/15
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Write a function that takes a string as input and returns the string reversed.
* 
* Example:
* Given s = "hello", return "olleh".
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n/2)，空间复杂度O(1)。
class Solution {
public:
    string reverseString(string s) {
        if (s.empty()) return s;
        string result(s);
        for (int i = 0; i < (s.size() >> 1); ++i)
        {
            swap(result, i, s.size()-i-1);
        }
        return result;
    }
private:
    void swap(string& s, int a, int b)
    {
        char t(s[a]);
        s[a] = s[b];
        s[b] = t;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Reverse_String", "[Arrays]"){
	Solution s;
	SECTION("Invalid Input"){
		REQUIRE(s.reverseString("") == "");
	}
	SECTION("Normal Input"){
		REQUIRE(s.reverseString("hello") == "olleh");
	}
}