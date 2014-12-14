//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way 1
// 深度优先搜索。时间复杂度O(2^n)，空间复杂度O(n)
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string> > result;
		vector<string> path;
		DFS(s, path, result, 0);
		return result;
	}

	void DFS(string &s, vector<string> &path, vector<vector<string> > &result, int start)
	{
		if (start == s.size())
		{
			result.push_back(path);
			return;
		}
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

// Learned Way 2
// 动态规划，时间复杂度O(n^2)，空间复杂度O(1)
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
				if (is_valid[i][j])
				{
					const string palindrome = s.substr(i, j - i + 1);
					if (j + 1 < n)
					{
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