//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
* 
* Below is one possible representation of s1 = "great":
* 
*     great
*    /    \
*   gr    eat
*  / \    /  \
* g   r  e   at
*            / \
*           a   t
* To scramble the string, we may choose any non-leaf node and swap its two children.
* 
* For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
* 
*     rgeat
*    /    \
*   rg    eat
*  / \    /  \
* r   g  e   at
*            / \
*           a   t
* We say that "rgeat" is a scrambled string of "great".
* 
* Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
* 
*     rgtae
*    /    \
*   rg    tae
*  / \    /  \
* r   g  ta  e
*        / \
*       t   a
* We say that "rgtae" is a scrambled string of "great".
* 
* Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2
#ifdef W1
// LeetCode, Interleaving String
// 递归，会超时，仅用来帮助理解
// 时间复杂度O(n^6)，空间复杂度O(1)。
class Solution {
public:
	bool isScramble(string s1, string s2) {
		return isScramble(s1.begin(), s1.end(), s2.begin());
	}
private:
	typedef string::iterator Iterator;
	bool isScramble(Iterator first1, Iterator last1, Iterator first2) {
		auto length = distance(first1, last1);
		auto last2 = next(first2, length);
		if (length == 1) return *first1 == *first2;
		for (int i = 1; i < length; ++i)
			// 两个字符串分成A1A2和B1B2两部分，比较A1B1/A2B2或A1B2/A2B1组合。
			if ((isScramble(first1, first1 + i, first2)
				&& isScramble(first1 + i, last1, first2 + i))
				|| (isScramble(first1, first1 + i, last2 - i)
				&& isScramble(first1 + i, last1, first2)))
				return true;
		return false;
	}
};
#endif

#ifdef W2
// 动态规划。时间复杂度O(n^3)，空间复杂度O(n^3)。
/*
*	设状态为f[n][i][j]，表示长度为n，起点为s1[i]和起点为s2[j]两个字符串是否互为scramble，
*	则状态转移方程为：
*	f[n][i][j] = (f[k][i][j] && f[n-k)[i+k][j+k]) || (f[k][i][j+n-k] && f[n-k][i+k][j])
*/
class Solution {
public:
	bool isScramble(string s1, string s2) {
		if (s1.empty() && s2.empty()) return true;
		const int LEN = s1.size();
		if (LEN != s2.size()) return false;
		
		vector<vector<vector<bool> > > f(LEN+1,vector<vector<bool> >(LEN, vector<bool>(LEN, false)));
		
		for (int i = 0; i < LEN; ++i)
		{
			for (int j = 0; j < LEN; ++j)
			{
				f[1][i][j] = s1[i] == s2[j];
			}
		}
		
		for (int n = 1; n <= LEN; ++n)
		{
			for (int i = 0; i+n <= LEN; ++i)
			{
				for (int j = 0; j+n <= LEN; ++j)
				{
					for (int k = 1; k < n; ++k)
					{
						if ((f[k][i][j] && f[n-k][i+k][j+k]) || (f[k][i][j+n-k] && f[n-k][i+k][j]))
						{
							f[n][i][j] = true;
							break;
						}
					}
				}
			}
		}
		return f[LEN][0][0];
	}
};
#endif

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Scramble_String", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.isScramble("a","") == false);
		REQUIRE(sln.isScramble("","") == true);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.isScramble("rgeat","great") == true);
		REQUIRE(sln.isScramble("rgtae","great") == true);
	}
}