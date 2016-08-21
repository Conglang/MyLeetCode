//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/8/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a list of non negative integers, arrange them such that they form the largest number.
* 
* For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
* 
* Note: The result may be very large, so you need to return a string instead of an integer.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(n)
// 关键是想到在sorting的时候用s1+s2 > s2+s1这个做标准。
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strvec;
        for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
        {
            strvec.push_back(to_string((long long)(*it)));
        }
        sort(begin(strvec), end(strvec), [](string s1, string s2){return s1+s2 > s2+s1;});
        string result;
        for (vector<string>::iterator it = strvec.begin(); it != strvec.end(); ++it)
        {
            result += *it;
        }
        while (result[0] == '0' && result.length() > 1)
        {
            result.erase(0,1);
        }
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Largest_Number", "[Sorting]"){
	Solution s;
	SECTION("Normal Input1"){
		int t[5] = {3,30,34,5,9};
		vector<int> input(t,t+5);
		REQUIRE(s.largestNumber(input) == "9534330");
	}
}