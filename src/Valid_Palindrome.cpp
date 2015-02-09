//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
* 
* For example,
* "A man, a plan, a canal: Panama" is a palindrome.
* "race a car" is not a palindrome.
* 
* Note:
* Have you consider that the string might be empty? This is a good question to ask during an interview.
* 
* For the purpose of this problem, we define empty string as valid palindrome.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
#define W2
#ifdef W1
// 时间复杂度O(n)，空间复杂度O(n)
// 提取有效字符，反转后再比较。不是最好的方法。
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) {return true;}
		string purified_str;
		for(size_t i = 0; i < s.length(); ++i)
		{
			if ((s[i] <= 'z' && s[i] >= 'a') || (s[i] <= '9' && s[i] >= '0'))
			{
				purified_str.push_back(s[i]);
			}
			if (s[i] <= 'Z' && s[i] >= 'A')
			{
				purified_str.push_back(s[i]|=32);
			}
		}
		string reversed_str = purified_str;
		std::reverse(reversed_str.begin(), reversed_str.end());
		if (purified_str == reversed_str) {return true;}
		return false;
	}
};
#endif

#ifdef W2
// 时间复杂度O(n)，空间复杂度O(1)。
// 先全部变为小写，然后两边向中间逼近比较。
class Solution {
public:
	bool isPalindrome(string s) {
		if (s.empty()) {return true;}
		transform(s.begin(), s.end(), s.begin(), tolower);
		string::iterator left = s.begin(), right = prev(s.end());
		while (left < right) {
			if (!::isalnum(*left)) ++left;
			else if (!::isalnum(*right)) --right;
			else if (*left != *right) return false;
			else{ ++left, --right; }
		}
		return true;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Valid_Palindrome", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.isPalindrome("") == true);
	}
	SECTION("Normal Input"){
		REQUIRE(s.isPalindrome("A man, a plan, a canal: Panama") == true);
		REQUIRE(s.isPalindrome("race a car") == false);
	}
}
