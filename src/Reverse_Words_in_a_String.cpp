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
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
// �Ƚ������ַ�����ת����ȥ������Ŀո��ٽ�ÿ���������η�ת��
class Solution {
public:
	void reverseWords(string &s) {
		if (s.empty()) return;
		int n = s.size();
		int i(0), j(n-1);
		// �������ַ���ת��
		reverse(s.begin(), s.end());
		// ȥ���ַ���β�����пո�
		while (j >= 0 && s[j] == ' ')
		{
			--j; --n;
		}
		// ȥ�������ո�
		int pos(0);
		while (i < n)
		{
			if (s[i] == ' ') {++i; continue;}   // ���������ո񣬲��ܡ�
			if (pos != 0) {s[pos++] = ' ';} // ���������ǿո�������ѭ�������ո��ĵ�һ���ַ������һ���ո�
			while (i < n && s[i] != ' ') {s[pos++] = s[i++];}   // ����ѭ���н�������������ʸ��Ƶ���ȷλ���ϡ�
		}
		s.resize(pos);  // ɾ��ĩβ���ò��֡�
		// ��תÿ�����ʡ�
		i = 0;
		int last_space(-1);
		while (i < pos)
		{
			if (s[i] == ' ')    // �����ո񣬽�֮ǰ���ʷ�ת��
			{
				auto starti = s.begin() + (last_space + 1);
				reverse(starti, s.begin()+i);
				last_space = i;
			}else if (i == pos-1)   // ��ת���һ�����ʡ�
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