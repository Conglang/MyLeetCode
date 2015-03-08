//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string s, partition s such that every substring of the partition is a palindrome.
* 
* Return all possible palindrome partitioning of s.
* 
* For example, given s = "aab",
* Return
* 
*   [
*     ["aa","b"],
*     ["a","a","b"]
*   ]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1

#ifdef W1
// �������������ʱ�临�Ӷ�O(2^n)���ռ临�Ӷ�O(n)��
// һ������Ϊn���ַ�������n-1���ط����Կ��ϣ�ÿ���ط��ɶϿɲ��ϣ�����ʱ�临�Ӷ�ΪO(2^{n-1})��
// ���ݷ�����ͷ��ʼ�����ַ������������Ĳ����ǿ��е�partition����ʱ���͵ݹ鴦����֮����ַ�����
class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<vector<string> > result;
		vector<string> path;	// һ��partition������
		DFS(s, path, result, 0);
		return result;
	}
	// ����������s[start]��ͷ��partition������
	void DFS(string &s, vector<string> &path, vector<vector<string> > &result, int start)
	{
		if (start == s.size())	// �Ѿ������������ַ�����
		{
			result.push_back(path);
			return;
		}
		// ����ÿ��λ�ã�����ǿ��е�partition�������͵ݹ鴦��֮���λ�á�
		for (int i = start; i < s.size(); ++i)
		{
			if (is_palindrome(s, start, i))
			{
				path.push_back(s.substr(start, i-start+1));
				DFS(s, path, result, i+1);
				path.pop_back();
			}
		}
	}
	// �ж�һ���ַ����Ƿ��ǻ��Ĵ���
	bool is_palindrome(const string &s, int start, int end)
	{
		while (start < end && s[start] == s[end])
		{
			++start;
			--end;
		}
		return start >=end;
	}
};
#endif

#ifdef W2
// ��̬�滮��ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)��
// ���ö�̬�滮�õ���Щ��������Ч�Ļ��Ĵ���
// �ٸ��������Ϣ�����ö�̬�滮��������ÿ�����Ĵ��״��ļ�����β����һλ������ӱ����Ĵ��ļ��ϡ�
// Ҫ��õ��ľ�����λ��0���ļ��ϡ�
class Solution {
public:
	vector<vector<string>> partition(string s) {
		const int n(s.size());

		bool is_valid[n][n];    // whether s[i,j] is palindrome
		fill_n(&is_valid[0][0], n*n, false);

		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				is_valid[i][j] = s[i] == s[j] && ((j - i < 2) || is_valid[i + 1][j - 1]);
			}
		}

		vector<vector<string> > sub_palis[n];   // sub palindromes of s[0, i]
		for (int i = n - 1; i >= 0; --i)
		{
			for (int j = i; j < n; ++j)
			{
				// ����ÿ�����еĻ��Ĵ���
				if (is_valid[i][j])
				{
					const string palindrome = s.substr(i, j - i + 1);
					if (j + 1 < n)
					{
						// �����Ĵ����i����sub_palis[i]���Ǳ����Ĵ��յ�j��һλ��sub_pailis[j+1]���ÿһ����ӱ����Ĵ���
						for (auto v : sub_palis[j + 1])
						{
							v.insert(v.begin(), palindrome);
							sub_palis[i].push_back(v);
						}
					}else
					{
						sub_palis[i].push_back(vector<string> {palindrome });
					}
				}
			}
		}
		return sub_palis[0];
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Palindrome_Partitioning", "[Depth-First Search]"){
	Solution sln;
	vector<vector<string> > result;
	SECTION("Empty Input") {
		result.push_back(vector<string>());
		REQUIRE(sln.partition("") == result);
	}
	SECTION("Normal Input") {
		string t1[2] = {"aa","b"};
		string t2[3] = {"a","a","b"};
		result.push_back(vector<string>(t2,t2+3));
		result.push_back(vector<string>(t1,t1+2));
		REQUIRE(sln.partition("aab") == result);
	}
}
