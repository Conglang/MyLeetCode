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
// ��ǰһ��Word_Break�Ļ����ϣ����Ӽ�¼���п�����������顣
class Solution {
public:
	vector<string> wordBreak2(string s, unordered_set<string> &dict) {
		vector<string> result;
		if(s.empty()) return result;
		vector<bool> f(s.size()+1, false);	// 0Ϊ��ʱ��1~size��Ӧ�ַ���s��
		// valid_range[j][i]Ϊtrue����ʾs[j,i)��һ���Ϸ����ʣ����Դ�j���п���
		// ��һ��û���á�
		vector<vector<bool> > valid_range(s.size(), vector<bool>(s.size()+1));

		f[0] = true;
		for (size_t i = 1; i <= s.size(); ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (f[j] && dict.find(s.substr(j, i-j)) != dict.end())
				{
					f[i] = true;
					valid_range[j][i] = true;	// ��¼�������䡣
				}
			}
		}
		vector<string> path;
		generate_path(s, valid_range, s.size(), path, result);
		return result;
	}
private:
	// DFS��������·����
	void generate_path(string s, const vector<vector<bool> >& valid_range, int cur, vector<string>& path, vector<string>& result)
	{
		// ���ַ���ĩβ���������ַ����ס�
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
				generate_path(s, valid_range, i, path, result);	// �ݹ�ȥǰһ�����е��ʡ�
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