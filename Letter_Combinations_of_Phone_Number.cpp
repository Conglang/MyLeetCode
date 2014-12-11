//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.

1:
2: abc
3: def
4: ghi
5: jkl
6: mno
7: pqrs
8: tuv
9: wxyz
*: +
0:  

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
//--------------------------------------------------------------------------------------------------------------*/
// My Way
class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		string path;
		map<char, string> correspond;
		correspond['1'] = "";
		correspond['2'] = "abc";
		correspond['3'] = "def";
		correspond['4'] = "ghi";
		correspond['5'] = "jkl";
		correspond['6'] = "mno";
		correspond['7'] = "pqrs";
		correspond['8'] = "tuv";
		correspond['9'] = "wxyz";
		correspond['0'] = "";
		dfs(digits, 0, correspond, path, result);
		return result;
	}
private:
	void dfs(const string& digits, int cur, const map<char, string>& correspond, string& path, vector<string>& result)
	{
		if (path.size() == digits.size())
		{
			result.push_back(path);
			return;
		}
		char cur_char(digits.at(cur));
		string cor_str(correspond.find(cur_char)->second);
		for (char elem : cor_str)
		{
			path += elem;
			dfs(digits, cur+1, correspond, path, result);
			path.pop_back();
		}
	}
};