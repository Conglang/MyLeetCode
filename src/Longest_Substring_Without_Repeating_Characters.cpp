//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string, find the length of the longest substring without repeating characters.
* For example, the longest substring without repeating letters for "abcabcbb" is "abc", 
* which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ��¼ÿ�ο����ַ���start��cur��ÿ�������ظ�ʱ��start����Ϊ���ظ��ַ���һ�γ��ִ��ĺ�һ��λ�á�
// �������start��cur��������������ÿ�η���ǰ��λ�����´���Ļ��ᳬʱ��Ӧ���ظ�����֮ǰ�жϹ��ķ����ַ����ĳɹ���
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)��
class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_len(0);	// ��󳤶�
		string processed_str;	// ��¼֮ǰ���ظ����ַ��ǣ��������ϵ�ǰ�ַ��Ƿ���ֹ���
		vector <int> processed_pos;	// ��¼֮ǰ���ظ��ַ��ǳ��ֵ�λ�ã���ǰһ������˳����һһ��Ӧ��
		int start(0),cur(0);	// �˲��ظ��ַ�������ʼλ�ú͵�ǰλ�á�

		int count(0);	// �����ַ���δ�ظ��ĳ��ȡ�
		while (cur < s.size())
		{
			if (processed_str.find(s.at(cur)) == string::npos)	// ������ַ�û�г��ֹ������Ӽ�����
			{
				++count;
			}else	// ������ַ��Ѿ����ֹ���
			{
				max_len = max(max_len, count);	// �Ƚ�֮ǰ�Ӵ��Ƿ���Ŀǰ��󳤶ȡ�
				// �õ��µ���ʼλ�ã������ظ����ַ���һ�γ��ֵ�λ�ü�1��
				int new_start = processed_pos[processed_str.find(s.at(cur))] + 1;
				// ɾ����λ��֮ǰ���ظ��ַ���λ�ü�¼�����ǲ�Ӧ��Ӱ����һ���Ӵ���֤��
				processed_str = processed_str.substr(new_start-start);
				processed_pos.erase(processed_pos.begin(), next(processed_pos.begin(),new_start-start));
				// ��¼��λ�á�
				start = new_start;
				// �������λ�õ���ǰλ���Ӵ��ĳ��ȡ�
				count = cur - new_start + 1;
			}
			// ÿ�ν���ǰ�ַ���λ�ô�������
			processed_str.push_back(s.at(cur));	
			processed_pos.push_back(cur);
			// cur��֤�����ˣ����������
			++cur;
		}
		max_len = max(max_len, count);
		return max_len;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Longest_Substring_Without_Repeating_Characters", "[]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.lengthOfLongestSubstring("") == 0);
	}
	SECTION("Normal Input1") {
		REQUIRE(sln.lengthOfLongestSubstring("dyig") == 4);
	}
	SECTION("Normal Input2") {
		REQUIRE(sln.lengthOfLongestSubstring("advdf") == 3);
	}
	SECTION("Normal Input3") {
		REQUIRE(sln.lengthOfLongestSubstring("eee") == 1);
	}
}