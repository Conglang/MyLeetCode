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

// 时间复杂度O(n*m)，空间复杂度O(1)
// 蛮力字符串匹配。先知道两者的长度才能在后面查找的时候做终止优化。
class Solution {
public:
	int strStr(char *haystack, char *needle) {
		if (!needle) {return 0;}
		if (!haystack) {return -1;}
		// 先得到haystack和needle的长度
		int haystack_len(0);
		int needle_len(0);
		while (needle[needle_len]){++needle_len;}
		while (haystack[haystack_len]){++haystack_len;}

		if (!needle_len) {return 0;}
		if (!haystack_len) {return -1;}
		// 蛮力查找匹配
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
