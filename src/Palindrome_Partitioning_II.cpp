//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string s, partition s such that every substring of the partition is a palindrome.
* 
* Return the minimum cuts needed for a palindrome partitioning of s.
* 
* For example, given s = "aab",
* Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/*
*	定义状态f(i, j)表示区间[i, j]之间最小的cut数，则状态转移方程为：
*	f(i, j) = min {f(i, k) + f(k + 1, j)}, i <=k<=j, 0 <=i<=j<n
*	转换成一维DP。如果每次从i向右扫描，每找到一个回文就算一次DP，那么i~j之间有一个回文，那么上式转换为：
*	f(i) = min{f(j+1)+1}, i<=j<n
*	其中f(i) = 区间[i, n-1]之间最小的cut数，n为字符串长度。
*	那么如何判断[i, j]是否是回文？
*	还是用DP的思路。
*	定义状态P[i][j] = true，如果[i, j]为回文，那么
*	P[i][j] = str[i] == str[j] && P[i+1][j-1]
*/
// 时间复杂度O(n^2)，空间复杂度O(n^2)
class Solution {
public:
	int minCut(string s) {
		if(s.empty()) return 0;
		const int n(s.size());
#if __cplusplus < 201103L
		vector<int> f(n+1,0);
		vector<bool> temp(n,false);
		vector<vector<bool> > p(n, temp);
#else
		int f[n+1];	// 记录从i~n-1之间字符串的最小cut数。
		bool p[n][n];	// 用于判断i~j之间是否为回文串。
		fill_n(&p[0][0], n * n, false);	// 初始全部置为否，即不是回文串。
#endif
		// 初始置为最坏情况，即每个字符后都需要切割。
		for (int i = 0; i <= n; ++i)
		{
			f[i] = n - 1 - i;   // 最后一个f[n]=-1
		}
		// 从右向左依次移动子字符串首。
		for (int i = n - 1; i >=0; --i)
		{
			// 从子字符串首向右移动到字符串尾。
			for (int j = i; j < n; ++j)
			{
				// 如果从i到j是一个回文串，增加一个f的DP分量。
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
				{
					p[i][j] = true;
					f[i] = min(f[i], f[j + 1] + 1);
				}
			}
		}
		return f[0];	// 返回从0~n-1的最小切割值。
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Palindrome_Partitioning_II", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.minCut("") == 0);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.minCut("aab") == 1);
	}
}