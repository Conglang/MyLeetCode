//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way, 会Time Limit Exceeded
/*
动态规划，复杂度O(n^2)。设状态为f(i, j)，表示区间[i,j]是否为回文串，则状态转移方程为：
			true										, i = j
f(i,j) =	S[i] = S[j}							, j = i + 1
			S[i] = S[j] and f(i+1, j-1)	, j > i+1
*/
class Solution {
public:
	string longestPalindrome(string s) {
		const int n = s.size();
		bool f[n][n];
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

// TODO: https://oj.leetcode.com/discuss/15311/share-accepted-c-code-with-o-n-2-time-and-o-1-space