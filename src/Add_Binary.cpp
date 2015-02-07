//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
//--------------------------------------------------------------------------------------------------------------*/
// My Way
class Solution {
public:
	string addBinary(string a, string b) {
		string result;
		size_t n = a.size() > b.size() ? a.size() : b.size();
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int plus = 0;
		for (size_t i = 0; i < n; ++i)
		{
			int a_num = i < a.size() ? a[i] - '0' : 0;
			int b_num = i < b.size() ? b[i] - '0' : 0;
			int cur_num = a_num + b_num + plus;
			result.insert(result.begin(), cur_num % 2 + '0');
			plus = cur_num / 2;
		}
		if (plus == 1) {result.insert(result.begin(), '1');}
		return result;
	}
};