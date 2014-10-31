//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/31
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P    A    H    N
A P L S  I  I  G
Y     I     R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
//--------------------------------------------------------------------------------------------------------------*/
// My way
class Solution {
public:
	string convert(string s, int nRows) {
		string result;
		if (nRows == 1) {return s;}
		if (nRows > s.size()) {return s;}
		int gap = nRows * 2 - 2;
		int pairs = s.size() / gap;
		int remain = s.size() % gap;
		for (int i = 0; i < nRows; ++i)
		{
			for (int j = 0; j < (remain > 0 ? pairs+1 : pairs); ++j)
			{
				if (j == pairs)
				{
					if (remain > i)
					{
						result += s[i+j*gap];
					}
					if (i > 0 && i < nRows-1 && gap-i < remain)
					{
						result += s[(j+1)*gap-i];
					}
					continue;
				}
				result += s[i+j*gap];
				if (i > 0 && i < nRows-1)
				{
					result += s[(j+1)*gap-i];
				}
			}
		}
		return result;
	}
};