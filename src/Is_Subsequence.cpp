//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string s and a string t, check if s is subsequence of t.
* 
* You may assume that there is only lower case English letters in both s and t.
* t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
* 
* A subsequence of a string is a new string which is formed from the original string by deleting some
* (can be none) of the characters without disturbing the relative positions of the remaining characters.
* (ie, "ace" is a subsequence of "abcde" while "aec" is not).
* 
* Example 1:
* s = "abc", t = "ahbgdc"
* 
* Return true.
* 
* Example 2:
* s = "axc", t = "ahbgdc"
* 
* Return false.
* 
* Follow up:
* If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B,
* and you want to check one by one to see if T has its subsequence.
* In this scenario, how would you change your code?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/57151/3-lines-c
// t每次向前一位，如果和s相同s就也向前一位。
// 最终t走完的时候，如果s到了末尾，说明s里的都匹配上了，不然就是没有。
class Solution {
public:
	bool isSubsequence(string s, string t) {
		auto i = s.begin();
		//for(char c : t) i += (*i == c);
		for (auto it = t.begin(); it != t.end(); ++it)
		{
			char c = *it;
			i += (*i == c);
		}
		return i == s.end();
	}
};
// Follow up O(len(t) * k)
/*
class Solution {
public:
    vector<bool> isSubsequence(vector<string> ss, string t) {
    	vector<string::const_iterator> iters(ss.size());
    	for(int i = 0; i < ss.size(); i++) {
    		iters[i] = ss[i].begin();
    	}
        for(char c : t) {
        	for(int i = 0; i < ss.size(); i++) {
        		iters[i] += *iters[i] == c;
        	}
        }
        vector<bool> ans(ss.size());
        for(int i = 0; i < ss.size(); i++) {
        	ans[i] = iters[i] == ss[i].end();
        }
        return ans;
    }
};
*/
// Follow up Faster O(len(t) + sum(len(s[i])))
/*
vector<bool> isSubsequence(vector<string> ss, string t) {
	vector<string::const_iterator> iters(ss.size());
	vector<vector<int> > waitingList(26);
	int unfinished = ss.size();
	for(int i = 0; i < ss.size(); i++) {
		iters[i] = ss[i].begin();
		if(iters[i] != ss[i].end()) waitingList[*iters[i] - 'a'].push_back(i);
	}
	for(char c : t) {
		vector<int> updateList = waitingList[c - 'a'];
		waitingList[c - 'a'].clear();
		for(int i : updateList) {
			iters[i]++;
			if(iters[i] != ss[i].end()) waitingList[*iters[i] - 'a'].push_back(i);
			else unfinished--;
		}
		if(unfinished == 0) break;
	}
	vector<bool> ans(ss.size());
	for(int i = 0; i < ss.size(); i++) {
		ans[i] = iters[i] == ss[i].end();
	}
	return ans;
}
*/
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Is_Subsequence", "[Binary_Search]"){
	Solution s;
	SECTION("Normal Input"){
		REQUIRE(s.isSubsequence("abc", "ahbgdc") == true);
		REQUIRE(s.isSubsequence("axc", "ahbgdc") == false);
	}
}