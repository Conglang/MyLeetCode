//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string s, partition s such that every substring of the partition is a palindrome.
* 
* Return all possible palindrome partitioning of s.
* 
* For example, given s = "aab",
* Return
* 
*   [
*     ["aa","b"],
*     ["a","a","b"]
*   ]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1

#ifdef W1
// 深度优先搜索。时间复杂度O(2^n)，空间复杂度O(n)。
// 一个长度为n的字符串，有n-1个地方可以砍断，每个地方可断可不断，所以时间复杂度为O(2^{n-1})。
// 回溯法。从头开始遍历字符串，当经过的部分是可行的partition方案时，就递归处理其之后的字符串。
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string> > result;
		vector<string> path;	// 一个partition方案。
		DFS(s, path, result, 0);
		return result;
	}
	// 搜索必须以s[start]开头的partition方案。
	void DFS(string &s, vector<string> &path, vector<vector<string> > &result, int start)
	{
		if (start == s.size())	// 已经处理完整个字符串。
		{
			result.push_back(path);
			return;
		}
		// 对于每个位置，如果是可行的partition方案，就递归处理之后的位置。
		for (int i = start; i < s.size(); ++i)
		{
			if (is_palindrome(s, start, i))
			{
				path.push_back(s.substr(start, i-start+1));
				DFS(s, path, result, i+1);
				path.pop_back();
			}
		}
	}
	// 判断一段字符串是否是回文串。
	bool is_palindrome(const string &s, int start, int end)
	{
		while (start < end && s[start] == s[end])
		{
			++start;
			--end;
		}
		return start >=end;
	}
};
#endif

#ifdef W2
// 动态规划，时间复杂度O(n^2)，空间复杂度O(1)。
// 先用动态规划得到哪些区间是有效的回文串。
// 再根据这个信息还是用动态规划从右向左，每个回文串首处的集合是尾部后一位集合添加本回文串的集合。
// 要求得到的就是在位置0出的集合。
class Solution {
public:
	vector<vector<string>> partition(string s) {
		const int n(s.size());

		bool is_valid[n][n];    // whether s[i,j] is palindrome
		fill_n(&is_valid[0][0], n*n, false);

		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				is_valid[i][j] = s[i] == s[j] && ((j - i < 2) || is_valid[i + 1][j - 1]);
			}
		}

		vector<vector<string> > sub_palis[n];   // sub palindromes of s[0, i]
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				// 对于每个可行的回文串。
				if (is_valid[i][j])
				{
					const string palindrome = s.substr(i, j - i + 1);
					if (j + 1 < n)
					{
						// 本回文串起点i出的sub_palis[i]，是本回文串终点j后一位处sub_pailis[j+1]里的每一段添加本回文串。
						for (auto v : sub_palis[j + 1])
						{
							v.insert(v.begin(), palindrome);
							sub_palis[i].push_back(v);
						}
					}else
					{
						sub_palis[i].push_back(vector<string> {palindrome });
					}
				}
			}
		}
		return sub_palis[0];
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Palindrome_Partitioning", "[Depth-First Search]"){
	Solution sln;
	vector<vector<string> > result;
	SECTION("Empty Input") {
		result.push_back(vector<string>());
		REQUIRE(sln.partition("") == result);
	}
	SECTION("Normal Input") {
		string t1[2] = {"aa","b"};
		string t2[3] = {"a","a","b"};
		result.push_back(vector<string>(t2,t2+3));
		result.push_back(vector<string>(t1,t1+2));
		REQUIRE(sln.partition("aab") == result);
	}
}
