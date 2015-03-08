//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/3
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Implement strStr().
* 
* Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

// ʱ�临�Ӷ�O(n*m)���ռ临�Ӷ�O(1)
// �����ַ���ƥ�䡣��֪�����ߵĳ��Ȳ����ں�����ҵ�ʱ������ֹ�Ż���
class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (!needle) {return 0;}
		if (!haystack) {return -1;}
		// �ȵõ�haystack��needle�ĳ���
		int haystack_len(0);
		int needle_len(0);
		while (needle[needle_len]){++needle_len;}
		while (haystack[haystack_len]){++haystack_len;}

		if (!needle_len) {return 0;}
		if (!haystack_len) {return -1;}
		// ��������ƥ��
		for (int h_it = 0; h_it < haystack_len - needle_len + 1; ++h_it)
		{
			int n_it = 0;
			while (n_it < needle_len && needle[n_it] == haystack[h_it + n_it])
			{
				++n_it;
				if (n_it == needle_len)
				{
					return h_it;
				}
			}
		}
		return -1;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Implement_strStr()", "[Strings]"){
	Solution s;
	char haystack[] = "This problem can be solved by Horspool or Boyer-Moore or KMP.";
	char needle[] = "pool";
	char badneedle[] = "Smile";
	SECTION("Empty Input"){
		REQUIRE(s.strStr(NULL, NULL) == 0);
		REQUIRE(s.strStr(NULL, needle) == -1);
	}
	SECTION("Normal Input"){
		REQUIRE(s.strStr(haystack, needle) == 34);
		REQUIRE(s.strStr(haystack, badneedle) == -1);
	}
}
