//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a string s, partition s such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of s.

For example, given s = "aab",
Return 1 since the palindrome partitioning ["aa","b"] could be produced using 1 cut.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
/*
����״̬f(i, j)��ʾ����[i, j]֮����С��cut������״̬ת�Ʒ���Ϊ��
f(i, j) = min {f(i, k) + f(k + 1, j)}, i <=k<=j, 0 <=i<=j<n
ת����һάDP�����ÿ�δ�i����ɨ�裬ÿ�ҵ�һ�����ľ���һ��DP����ô��ʽת��Ϊ��
f(i) = min{f(j+1)+1}, i<=j<n
����f(i) = ����[i, n-1]֮����С��cut����nΪ�ַ������ȡ�
��ô����ж�[i, j]�Ƿ��ǻ��ģ�
������DP��˼·��
����״̬P[i][j] = true�����[i, j]Ϊ���ģ���ô
P[i][j] = str[i] == str[j] && P[i+1][j-1]
*/
// ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n^2)
class Solution {
public:
	int minCut(string s) {
		const int n(s.size());
		int f[n+1];
		bool p[n][n];

		fill_n(&p[0][0], n * n, false);
		// the worst case is cutting by each char
		for (int i = 0; i <= n; ++i)
		{
			f[i] = n - 1 - i;   // ���һ��f[n]=-1
		}

		for (int i = n - 1; i >=0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				if (s[i] == s[j] && (j - i < 2 || p[i + 1][j - 1]))
				{
					p[i][j] = true;
					f[i] = min(f[i], f[j + 1] + 1);
				}
			}
		}
		return f[0];
	}
};