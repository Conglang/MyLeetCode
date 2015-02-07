//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/6
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
* 
* For example,
* Given [100, 4, 200, 1, 3, 2],
* The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
* 
* Your algorithm should run in O(n) complexity.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 时间复杂度O(n)，空间复杂度O(n)。
// 一看到O(n)，就想起来哈希表。如果要排序，至少要O(nlogn)，所以不能排序。
class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		if (num.empty()) {return 0;}
		if (num.size() == 1) {return 1;}
		unordered_map<int, bool> used;
#if __cplusplus < 201103L
		for (auto t = num.begin(); t != num.end(); ++t)
		{
			int i = *t;
#else
		for (auto i : num)
		{
#endif
			used[i] = false;	// 首先标记列表中所有的元素都未访问
		}
		int max_len(0);
#if __cplusplus < 201103L
		for (auto t = num.begin(); t != num.end(); ++t)
		{
			int i = *t;
#else
		for (auto i : num)	// 遍历元素
		{
#endif
		
			if(used[i]) continue;	// 如果未访问过
			int length = 1;
			used[i] = true;
			// 看看比它大的连续数字是否存在于列表
			for (int j = i + 1; used.find(j) != used.end(); ++j)
			{
				used[j] = true;
				++length;
			}
			// 看看比它小的连续数字是否存在于列表
			for (int j = i - 1; used.find(j) != used.end(); --j)
			{
				used[j] = true;
				++length;
			}
			max_len = max(max_len, length);
		}
		return max_len;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Longest_Consecutive_Sequence", "[Arrays]"){
	Solution s;
	SECTION("Empty Input") {
		vector<int> num;
		REQUIRE(s.longestConsecutive(num) == 0);
		num.assign(1,1);
		REQUIRE(s.longestConsecutive(num) == 1);
	}
	SECTION("Normal Input") {
		int temp[8] = {12,1,6,2,4,13,5,3};
		vector<int> num(temp, temp+8);
		REQUIRE(s.longestConsecutive(num) == 6);
	}
}
