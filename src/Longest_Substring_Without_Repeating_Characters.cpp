//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string, find the length of the longest substring without repeating characters.
* For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
* which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 记录每段可行字符的start和cur，每次遇到重复时，start就置为该重复字符上一次出现处的后一个位置。
// 如果不用start和cur两个来管理，而是每次返回前面位置重新处理的话会超时，应当重复利用之前判断过的非重字符串的成果。
// 时间复杂度O(n)，空间复杂度O(n)。
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_len(0);	// 最大长度
		string processed_str;	// 记录之前不重复的字符们，用来辨认当前字符是否出现过。
		vector <int> processed_pos;	// 记录之前不重复字符们出现的位置，与前一变量在顺序上一一对应。
		int start(0),cur(0);	// 此不重复字符串的起始位置和当前位置。

		int count(0);	// 本轮字符串未重复的长度。
		while (cur < s.size())
		{
			if (processed_str.find(s.at(cur)) == string::npos)	// 如果该字符没有出现过，增加计数。
			{
				++count;
			}else	// 如果该字符已经出现过。
			{
				max_len = max(max_len, count);	// 比较之前子串是否是目前最大长度。
				// 得到新的起始位置，就是重复的字符上一次出现的位置加1。
				int new_start = processed_pos[processed_str.find(s.at(cur))] + 1;
				// 删掉新位置之前的重复字符和位置记录。它们不应该影响下一轮子串验证。
				processed_str = processed_str.substr(new_start-start);
				processed_pos.erase(processed_pos.begin(), next(processed_pos.begin(),new_start-start));
				// 记录新位置。
				start = new_start;
				// 计算从新位置到当前位置子串的长度。
				count = cur - new_start + 1;
			}
			// 每次将当前字符和位置存起来。
			processed_str.push_back(s.at(cur));	
			processed_pos.push_back(cur);
			// cur保证不回退，总是向后处理。
			++cur;
		}
		max_len = max(max_len, count);
		return max_len;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Longest_Substring_Without_Repeating_Characters", "[]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.lengthOfLongestSubstring("") == 0);
	}
	SECTION("Normal Input1") {
		REQUIRE(sln.lengthOfLongestSubstring("dyig") == 4);
	}
	SECTION("Normal Input2") {
		REQUIRE(sln.lengthOfLongestSubstring("advdf") == 3);
	}
	SECTION("Normal Input3") {
		REQUIRE(sln.lengthOfLongestSubstring("eee") == 1);
	}
}