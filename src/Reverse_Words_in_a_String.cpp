//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an input string, reverse the string word by word.
* 
* For example,
* Given s = "the sky is blue",
* return "blue is sky the".
* 
* Update (2015-02-12):
* For C programmers: Try to solve it in-place in O(1) space.
* 
* click to show clarification.
* 
* Clarification:
* What constitutes a word?
*	A sequence of non-space characters constitutes a word.
* Could the input string contain leading or trailing spaces?
*	Yes. However, your reversed string should not contain leading or trailing spaces.
* How about multiple spaces between two words?
*	Reduce them to a single space in the reversed string.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)。
// 先将整个字符串反转，再去掉多余的空格，再将每个单词依次反转。
class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty()) return;
		int n = s.size();
		int i(0), j(n-1);
		// 将整个字符翻转。
		reverse(s.begin(), s.end());
		// 去除字符串尾的所有空格。
		while (j >= 0 && s[j] == ' ')
		{
			--j; --n;
		}
		// 去除连续空格。
		int pos(0);
		while (i < n)
		{
			if (s[i] == ' ') {++i; continue;}   // 遍历遇到空格，不管。
			if (pos != 0) {s[pos++] = ' ';} // 遍历遇到非空格，且在外循环，即空格后的第一个字符。添加一个空格。
			while (i < n && s[i] != ' ') {s[pos++] = s[i++];}   // 在内循环中将后面的连续单词复制到正确位置上。
		}
		s.resize(pos);  // 删除末尾无用部分。
		// 翻转每个单词。
		i = 0;
		int last_space(-1);
		while (i < pos)
		{
			if (s[i] == ' ')    // 遇到空格，将之前单词翻转。
			{
				auto starti = s.begin() + (last_space + 1);
				reverse(starti, s.begin()+i);
				last_space = i;
			}else if (i == pos-1)   // 翻转最后一个单词。
			{
				auto starti = s.begin() + (last_space + 1);
				reverse(starti,s.end()); 
			}
			++i;
		}
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Reverse_Words_in_a_String", "[Strings]"){
	Solution sln;
	string str;
	SECTION("Empty Input") {
		sln.reverseWords(str);
		REQUIRE(str == "");
	}
	SECTION("Normal Input") {
		str = "    ";
		sln.reverseWords(str);
		REQUIRE(str == "");
		str = "sky";
		sln.reverseWords(str);
		REQUIRE(str == "sky");
		str = "  sky   ";
		sln.reverseWords(str);
		REQUIRE(str == "sky");
		str = "  sky  is  ";
		sln.reverseWords(str);
		REQUIRE(str == "is sky");
		str = "the sky is blue";
		sln.reverseWords(str);
		REQUIRE(str == "blue is sky the");
	}
}