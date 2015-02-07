//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/2
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
//--------------------------------------------------------------------------------------------------------------*/
// My Way
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int i = 0;
		int length = 0;
		int last_length = 0;
		bool restart = false;
		while (s[i])
		{
			if (s[i] == ' ')
			{
				if (restart)
				{
					last_length = length;
				}
				length = 0;
				restart = false;

			}
			else {restart = true; ++length;}
			++i;
		}
		return restart ? length : last_length;
	}
};

// 或者用stl里的string操作find直接实现。