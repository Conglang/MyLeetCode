//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S
* is 1000, and there exists one unique longest palindromic substring.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2

#ifdef W1
// 时间复杂度O(n^2)，空间复杂度O(n^2)
/*
* 动态规划，复杂度O(n^2)。设状态为f(i, j)，表示区间[i,j]是否为回文串，则状态转移方程为：
* 			true						, i = j
* f(i,j) =	S[i] = S[j}					, j = i + 1
* 			S[i] = S[j] and f(i+1, j-1)	, j > i+1
*/
class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return string();
		const int n = s.size();
		//bool f[n][n];
		bool f[255][255];
		fill_n(&f[0][0], n*n, false);

		size_t max_len = 1, start = 0;
		for (size_t i = 0; i < n; i++)
		{
			f[i][i] = true;
			for (size_t j = 0; j < i; j++)
			{
				f[j][i] = ((s[i] == s[j]) && (i - j < 2 || f[j+1][i-1]));
				if (f[j][i] && max_len < (i - j + 1))
				{
					max_len = i - j + 1;
					start = j;
				}
			}
		}
		return s.substr(start, max_len);
	}
};
#endif

#ifdef W2
// 时间复杂度O(n^2)，空间复杂度O(1)
// https://oj.leetcode.com/discuss/15311/share-accepted-c-code-with-o-n-2-time-and-o-1-space
/*
*	从1位置开始遍历，考虑自己是回文串中心或者自己和左边的是回文串中心两种情况。
*	如果第一步情况满足，就尽力向两边扩展到尽头或不是回文位置。
*	比较此时得到的回文串长度和之前的最大长度。
*/
class Solution
{
public:
	string longestPalindrome(const string& s)
	{
		if (s.empty()) return string();
		const size_t str_size = s.size();
		const size_t max_idx = str_size - 1;
		// i_start and i_end are the start location and end location of the longest palindrome substring in s.
		size_t i_start(0), i_end(0);
		for (size_t i = 1; i < str_size; ++i)
		{
			// start from s[1], since s[0] has already been stored by i_start and i_end.
			for (size_t offset = 0; offset < 2; ++offset)
			{
				// offset = 0: this palindrome centers on s[i]
				// offset = 1: this palindrome centers between s[i-1] and s[i]
				// cur_i0 and cur_i1 are the start and end location of current palindrome
				size_t cur_i0 = i - offset;
				bool end_of_pal = (s[cur_i0] != s[i]);
				size_t cur_i1 = end_of_pal ? cur_i0 : i;
				// p0 and p1 is the expanded start and end location of current palindrome
				size_t p0(cur_i0), p1(cur_i1);
				while (!end_of_pal)
				{
					cur_i0 = p0;
					cur_i1 = p1;	// execute palindrome range expansion
					p0 = cur_i0 - 1;
					p1 = cur_i1 + 1;	// prepare for next expansion
					end_of_pal = (cur_i0 <= 0) || (cur_i1 >= max_idx);	// determine whether expasion is possible
					if (!end_of_pal) {end_of_pal = (s[p0] != s[p1]);}
				}
				if (cur_i1 - cur_i0 > i_end - i_start)
				{
					//compare current palindrome substring length with the length of the longest one
					i_start = cur_i0;
					i_end = cur_i1;
				}
			}
 		}
		return s.substr(i_start, i_end - i_start + 1);
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Longest_Palindromic_Substring", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.longestPalindrome("") == "");
	}
	SECTION("Normal Input"){
		REQUIRE(s.longestPalindrome("ablistenetsildx") == "listenetsil");
		REQUIRE(s.longestPalindrome("sasdfwatchhctawsd") == "watchhctaw");
		REQUIRE(s.longestPalindrome("safagsd") == "afa");
		REQUIRE(s.longestPalindrome("abcde") == "a");
	}
}