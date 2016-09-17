//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
* 
* For example, given n = 3, a solution set is:
* 
* "((()))", "(()())", "(())()", "()(())", "()()()"
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ���ѡ�ʱ�临�Ӷ�O(2^n)���ռ临�Ӷ�O(n)��
class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> result;
		if (n==0) {return result;}
		if (n==1) {result.assign(1,"()"); return result;}
		int balance_factor = 0;	// �����ż�ȥ�����ŵ�������
		string sequence;
		dfs(result,sequence,n,0,balance_factor);
		return result;
	}
private:
	void dfs(vector<string>& result,string& sequence, int n, int cur, int balance_factor)
	{
		if (balance_factor == 0 && cur == n*2)	// ����Ҫ��������
		{
			result.push_back(sequence);
			return;
		}
		if (balance_factor < 0 || cur >= n*2 || balance_factor > n)	// ��֦��������̫�ࡢ�ߵ����ˡ������Ŷ���һ���ˡ�
		{
			return;
		}
		sequence.push_back('(');	// ���������š�
		++balance_factor;
		dfs(result,sequence,n,cur+1,balance_factor);
		--balance_factor;
		sequence.pop_back();
		
		sequence.push_back(')');	// ���������š�
		--balance_factor;
		dfs(result,sequence,n,cur+1,balance_factor);
		++balance_factor;
		sequence.pop_back();
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Generate_Parentheses", "[Depth-First Search]"){
	Solution sln;
	vector<string> result;
	SECTION("Empty Input") {
		REQUIRE(sln.generateParenthesis(0) == result);
	}
	SECTION("Normal Input") {
		result.push_back("(())");
		result.push_back("()()");
		REQUIRE(sln.generateParenthesis(2) == result);
	}
}