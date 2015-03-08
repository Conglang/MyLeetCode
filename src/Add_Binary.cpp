//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two binary strings, return their sum (also a binary string).
* 
* For example,
* a = "11"
* b = "1"
* Return "100".
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		// ȡ����ĳ���
		size_t n = a.size() > b.size() ? a.size() : b.size();
		// ���ȷ�ת���������Ǵ����ַ���ʼ��
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int plus = 0;
		for (size_t i = 0; i < n; ++i)
		{
			int a_num = i < a.size() ? a[i] - '0' : 0;
			int b_num = i < b.size() ? b[i] - '0' : 0;
			int cur_num = a_num + b_num + plus;
			result.insert(result.begin(), cur_num % 2 + '0');	// �����ײ��뵱ǰλ
			plus = cur_num / 2;	// �õ���λ
		}
		if (plus == 1) {result.insert(result.begin(), '1');}	// �Ƿ���Ҫ�ھ��׽�λ
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Add_Binary", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.addBinary("","") == "");
		REQUIRE(s.addBinary("","0") == "0");
	}
	SECTION("Normal Input"){
		REQUIRE(s.addBinary("11","1") == "100");
	}
}