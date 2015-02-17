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
// 动态规划，时间复杂度O(n*m)，空间复杂度O(n*m)。
/*
*	设状态为f[i][j]，表示word1[0,i]和word2[0,j]之间的最小编辑距离。
*	设word1当前处理的字符是a，word2当前处理的字符是b。
*	1. 如果a == b，则f[i][j] = f[i-1][j-1]
*	2. 如果a != b，
*		(1)如果将a替换成b，则f[i][j] = f[i-1][j-1] + 1
*		(2)如果在a的后面添加一个b，则f[i][j] = f[i][j-1] + 1
*		(3)如果将a删除，则f[i][j] = f[i-1][j] + 1
*/
class Solution {
public:
	int minDistance(string word1, string word2) {
		const int m = word1.length();
		const int n = word2.length();
		vector<vector<int> > f(m+1, vector<int>(n+1,0));	// 0位表示空，1位表示第1位，m位表示第m位。
		// 要清空为""的状态，最小要删除i个字符即i步。
		for (int i = 0; i <= m; ++i)
		{
			f[i][0] = i;
		}
		// 要从""的状态增加为j长的字符串，最小需要添加j个字符即j步。
		for (int j = 0; j <= n; ++j)
		{
			f[0][j] = j;
		}
		// 动态规划递推其他位置。
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