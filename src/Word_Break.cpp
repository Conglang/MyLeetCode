//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string s and a dictionary of words dict, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
* 
* For example, given
* s = "leetcode",
* dict = ["leet", "code"].
* 
* Return true because "leetcode" can be segmented as "leet code".
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// ��̬�滮��ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)��
class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		if(s.empty()) return false;
		vector<bool> f(s.size()+1, false);	// 0Ϊ��ʱ��1~size��Ӧ�ַ���s��
		f[0] = true;	// ��ʼ״̬��ǰ���ǿ��д�(��)��
		for (int i = 1; i <= s.size(); ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (f[j] && dict.find(s.substr(j, i-j)) != dict.end())	// jǰ�Ƿ��ǿ��дʣ�j~i����ַ����Ƿ��ǵ��ʡ����ǲ��ܹ�����һ�����дʡ�
				{
					f[i] = true;
					break;
				}
			}
		}
		return f[s.size()];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Word_Break", "[Dynamic Programming]"){
	Solution sln;
	unordered_set<string> dict;
	dict.insert("leet");
	dict.insert("code");
	SECTION("Empty Input") {
		REQUIRE(sln.wordBreak("", dict) == false);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.wordBreak("leetcode", dict) == true);
		REQUIRE(sln.wordBreak("leecode", dict) == false);
	}
}