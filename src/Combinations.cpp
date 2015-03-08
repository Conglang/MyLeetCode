//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/11
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
* 
* For example,
* If n = 4 and k = 2, a solution is:
* 
* [
*   [2,4],
*   [3,4],
*   [2,3],
*   [1,2],
*   [1,3],
*   [1,4],
* ]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

// 递归法。时间复杂度O(n!)，空间复杂度O(n)
class Solution {
public:
	vector<vector<int> > combine(int n, int k) {
		vector<vector<int> > result;
		vector<int> path;
		dfs(n, k, 1, 0, path, result);
		return result;
	}
private:
	// start: start number
	// cur: numbers already have
	static void dfs(int n, int k, int start, int cur, vector<int>& path, vector<vector<int> >&result)
	{
		if (cur == k)   // we already have required number of numbers
		{
			result.push_back(path);
			return;
		}
		for (int i = start; i <= n; ++i)
		{
			path.push_back(i);
			dfs(n, k, i+1, cur+1, path, result);
			path.pop_back();
		}
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Combinations", "[Brute Force]"){
	Solution s;
	SECTION("Empty Input"){
		vector<int> temp;
		vector<vector<int> > result(1, temp);
		REQUIRE(s.combine(0,0) == result);
	}
	SECTION("One Input"){
		vector<int> temp(1, 1);
		vector<vector<int> > result(1, temp);
		REQUIRE(s.combine(1, 1) == result);
	}
	SECTION("Invalid Input"){
		vector<vector<int> > result;
		REQUIRE(s.combine(1, 2) == result);
	}
	SECTION("Normal Input"){
		vector<int> a;
		a.push_back(2); a.push_back(4);
		vector<int> b;
		b.push_back(3); b.push_back(4);
		vector<int> c;
		c.push_back(2); c.push_back(3);
		vector<int> d;
		d.push_back(1); d.push_back(2);
		vector<int> e;
		e.push_back(1); e.push_back(3);
		vector<int> f;
		f.push_back(1); f.push_back(4);
		vector<vector<int> > result;
		result.push_back(a);
		result.push_back(b);
		result.push_back(c);
		result.push_back(d);
		result.push_back(e);
		result.push_back(f);
		vector<vector<int> > my(s.combine(4, 2));
		sort(my.begin(), my.end());
		sort(result.begin(), result.end());
		REQUIRE(my == result);
	}
}