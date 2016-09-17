//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string s and a dictionary of words dict, add spaces in s to construct a sentence where each word
* is a valid dictionary word.
* 
* Return all such possible sentences.
* 
* For example, given
* s = "catsanddog",
* dict = ["cat", "cats", "and", "sand", "dog"].
* 
* A solution is ["cats and dog", "cat sand dog"].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 在前一题Word_Break的基础上，增加记录所有可行区间的数组。
class Solution {
public:
	vector<string> wordBreak2(string s, unordered_set<string> &dict) {
		vector<string> result;
		if(s.empty()) return result;
		vector<bool> f(s.size()+1, false);	// 0为空时，1~size对应字符串s。
		// valid_range[j][i]为true，表示s[j,i)是一个合法单词，可以从j处切开。
		// 第一列没有用。
		vector<vector<bool> > valid_range(s.size(), vector<bool>(s.size()+1));

		f[0] = true;
		for (size_t i = 1; i <= s.size(); ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (f[j] && dict.find(s.substr(j, i-j)) != dict.end())
				{
					f[i] = true;
					valid_range[j][i] = true;	// 记录可行区间。
				}
			}
		}
		vector<string> path;
		generate_path(s, valid_range, s.size(), path, result);
		return result;
	}
private:
	// DFS遍历生成路径。
	void generate_path(string s, const vector<vector<bool> >& valid_range, int cur, vector<string>& path, vector<string>& result)
	{
		// 从字符串末尾遍历到了字符串首。
		if (cur == 0)
		{
			string temp;
			for_each(path.crbegin(), path.crend(), [&](string word){temp += word + " ";});
			temp.pop_back();
			result.push_back(temp);
		}
		for (size_t i = 0; i < cur; ++i)
		{
			if (valid_range[i][cur])
			{
				path.push_back(s.substr(i, cur-i));
				generate_path(s, valid_range, i, path, result);	// 递归去前一个可行单词。
				path.pop_back();
			}
		}
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Word_Break_II", "[Dynamic Programming]"){
	Solution sln;
	vector<string> result;
	unordered_set<string> dict;
	SECTION("Normal Input1") {
		REQUIRE(sln.wordBreak2("a", dict) == result);
	}
	SECTION("Normal Input2") {
		result.push_back("cat sand dog");
		result.push_back("cats and dog");
		dict.insert("cat");
		dict.insert("cats");
		dict.insert("and");
		dict.insert("sand");
		dict.insert("dog");
		REQUIRE(sln.wordBreak2("catsanddog", dict) == result);
	}
}