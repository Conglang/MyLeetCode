//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/22
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
//--------------------------------------------------------------------------------------------------------------*/
/*
Anagram（回文构词法）是指打乱字母顺序从而得到新的单词，比如"dormitory"打乱字母顺
序会变成"dirty room"，"tea" 会变成"eat"。
回文构词法有一个特点：单词里的字母的种类和数目没有改变，只是改变了字母的排列顺序。
因此，将几个单词按照字母顺序排序后，若它们相等，则它们属于同一组anagrams。
*/

// My Way
// 每个string排序后作为key，自己自身作为value，写入到一个哈希表里。
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		unordered_map<string, vector<string> >  group;
		for (auto it = strs.cbegin(); it != strs.cend(); ++it)
		{
			string key = *it;
			sort(key.begin(), key.end());
			group[key].push_back(*it);
		}

		vector<string> result;
		for (auto it = group.cbegin(); it != group.cend(); ++it)
		{
			if (it->second.size() > 1)
			{
				result.insert(result.end(), it->second.begin(), it->second.end());
			}
		}
		return result;
	}
};