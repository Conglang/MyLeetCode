//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
//--------------------------------------------------------------------------------------------------------------*/
// My way
class Solution {
public:
	bool isValid(string s) {
		stack<char> opt;
		map<char, char> opt_map;
		opt_map.insert(make_pair('(',')'));
		opt_map.insert(make_pair('[',']'));
		opt_map.insert(make_pair('{','}'));
		while (!s.empty())
		{
			char this_char = *s.begin();
			s.erase(s.begin());
			if (this_char == '(' || this_char == '[' || this_char == '{')
			{
				opt.push(opt_map[this_char]);
			}
			else if (this_char == ')' || this_char == ']' || this_char == '}')
			{
				if (opt.empty()) {return false;}
				if (this_char != opt.top())
				{
					return false;
				}
				opt.pop();
			}
			else if (this_char != ',')
			{
				return false;
			}
		}
		if (!opt.empty()) {return false;}
		return true;
	}
};