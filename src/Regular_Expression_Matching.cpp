//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Implement regular expression matching with support for '.' and '*'.
* 
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* 
* The matching should cover the entire input string (not partial).
* 
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* 
* Some examples:
* isMatch("aa","a") �� false
* isMatch("aa","aa") �� true
* isMatch("aaa","aa") �� false
* isMatch("aa", "a*") �� true
* isMatch("aa", ".*") �� true
* isMatch("ab", ".*") �� true
* isMatch("aab", "c*a*b") �� true
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// �õݹ�ķ�����
// �����һλ����*�Ļ��������Ƚϣ�˫˫���е���һ����
// �����һλ��*��Ҫ�ľ�s�����к�p*֮ǰ�ַ�һ���������ַ���Ȼ���ٽ���һ����һ���ĺ�p*֮����ַ��Ƚϡ�
// ��Ϊ*��ʾ�����������Ҳ������0����������һ����*��ʱ�򣬵�ǰp�ַ���s�ַ���һ�����Ƿ�������
class Solution {
public:
	bool isMatch(const char *s, const char *p) {
		if (*p == '\0') {return *s == '\0';}

		// next char is not '*', then must match current character
		if (*(p+1) != '*')
		{
			if (*p == *s || (*p == '.' && *s != '\0'))
			{
				return isMatch(s+1, p+1);
			}else {return false;}
		}else // next char is '*'
		{
			while (*p == *s || (*p == '.' && *s != '\0'))
			{
				if (isMatch(s, p+2))	// ȥ����ǰ����ظ�s��ʣ�µ�s��p��*֮����ַ������ƥ�䣬�Ǿ���ƥ���ˡ�
				{
					return true;
				}
				++s;	// ûƥ���ϣ���ȥһ���ظ�s��
			}
			return isMatch(s, p+2);	// �ظ��Ķ�ȥ�ˣ��ٱȽ�ʣ�µ�s��p��*֮����ַ�����
		}
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Regular_Expression_Matching", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.isMatch("","") == true);
		REQUIRE(s.isMatch("a","") == false);
	}
	SECTION("Normal Input"){
		REQUIRE(s.isMatch("aa","a") == false);
		REQUIRE(s.isMatch("aa","aa") == true);
		REQUIRE(s.isMatch("aaa","aa") == false);
		REQUIRE(s.isMatch("aa","a*") == true);
		REQUIRE(s.isMatch("aa",".*") == true);
		REQUIRE(s.isMatch("ab",".*") == true);
		REQUIRE(s.isMatch("aab","c*a*b") == true);
		REQUIRE(s.isMatch("kkkkb","k*kabc") == false);
		REQUIRE(s.isMatch("kkkkabc","k*kabc") == true);
	}
}