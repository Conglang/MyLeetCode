//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* A message containing letters from A-Z is being encoded to numbers using the following mapping:
* 
* 'A' -> 1
* 'B' -> 2
* ...
* 'Z' -> 26
* Given an encoded message containing digits, determine the total number of ways to decode it.
* 
* For example,
* Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).
* 
* The number of ways decoding "12" is 2.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// ��̬�滮��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
// ������¥��(Climbing Stairs)�����ֿ�����������1����ǰһ��ƴ�ϣ����2���Լ����Խ�����
// ���ܵ��龳����������֮�͡�
class Solution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;
		int prev(0),cur(1);
		for (size_t i = 1; i <= s.length(); ++i)
		{
			// ���������ܶ��Խ��������2��ͨ��
			if (s[i-1] == '0') {cur = 0;}
			// ��Щ���������ǰһ��ƴ�ϣ����1��ͨ��
			if (i < 2 || !(s[i-2] == '1' || (s[i-2] == '2' && s[i-1] <= '6')))
			{
				prev = 0;
			}
			swap(prev, cur);
			cur += prev;	// ����¥�����ƣ���ǰ=���1+���2
		}
		return cur;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Decode_Ways", "[Dynamic Programming]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.numDecodings("") == 0);
		REQUIRE(sln.numDecodings("0") == 0);
	}
	SECTION("Normal Input") {
		REQUIRE(sln.numDecodings("12") == 2);
		REQUIRE(sln.numDecodings("127") == 2);
		REQUIRE(sln.numDecodings("111") == 3);
	}
}