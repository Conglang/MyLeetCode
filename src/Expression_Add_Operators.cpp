//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string that contains only digits 0-9 and a target value, 
* return all possibilities to add binary operators (not unary) +, -, or * between the digits 
* so they evaluate to the target value.
* 
* Examples: 
* "123", 6 -> ["1+2+3", "1*2*3"] 
* "232", 8 -> ["2*3+2", "2+3*2"]
* "105", 5 -> ["1*0+5","10-5"]
* "00", 0 -> ["0+0", "0-0", "0*0"]
* "3456237490", 9191 -> []
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/24478/17-lines-solution-dfs-c
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        if (num.empty()) return res;
        for (int i = 1; i <= num.size(); ++i)
        {
            string s = num.substr(0,i);
            long cur = stol(s);
            if (to_string((long long)cur).size() != s.size()) continue;
            dfs(res, num, target, s, i, cur, cur, '#'); // no operator defined
        }
        return res;
    }
public:
    // cur: [string]    expression generated so far.
    // pos: [int]       current visiting position of num.
    // cv:  [long]      cumulative value so far.
    // pv:  [long]      previous operand value.
    // op:  [char]      previous operator used.
    void dfs(vector<string>& res, const string& num, const int target, string cur, int pos, const long cv, const long pv, const char op)
    {
        if (pos == num.size() && cv == target)
        {
            res.push_back(cur);
        }else
        {
            for (int i = pos+1; i <= num.size(); ++i)
            {
                string t = num.substr(pos, i-pos);
                long now = stol(t);
                if (to_string((long long)now) != t) continue;
                dfs(res, num, target, cur+'+'+t, i, cv+now, now, '+');
                dfs(res, num, target, cur+'-'+t, i, cv-now, now, '-');
                dfs(res, num, target, cur+'*'+t, i, (op == '-') ? cv+pv-pv*now : ((op == '+') ? cv-pv+pv*now : pv*now), pv*now, op);
            }
        }
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Expression_Add_Operators", "[Devide and Conquer]") {
	Solution s;
	SECTION("Normal Input") {
		vector<string> result;
		result.push_back("1+2+3");
		result.push_back("1*2*3");
		REQUIRE(s.addOperators("123", 6) == result);
	}
}
