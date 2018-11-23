//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Write a function that takes a string as input and reverse only the vowels of a string.
* 
* Example 1:
* Given s = "hello", return "holle".
* 
* Example 2:
* Given s = "leetcode", return "leotcede".
* 
* Note:
* The vowels does not include the letter "y".
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)
// Two Pointers，类似快排的方法。
class Solution {
public:
    string reverseVowels(string s) {
        if (s.size() < 2) return s;
        int left(0), right(s.size()-1);
        string vowels("aeiouAEIOU");
        while (left <= right)
        {
            while(left <= right && vowels.find_first_of(s[left]) == string::npos) {++left;}
            while(left <= right && vowels.find_first_of(s[right]) == string::npos) {--right;}
            if (left <= right)
            {
                swap(s, left, right);
                ++left;
                --right;
            }
        }
        return s;
    }
private:
    void swap(string& s, int p1, int p2)
    {
        if (p1 == p2) return;
        char t = s[p1];
        s[p1] = s[p2];
        s[p2] = t;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Reverse_Vowels_of_a_String", "[Strings]"){
	Solution s;
	SECTION("Invalid Input"){
		REQUIRE(s.reverseVowels("") == "");
		REQUIRE(s.reverseVowels("a") == "a");
		REQUIRE(s.reverseVowels("b") == "b");
	}
	SECTION("Normal Input"){
		REQUIRE(s.reverseVowels("hello") == "holle");
		REQUIRE(s.reverseVowels("Aa") == "aA");
		REQUIRE(s.reverseVowels("a.") == "a.");
	}
}
