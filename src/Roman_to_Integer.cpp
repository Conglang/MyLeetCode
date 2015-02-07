//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a roman numeral, convert it to an integer.

Input is guaranteed to be within the range from 1 to 3999.
//--------------------------------------------------------------------------------------------------------------*/
// My way
class Solution {
public:
	int get_number(char rome)
	{
		if ( rome == 'I') {return 1;}
		if ( rome == 'V') {return 5;}
		if ( rome == 'X') {return 10;}
		if ( rome == 'L') {return 50;}
		if ( rome == 'C') {return 100;}
		if ( rome == 'D') {return 500;}
		if ( rome == 'M') {return 1000;}
		return 0;
	}
	int romanToInt(string s) {
		int result(0);
		std::transform(s.begin(), s.end(), s.begin(), ::toupper);
		for ( size_t i = 0; i < s.length(); ++i )
		{
			if (i + 1 == s.length())
			{
				result += get_number(s[i]);
				break;
			}
			if ( get_number(s[i+1]) > get_number(s[i])) {result -= get_number(s[i]);}
			else {result += get_number(s[i]);}
		}
		return result;
	}
};