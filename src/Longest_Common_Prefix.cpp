//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Write a function to find the longest common prefix string amongst an array of strings.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
#define W1
#ifdef W1
// 纵向扫描，从位置0开始，对每一个位置比较所有字符串，直到遇到一个不匹配
// 时间复杂度O(n1+n2+n3+...)，空间复杂度O(1)。
class Solution{
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.empty()) {return "";}
		for (int idx = 0; idx < strs[0].size(); ++idx)
		{
			for (int i = 1; i < strs.size(); ++i)
			{
				if (strs[i][idx] != strs[0][idx]) {return strs[0].substr(0,idx);}
			}
		}
		return strs[0];
	}
};
#endif
#ifdef W2
// 横向比较，每个字符串与第0个字符串，从左到右比较，直到遇到一个不匹配
// 时间复杂度O(n1+n2+n3+...)，空间复杂度O(1)。
class Solution
{
public:
	string longestCommonPrefix(vector<string> &strs) {
		if (strs.empty()) {return "";}
		for (int i = 1; i < strs.size(); ++i)
		{
			for (int idx = 0; idx < strs[0].size(); ++idx)
			{
				if (strs[i][idx] != strs[0][idx])	// 原来不会越界
				{return strs[0].substr(0, idx);}
			}
		}
		return strs[0];
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Longest_Common_Prefix", "[Strings]"){
	Solution s;
	vector<string> strs;
	SECTION("Empty Input"){
		REQUIRE(s.longestCommonPrefix(strs) == "");
		strs.push_back("");
		REQUIRE(s.longestCommonPrefix(strs) == "");
	}
	SECTION("Normal Input"){
		strs.push_back("abcdeq");
		strs.push_back("abcq");
		strs.push_back("abcdefq");
		REQUIRE(s.longestCommonPrefix(strs) == "abc");
		strs.clear();
		strs.push_back("abc");
		strs.push_back("abcdef");
		strs.push_back("abcdeq");
		REQUIRE(s.longestCommonPrefix(strs) == "abc");
	}
}