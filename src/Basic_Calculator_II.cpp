//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/24
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Implement a basic calculator to evaluate a simple expression string.
* 
* The expression string contains only non-negative integers, +, -, *, / operators and empty spaces . The integer division should truncate toward zero.
* 
* Example 1:
* 
* Input: "3+2*2"
* Output: 7
* Example 2:
* 
* Input: " 3/2 "
* Output: 1
* Example 3:
* 
* Input: " 3+5 / 2 "
* Output: 5
* Note:
* 
* You may assume that the given expression is always valid.
* Do not use the eval built-in library function.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 用栈。先移除多余空格。然后对连续的数字识别，遇到符号时就将识别或处理过的数字入栈。
// 如果前一符号是*或/，就把前两个数字计算一下再入栈。如果前一符号是-，当前数字就取反再入栈。如果前一符号是+，就直接入栈。
// 相当于栈内都是要加起来的数字，只对*/预先做处理。所以最后一步把所有栈内数字加起来就可以了。

class Solution {
    stack<int> s1;
    
public:
    int calculate(string s) {
        int ans = 0, val = 0, val1 = 0;
        char op = '+';
        
        /* Removing trailing spaces */
        size_t idx = s.find_last_not_of(' ');
        if (idx != string::npos)
            s.erase(idx+1);
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            // 连续的数字
            if (isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
            }
            // 非数字或者最后一个，算账的日子到了。只有*/操作才出栈单独计算，默认是+操作。
            if (!isdigit(s[i]) || (i == s.size()-1)) {
                if (op == '*' || op == '/' ) {  // 注意这是上次记下的 operator
                    int val1 = s1.top();
                    s1.pop();
                    val = (op == '*') ? (val1 * val) : (val1 / val);
                } else {
                    val = (op == '+') ? val : -val;
                }
                s1.push(val);
                op = s[i];
                val = 0;
            }
        }
        // 最后一起加起来
        while(!s1.empty()) {
            ans += s1.top();
            s1.pop();
        }
        return ans;
    }
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Basic_Calculator_II", "[Stack]"){
	Solution s;
	SECTION("Normal Input") {
		REQUIRE(s.calculate("30+  2*2") == 34);
        REQUIRE(s.calculate("  -30+  2*2") == -26);
	}
}