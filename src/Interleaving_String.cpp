//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
* 
* For example,
* Given:
* s1 = "aabcc",
* s2 = "dbbca",
* 
* When s3 = "aadbbcbcac", return true.
* When s3 = "aadbbbaccc", return false.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2
#ifdef W1
/*
*	��״̬f[i][j]����ʾs1[0,i]��s2[0,j]��ƥ��s3[0, i+j]��
*	���s1�����һ���ַ�����s3�����һ���ַ�����f[i][j]=f[i-1][j]��
*	���s2�����һ���ַ�����s3�����һ���ַ�����f[i][j]=f[i][j-1]��
*	���״̬ת�Ʒ������£�
*	f[i][j] = (s1[i - 1] == s3 [i + j - 1] && f[i - 1][j]) || (s2[j - 1] == s3 [i + j - 1] && f[i][j - 1]);
*/
// ��ά���棬ʱ�临�Ӷ� O(n^2)���ռ临�Ӷ�O(n^2)��
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s3.length() != s1.length() + s2.length())
			return false;
		// ���ȶ���ԭ�ַ�����һλ��Ϊ�˷�ֹ���ַ����������
		vector<vector<bool> > f(s1.length() + 1,
			vector<bool>(s2.length() + 1, true));
		// Ԥ��s2Ϊ�ա�
		for (size_t i = 1; i <= s1.length(); ++i)
		{
			f[i][0] = f[i - 1][0] && s1[i - 1] == s3[i - 1];
		}
		// Ԥ��s1Ϊ�ա�
		for (size_t i = 1; i <= s2.length(); ++i)
		{
			f[0][i] = f[0][i - 1] && s2[i - 1] == s3[i - 1];
		}
		// ��̬�滮���㣬ֻ��֮ǰ���������ұ���Ҳ���������ŷ���������
		for (size_t i = 1; i <= s1.length(); ++i)
		{
			for (size_t j = 1; j <= s2.length(); ++j)
			{
				f[i][j] = (s1[i - 1] == s3[i + j - 1] && f[i - 1][j])
					|| (s2[j - 1] == s3[i + j - 1] && f[i][j - 1]);
			}
		}
		return f[s1.length()][s2.length()];
	}
};
#endif

#ifdef W2
// ��ά���� + �������飬ʱ�临�Ӷ� O(n^2) ���ռ临�Ӷ� O(n)
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.length() + s2.length() != s3.length())
			return false;
		if (s1.length() < s2.length())
			return isInterleave(s2, s1, s3);
		vector<bool> f(s2.length() + 1, true);
		for (size_t i = 1; i <= s2.length(); ++i)
			f[i] = s2[i - 1] == s3[i - 1] && f[i - 1];
		// �ڵڶ���ѭ������һ��f[0]λ�ô洢����s1����Ϣ��
		for (size_t i = 1; i <= s1.length(); ++i) {
			f[0] = s1[i - 1] == s3[i - 1] && f[0];
			for (size_t j = 1; j <= s2.length(); ++j)
				f[j] = (s1[i - 1] == s3[i + j - 1] && f[j])
				|| (s2[j - 1] == s3[i + j - 1] && f[j - 1]);
		}
		return f[s2.length()];
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Interleaving_String", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.isInterleave("","","") == true);
		REQUIRE(sln.isInterleave("a","","a") == true);
		REQUIRE(sln.isInterleave("a","b","a") == false);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.isInterleave("aabcc","dbbca","aadbbcbcac") == true);
		REQUIRE(sln.isInterleave("aabcc","dbbca","aadbbbaccc") == false);
	}
}