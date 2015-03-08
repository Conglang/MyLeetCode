//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string s, partition s such that every substring of the partition is a palindrome.
* 
* Return the minimum cuts needed for a palindrome partitioning of s.
* 
* For example, given s = "aab",
* Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/*
*	����״̬f(i, j)��ʾ����[i, j]֮����С��cut������״̬ת�Ʒ���Ϊ��
*	f(i, j) = min {f(i, k) + f(k + 1, j)}, i <=k<=j, 0 <=i<=j<n
*	ת����һάDP�����ÿ�δ�i����ɨ�裬ÿ�ҵ�һ�����ľ���һ��DP����ôi~j֮����һ�����ģ���ô��ʽת��Ϊ��
*	f(i) = min{f(j+1)+1}, i<=j<n
*	����f(i) = ����[i, n-1]֮����С��cut����nΪ�ַ������ȡ�
*	��ô����ж�[i, j]�Ƿ��ǻ��ģ�
*	������DP��˼·��
*	����״̬P[i][j] = true�����[i, j]Ϊ���ģ���ô
*	P[i][j] = str[i] == str[j] && P[i+1][j-1]
*/
// ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n^2)
class Solution {
public:
	int minCut(string s) {
		if(s.empty()) return 0;
		const int n(s.size());
#if __cplusplus < 201103L
		vector<int> f(n+1,0);
		vector<bool> temp(n,false);
		vector<vector<bool> > p(n, temp);
#else
		int f[n+1];	// ��¼��i~n-1֮���ַ�������Сcut����
		bool p[n][n];	// �����ж�i~j֮���Ƿ�Ϊ���Ĵ���
		fill_n(&p[0][0], n * n, false);	// ��ʼȫ����Ϊ�񣬼����ǻ��Ĵ���
#endif
		// ��ʼ��Ϊ��������ÿ���ַ�����Ҫ�и
		for (int i = 0; i <= n; ++i)
		{
			f[i] = n - 1 - i;   // ���һ��f[n]=-1
		}
		// �������������ƶ����ַ����ס�
		for (int i = n - 1; i >=0; --i)
		{
			// �����ַ����������ƶ����ַ���β��
			for (int j = i; j < n; ++j)
			{
				// �����i��j��һ�����Ĵ�������һ��f��DP������
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
				{
					p[i][j] = true;
					f[i] = min(f[i], f[j + 1] + 1);
				}
			}
		}
		return f[0];	// ���ش�0~n-1����С�и�ֵ��
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Palindrome_Partitioning_II", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.minCut("") == 0);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.minCut("aab") == 1);
	}
}