//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2017/02/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string s, find the longest palindromic subsequence's length in s. 
* You may assume that the maximum length of s is 1000.
* 
* Example 1:
* Input:
* 
* "bbbab"
* Output:
* 4
* One possible longest palindromic subsequence is "bbbb".
* Example 2:
* Input:
* 
* "cbbd"
* Output:
* 2
* One possible longest palindromic subsequence is "bb".
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class Solution {
public:
	int longestPalindromeSubseq(string s) {
		// special cases
		const int n(s.size());
		if (n < 2) return 1;
		// initialize dp arrays
		vector<vector<int>> len_pal(n, vector<int>(n,0));
		for (int i = 0; i < n; ++i)
		{
			len_pal[i][i] = 1;
		}
		// len_pal[i, j] = if s[i]==s[j] then len_pal[i+1,j-1] + 2
		//               = else max(len_pal[i,j-1], len_pal[i+1,j])
		for (int i = n-1; i >= 0; --i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (i>=j) continue;
				if (s[i] == s[j])
				{
					len_pal[i][j] = max(len_pal[i][j], (i+1) > (j-1) ? 2 : len_pal[i+1][j-1] + 2);
				}else
				{
					len_pal[i][j] = max(len_pal[i][j], max((i>j-1 ? 1 : len_pal[i][j-1]), (i+1 > j ? 1 : len_pal[i+1][j])));
				}
			}
		}
		return len_pal[0][n-1];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Longest_Palindromic_Subsequence", "[Dynamic Programming]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.longestPalindromeSubseq("") == 1);
		REQUIRE(s.longestPalindromeSubseq("bbbab") == 4);
		REQUIRE(s.longestPalindromeSubseq("a") == 1);
		REQUIRE(s.longestPalindromeSubseq("ab") == 1);
		REQUIRE(s.longestPalindromeSubseq("aaa") == 3);
		REQUIRE(s.longestPalindromeSubseq("abba") == 4);
		REQUIRE(s.longestPalindromeSubseq("abbb") == 3);
		REQUIRE(s.longestPalindromeSubseq("abac") == 3);
		REQUIRE(s.longestPalindromeSubseq("abcdsfghiikl") == 2);
	}
}