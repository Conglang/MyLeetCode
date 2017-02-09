//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/24
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string of numbers and operators, return all possible results from computing
* all the different possible ways to group numbers and operators. The valid operators are +, - and *.
* 
* 
* Example 1
* Input: "2-1-1".
* 
* ((2-1)-1) = 0
* (2-(1-1)) = 2
* Output: [0, 2]
* 
* 
* Example 2
* Input: "2*3-4*5"
* 
* (2*(3-(4*5))) = -34
* ((2*3)-(4*5)) = -14
* ((2*(3-4))*5) = -10
* (2*((3-4)*5)) = -10
* (((2*3)-4)*5) = 10
* Output: [-34, -14, -10, -10, 10]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 首先想到了树，然后想到了递归，数的关键节点处也就是递归分裂的地方。
// Time Complexity O(nlogn)
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> output;
        for (int i = 0; i < input.size(); ++i)
        {
            char c = input[i];
            if (ispunct(c))
            {
                vector<int> left = diffWaysToCompute(input.substr(0, i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for (int l = 0; l < left.size(); ++l)
                {
                    for (int r = 0; r < right.size(); ++r)
                    {
                        int a(left[l]), b(right[r]);
                        output.push_back(c == '+' ? a+b : c=='-' ? a-b : a*b);
                    }
                }
            }
        }
        return output.size() ? output : vector<int>(1,stoi(input));
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Different_Ways_to_Add_Parentheses", "[Devide and Conquer]") {
	Solution s;
	SECTION("Normal Input 1 ") {
		vector<int> output = s.diffWaysToCompute("2-1-1");
		int pre[2] = {0,2};
		sort(output.begin(), output.end());
		REQUIRE(output == vector<int>(pre, pre+2));
	}
	SECTION("Normal Input 2") {
		vector<int> output = s.diffWaysToCompute("2*3-4*5");
		int pre[5] = {-34, -14, -10, -10, 10};
		sort(output.begin(), output.end());
		REQUIRE(output == vector<int>(pre, pre+5));
	}
}
