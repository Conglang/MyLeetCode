//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string containing only digits, restore it by returning all possible valid IP address combinations.
* 
* For example:
* Given "25525511135",
* 
* return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// ʱ�临�Ӷ�O(n^4)���ռ临�Ӷ�O(n)��
class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> result;
		if (s.size() < 4) return result;
		string ip;	// ����м�����
		dfs(s,0,0,ip,result);
		return result;
	}
	void dfs(string s, int start, int step, string ip, vector<string>& result)
	{
		if (start == s.size() && step == 4)	// �ҵ�һ���Ϸ��⡣
		{
			ip.resize(ip.size()-1);
			result.push_back(ip);
			return;
		}
		if (s.size() - start > (4-step)*3) return;	// ��֦��̫����
		if (s.size() - start < (4-step)) return;	// ��֦��̫�̡�

		int num(0);
		for(int i = start; i < min(int(s.size()),start+3); ++i)
		{
			num = num * 10 + (s[i] - '0');
			if (num <= 255)	// ��ǰ�ڵ�Ϸ����������µݹ顣
			{
				ip += s[i];
				dfs(s,i+1,step+1,ip+'.',result);
			}
			if (num == 0) break;	// ������ǰ׺0�����012��ֻ������0��
		}
	}
};//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Restore_IP_Addresses", "[Depth-First Search]"){
	Solution sln;
	vector<string> result;
	SECTION("Invalid Input") {
		REQUIRE(sln.restoreIpAddresses("123") == result);
		REQUIRE(sln.restoreIpAddresses("333333333") == result);
	}
	SECTION("Normal Input1") {
		result.push_back("0.10.0.10");
		result.push_back("0.100.1.0");
		REQUIRE(sln.restoreIpAddresses("010010") == result);
	}
	SECTION("Normal Input2") {
		result.push_back("255.255.11.135");
		result.push_back("255.255.111.35");
		REQUIRE(sln.restoreIpAddresses("25525511135") == result);
	}
}