//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
//--------------------------------------------------------------------------------------------------------------*/
// My Old Version
class Solution {
public:
	std::string int2str(int i)
	{
		string s;
		stringstream ss(s);
		ss<<i;
		return ss.str();
	}

	std::string get_next_string(std::string last_string)
	{
		std::string result_str;
		std::string temp_str;
		char last_char = '0';
		for(int i = 0; i < last_string.size(); ++i)
		{
			char this_char = last_string[i];

			if (this_char != last_char && !temp_str.empty())
			{
				result_str += (int2str(temp_str.length()) + temp_str.substr(0,1));
				temp_str.clear();
			}
			last_char = this_char;
			temp_str.push_back(this_char);
		}
		result_str += (int2str(temp_str.length()) + temp_str.substr(0,1));
		return result_str;
	}

	string countAndSay(int n) {
		std::string s("1");

		while(--n)
		{
			s = get_next_string(s);
		}
		return s;
	}
};
//---------------------------------------------------
// Better Version
// LeetCode, Count and Say
// @author 连城 (http://weibo.com/lianchengzju)
// 时间复杂度 O(n^2) ，空间复杂度 O(n)
class Solution {
public:
	string countAndSay(int n) {
		string s("1");
		while (--n)
			s = getNext(s);
		return s;
	}
	string getNext(const string &s) {
		stringstream ss;
		for (auto i = s.begin(); i != s.end(); ) {
			auto j = find_if(i, s.end(), bind1st(not_equal_to<char>(), *i));
			ss << distance(i, j) << *i;
			i = j;
		}
		return ss.str();
	}
}

// 心得：赶紧去好好看看标准库吧！