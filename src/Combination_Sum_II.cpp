//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a collection of candidate numbers (C) and a target number (T),
* find all unique combinations in C where the candidate numbers sums to T.
* 
* Each number in C may only be used once in the combination.
* 
* Note:
* All numbers (including target) will be positive integers.
* Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
* The solution set must not contain duplicate combinations.
* For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
* A solution set is: 
* [1, 7] 
* [1, 2, 5] 
* [2, 6] 
* [1, 1, 6] 
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 深搜。时间复杂度O(n!)，空间复杂度O(n)。
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
        vector<vector<int> > result;
		if (num.empty() || target < 1) return result;
		sort(num.begin(),num.end(), [](int a, int b){return a > b;});	// 最终结果。
		vector<int> sequence;	// 一个可行排列。
		dfs(result,sequence,0,target,num);
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
		int previous = -1;
		for (int i = start; i < candidates.size(); ++i)	// 扩展状态。
		{
		    if (previous == candidates[i]) continue;
			if (gap < candidates[i]) continue;	// 剪枝。
			previous = candidates[i];
			sequence.push_back(candidates[i]);
			dfs(result,sequence,i+1,gap-candidates[i],candidates);	// 扩展。
			sequence.pop_back();	// 撤销动作。
		}
	}

};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Combination_Sum_II", "[Depth-First Search]"){
	Solution sln;
	vector<int> nums;
	vector<vector<int> > result;
	SECTION("Empty Input") {
		REQUIRE(sln.combinationSum2(nums,0) == result);
	}
	SECTION("Normal Input1") {
		nums.push_back(1);
		result.push_back(vector<int>(1,1));
		REQUIRE(sln.combinationSum2(nums,1) == result);
	}
	SECTION("Normal Input2") {
		int temp[7] = {10,1,2,7,6,1,5};
		nums.assign(temp,temp+7);
		int r1[2] = {1,7};
		int r2[3] = {1,2,5};
		int r3[2] = {2,6};
		int r4[3] = {1,1,6};
		result.push_back(vector<int>(r1,r1+2));
		result.push_back(vector<int>(r2,r2+3));
		result.push_back(vector<int>(r3,r3+2));
		result.push_back(vector<int>(r4,r4+3));
		sort(result.begin(),result.end());
		REQUIRE(sln.combinationSum2(nums,8) == result);
	}
}