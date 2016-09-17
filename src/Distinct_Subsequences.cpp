//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string S and a string T, count the number of distinct subsequences of T in S.
* 
* A subsequence of a string is a new string which is formed from the original string by deleting some
* (can be none) of the characters without disturbing the relative positions of the remaining characters.
* (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
* 
* Here is an example:
* S = "rabbbit", T = "rabbit"
* 
* Return 3.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/*
��̬�滮����״̬Ϊf(i,j)����ʾT[0,j]��S[0,i]����ֵĴ�����
���ȣ�����S[i]��T[j]�Ƿ���ȣ�����ʹ��S[i]����f(i,j) = f(i-1,j);
��S[i] == T[j]�������ʹ��S[i]����ʱf(i,j) = f(i-1,j) + f(i-1,j-1)������ʹ�õ��������ʹ�õ������
*/
//��ά��̬�滮+�������顣
// ʱ�临�Ӷ�O(mn)���ռ临�Ӷ�O(n)��
class Solution {
public:
	int numDistinct(string S, string T) {
		vector<int> f(T.length()+1,0);	// 0Ϊ��ʱ��1~length��Ӧ�ַ���T��
		f[0] = 1;
		for (int i = 0; i < S.size(); ++i)
		{
			for (int j = T.length()-1; j >= 0 ; --j)
			{
				f[j+1] += S[i] == T[j] ? f[j] : 0;
			}
		}
		return f[T.length()];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Distinct_Subsequences", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Normal Input") {
		REQUIRE(sln.numDistinct("rabbbit", "rabbit") == 3);
		REQUIRE(sln.numDistinct("haha", "hehe") == 0);
		REQUIRE(sln.numDistinct("abcde", "aec") == 0);
	}
}