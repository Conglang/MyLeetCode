//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)
* 
* You have the following 3 operations permitted on a word:
* 
* a) Insert a character
* b) Delete a character
* c) Replace a character
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// ��̬�滮��ʱ�临�Ӷ�O(n*m)���ռ临�Ӷ�O(n*m)��
/*
*	��״̬Ϊf[i][j]����ʾword1[0,i]��word2[0,j]֮�����С�༭���롣
*	��word1��ǰ������ַ���a��word2��ǰ������ַ���b��
*	1. ���a == b����f[i][j] = f[i-1][j-1]
*	2. ���a != b��
*		(1)�����a�滻��b����f[i][j] = f[i-1][j-1] + 1
*		(2)�����a�ĺ������һ��b����f[i][j] = f[i][j-1] + 1
*		(3)�����aɾ������f[i][j] = f[i-1][j] + 1
*/
class Solution {
public:
	int minDistance(string word1, string word2) {
		const int m = word1.length();
		const int n = word2.length();
		vector<vector<int> > f(m+1, vector<int>(n+1,0));	// 0λ��ʾ�գ�1λ��ʾ��1λ��mλ��ʾ��mλ��
		// Ҫ���Ϊ""��״̬����СҪɾ��i���ַ���i����
		for (int i = 0; i <= m; ++i)
		{
			f[i][0] = i;
		}
		// Ҫ��""��״̬����Ϊj�����ַ�������С��Ҫ���j���ַ���j����
		for (int j = 0; j <= n; ++j)
		{
			f[0][j] = j;
		}
		// ��̬�滮��������λ�á�
		for (int i = 1; i <= m; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (word1[i-1] == word2[j-1])
				{
					f[i][j] = f[i-1][j-1];
				}else
				{
					int insert_num = f[i][j-1] + 1;
					int delete_num = f[i-1][j] + 1;
					int replace_num = f[i-1][j-1] + 1;
					f[i][j] = min(insert_num, min(delete_num, replace_num));
				}
			}
		}
		return f[m][n];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Edit_Distance", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.minDistance("","") == 0);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.minDistance("a","b") == 1);
		REQUIRE(sln.minDistance("abced","acea") == 2);
	}
}