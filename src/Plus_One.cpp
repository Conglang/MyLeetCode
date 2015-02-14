//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a non-negative number represented as an array of digits, plus one to the number.
* 
* The digits are stored such that the most significant digit is at the head of the list.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
// ��ֹ1���Ӷ����������Եķ������߾��ȼӷ���
class Solution {
public:
	vector<int> add_num(vector<int>& digits, int num)
	{
		vector<int> result;
		if (digits.empty() || !num) {return digits;}
		int plus = num;
		for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
		{
			int cur = *it + plus;
			plus = cur / 10;
			result.push_back(cur % 10);
		}
		if (plus) {result.push_back(1);}
		reverse(result.begin(), result.end());
		return result;
	}
	vector<int> plusOne(vector<int> &digits) {
		return add_num(digits, 1);
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Plus_One", "[Arrays]"){
	Solution s;
	vector<int> digits;
	vector<int> result;
	SECTION("Empty Input"){
		REQUIRE(s.plusOne(digits) == result);
	}
	SECTION("Normal Input"){
		digits.assign(3,9);
		result.assign(4,0);
		result[0] = 1;
		REQUIRE(s.plusOne(digits) == result);
		digits.assign(3,1);
		result.assign(3,1);
		result[2] = 2;
		REQUIRE(s.plusOne(digits) == result);
	}
}