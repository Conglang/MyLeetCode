//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Write a function to find the longest common prefix string amongst an array of strings.
//--------------------------------------------------------------------------------------------------------------*/
// My way
class Solution {
public:
	string longestCommonPrefix(vector<string> &strs) {
		string prefix;
		if ( strs.empty() )
		{
			return prefix;
		}
		prefix = strs.front();
		for ( vector<string>::iterator it = strs.begin() + 1; it != strs.end(); ++it )
		{
			string this_str = *it;
			prefix = prefix.substr(0,min(prefix.size(), this_str.size()));
			for (int i = 0; i < prefix.size(); ++i)
			{
				if (prefix[i] != this_str[i])
				{
					prefix = prefix.substr(0, i);
					break;
				}
			}
		}
		return prefix;
	}
};