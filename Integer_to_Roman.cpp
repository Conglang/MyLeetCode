//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
//--------------------------------------------------------------------------------------------------------------*/
// My Way
class Solution {
public:
	string intToRoman(int num) {
		string result;
		map<int, string, greater<int> > digit_rome_map;
		digit_rome_map.insert(make_pair(1000, "M"));
		digit_rome_map.insert(make_pair(500, "D"));
		digit_rome_map.insert(make_pair(100, "C"));
		digit_rome_map.insert(make_pair(50, "L"));
		digit_rome_map.insert(make_pair(10, "X"));
		digit_rome_map.insert(make_pair(5, "V"));
		digit_rome_map.insert(make_pair(1, "I"));
		digit_rome_map.insert(make_pair(900, "CM"));
		digit_rome_map.insert(make_pair(400, "CD"));
		digit_rome_map.insert(make_pair(90, "XC"));
		digit_rome_map.insert(make_pair(40, "XL"));
		digit_rome_map.insert(make_pair(9, "IX"));
		digit_rome_map.insert(make_pair(4, "IV"));

		while (num)
		{
			for (map<int, string, greater<int> >::iterator it = digit_rome_map.begin(); it != digit_rome_map.end(); ++it)
			{
				if (num >= (*it).first)
				{
					num -= (*it).first;
					result += (*it).second;
					break;
				}
			}
		}
		return result;
	}
};