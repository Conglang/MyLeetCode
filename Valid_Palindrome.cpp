//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
//--------------------------------------------------------------------------------------------------------------*/

// My Way
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