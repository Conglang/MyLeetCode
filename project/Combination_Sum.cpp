//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a set of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
* 
* The same repeated number may be chosen from C unlimited number of times.
* 
* Note:
* All numbers (including target) will be positive integers.
* Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
* The solution set must not contain duplicate combinations.
* For example, given candidate set 2,3,6,7 and target 7, 
* A solution set is: 
* [7] 
* [2, 2, 3] 
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 深搜。时间复杂度O(n!)，空间复杂度O(n)。
class Solution {
public:
	vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		vector<vector<int> > result;	// 最终结果。
		if (candidates.empty() || target < 1) return result;
		sort(candidates.begin(),candidates.end());	
		vector<int> sequence;	// 一个可行排列。
		dfs(result,sequence,0,target,candidates);
		return result;
	}
	void dfs(vector<vector<int> >& result, vector<int>& sequence, int start, int gap, const vector<int> &candidates)
	{
		if (gap == 0)	// 找到一个合法解。
		{
			//sort(sequence.begin(),sequence.end());
			result.push_back(sequence);
			return;
		}
		for (int i = start; i < candidates.size(); ++i)	// 扩展状态。
		{
			if (gap < candidates[i]) return;	// 剪枝。
			sequence.push_back(candidates[i]);
			dfs(result,sequence,i,gap-candidates[i],candidates);	// 扩展。
			sequence.pop_back();	// 撤销动作。
		}
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Combination_Sum", "[Depth-First Search]"){
	Solution sln;
	vector<int> candidates;
	vector<vector<int> > result;
	SECTION("Empty Input") {
		REQUIRE(sln.combinationSum(candidates,0) == result);
	}
	SECTION("Normal Input1") {
		candidates.push_back(1);
		result.push_back(vector<int>(2,1));
		REQUIRE(sln.combinationSum(candidates,2) == result);
	}
	SECTION("Normal Input2") {
		int temp[4] = {2,3,6,7};
		candidates.assign(temp,temp+4);
		int r[3] = {2,2,3};
		result.push_back(vector<int>(r,r+3));
		result.push_back(vector<int>(1,7));
		REQUIRE(sln.combinationSum(candidates,7) == result);
	}
}