//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/01
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Find all possible combinations of k numbers that add up to a number n, 
* given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
* 
* 
* Example 1:
* 
* Input: k = 3, n = 7
* 
* Output:
* 
* [[1,2,4]]
* 
* Example 2:
* 
* Input: k = 3, n = 9
* 
* Output:
* 
* [[1,2,6], [1,3,5], [2,3,4]]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Backtracking
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> path;
        backtracking(result, path, k, n);
        return result;
    }
private:
    void backtracking(vector<vector<int>>& result, vector<int> path, int k, int n)
    {
        if (path.size() == k && n == 0)
        {
            result.push_back(path);
            return;
        }
        if (n < 0 || n > 9*(k-path.size()) || path.size() >= k) return;
        for (int i = path.empty() ? 1 : path.back()+1; i <= 9; ++i)
        {
            if (n - i < 0) break;
            path.push_back(i);
            backtracking(result, path, k, n-i);
            path.pop_back();
        }
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Combination_Sum_III", "[Arrays]"){
	Solution s;
	SECTION("Normal Input 1"){
		int r[3] = {1,2,4};
		vector<vector<int>> result;
		result.push_back(vector<int>(r,r+3));
		REQUIRE(s.combinationSum3(3,7) == result);
	}
	SECTION("Normal Input 2"){
		int r1[3] = {1,2,6};
		int r2[3] = {1,3,5};
		int r3[3] = {2,3,4};
		vector<vector<int>> result;
		result.push_back(vector<int>(r1,r1+3));
		result.push_back(vector<int>(r2,r2+3));
		result.push_back(vector<int>(r3,r3+3));
		REQUIRE(s.combinationSum3(3,9) == result);
	}
}