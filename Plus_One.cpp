//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
//--------------------------------------------------------------------------------------------------------------*/
// My way，特化+1的方法
class Solution {
public:
	vector<int> plusOne(vector<int> &digits) {
		bool exceed = false;
		vector<int> result;
		for (vector<int>::reverse_iterator it = digits.rbegin(); it != digits.rend(); ++it)
		{
			int this_num = *it;
			if (it == digits.rbegin() || exceed)
			{
				exceed = this_num + 1 > 9;
				result.push_back(exceed ? 0 : this_num + 1);
				continue;
			}else
			{
				result.push_back(this_num);
			}
		}
		if (exceed) {result.push_back(1);}
		reverse(result.begin(), result.end());
		return result;
	}
};
// My Way, 加多少数都可以的方法
class Solution {
public:
	vector<int> add_num(vector<int>& digits, int num)
	{
		int plus = num;
		vector<int> result;
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