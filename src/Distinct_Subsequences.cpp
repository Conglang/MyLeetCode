//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string S and a string T, count the number of distinct subsequences of T in S.
* 
* A subsequence of a string is a new string which is formed from the original string by deleting some
* (can be none) of the characters without disturbing the relative positions of the remaining characters.
* (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
* 
* Here is an example:
* S = "rabbbit", T = "rabbit"
* 
* Return 3.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/*
动态规划。设状态为f(i,j)，表示T[0,j]在S[0,i]里出现的次数。
首先，无论S[i]和T[j]是否相等，若不使用S[i]，则f(i,j) = f(i-1,j);
若S[i] == T[j]，则可以使用S[i]，此时f(i,j) = f(i-1,j) + f(i-1,j-1)，即不使用的情况加上使用的情况。
*/
//二维动态规划+滚动数组。
// 时间复杂度O(mn)，空间复杂度O(n)。
class Solution {
public:
	int numDistinct(string S, string T) {
		vector<int> f(T.length()+1,0);	// 0为空时，1~length对应字符串T。
		f[0] = 1;
		for (int i = 0; i < S.size(); ++i)
		{
			for (int j = T.length()-1; j >= 0 ; --j)
			{
				f[j+1] += S[i] == T[j] ? f[j] : 0;
			}
		}
		return f[T.length()];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Distinct_Subsequences", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Normal Input") {
		REQUIRE(sln.numDistinct("rabbbit", "rabbit") == 3);
		REQUIRE(sln.numDistinct("haha", "hehe") == 0);
		REQUIRE(sln.numDistinct("abcde", "aec") == 0);
	}
}