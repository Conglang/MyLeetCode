//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
* 
* For example,
* Given:
* s1 = "aabcc",
* s2 = "dbbca",
* 
* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1
#ifdef W1
/*
*	设状态f[i][j]，表示s1[0,i]和s2[0,j]，匹配s3[0, i+j]。
*	如果s1的最后一个字符等于s3的最后一个字符，则f[i][j]=f[i-1][j]；
*	如果s2的最后一个字符等于s3的最后一个字符，则f[i][j]=f[i][j-1]。
*	因此状态转移方程如下：
*	f[i][j] = (s1[i - 1] == s3 [i + j - 1] && f[i - 1][j]) || (s2[j - 1] == s3 [i + j - 1] && f[i][j - 1]);
*/
// 二维动规，时间复杂度 O(n^2)，空间复杂度O(n^2)。
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.length() != s1.length() + s2.length())
			return false;
		// 长度都比原字符串多一位是为了防止空字符串的情况。
		vector<vector<bool> > f(s1.length() + 1,
			vector<bool>(s2.length() + 1, true));
		// 预防s2为空。
		for (size_t i = 1; i <= s1.length(); ++i)
		{
			f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
		}
		// 预防s1为空。
		for (size_t i = 1; i <= s2.length(); ++i)
		{
			f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
		}
		// 动态规划计算，只有之前符合条件且本次也符合条件才符合条件。
		for (size_t i = 1; i <= s1.length(); ++i)
		{
			for (size_t j = 1; j <= s2.length(); ++j)
			{
				f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j])
					|| (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
			}
		}
		return f[s1.length()][s2.length()];
	}
};
#endif

#ifdef W2
// 二维动规 + 滚动数组，时间复杂度 O(n^2) ，空间复杂度 O(n)
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		if (s1.length() < s2.length())
			return isInterleave(s2, s1, s3);
		vector<bool> f(s2.length() + 1, true);
		for (size_t i = 1; i <= s2.length(); ++i)
			f[i] = s2[i - 1] == s3[i - 1] && f[i - 1];
		// 在第二个循环中用一个f[0]位置存储关于s1的信息。
		for (size_t i = 1; i <= s1.length(); ++i) {
			f[0] = s1[i - 1] == s3[i - 1] && f[0];
			for (size_t j = 1; j <= s2.length(); ++j)
				f[j] = (s1[i - 1] == s3[i + j - 1] && f[j])
				|| (s2[j - 1] == s3[i + j - 1] && f[j - 1]);
		}
		return f[s2.length()];
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Interleaving_String", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.isInterleave("","","") == true);
		REQUIRE(sln.isInterleave("a","","a") == true);
		REQUIRE(sln.isInterleave("a","b","a") == false);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.isInterleave("aabcc","dbbca","aadbbcbcac") == true);
		REQUIRE(sln.isInterleave("aabcc","dbbca","aadbbbaccc") == false);
	}
}