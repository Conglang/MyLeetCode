//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two strings s and t, write a function to determine if t is an anagram of s.
* 
* For example,
* s = "anagram", t = "nagaram", return true.
* s = "rat", t = "car", return false.
* 
* Note:
* You may assume the string contains only lowercase alphabets.
* 
* Follow up:
* What if the inputs contain unicode characters? How would you adapt your solution to such case?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1

#ifdef W1
// Sorting
// 时间复杂度O(nlogn)，空间复杂度O(1)
class Solution {
public:
    bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t) {return true;}
        return false;
    }
};
#endif

#ifdef W2
// Hash Table
// 时间复杂度O(n)，空间复杂度O(1)
// 为兼顾followup使用unordered_map，不然可以用只有26个字母的数组优化
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;
        unordered_map<char, int> map;
        for (int i = 0; i < s.size(); ++i)
        {
            ++map[s[i]];
        }
        for (int i = 0; i < t.size(); ++i)
        {
            --map[t[i]];
            if (map[t[i]] < 0)
                return false;
        }
        return true;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Valid_Anagram", "[Sorting]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.isAnagram("", "") == true);
		REQUIRE(s.isAnagram("s", "") == false);
		REQUIRE(s.isAnagram("anagram", "nagaram") == true);
		REQUIRE(s.isAnagram("rat", "car") == false);
	}
}
