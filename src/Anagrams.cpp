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
Anagram�����Ĺ��ʷ�����ָ������ĸ˳��Ӷ��õ��µĵ��ʣ�����"dormitory"������ĸ˳
�����"dirty room"��"tea" ����"eat"��
���Ĺ��ʷ���һ���ص㣺���������ĸ���������Ŀû�иı䣬ֻ�Ǹı�����ĸ������˳��
��ˣ����������ʰ�����ĸ˳���������������ȣ�����������ͬһ��anagrams��
*/

// My Way
// ÿ��string�������Ϊkey���Լ�������Ϊvalue��д�뵽һ����ϣ���
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