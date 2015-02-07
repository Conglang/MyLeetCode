//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/6
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

For example,
Given [100, 4, 200, 1, 3, 2],
The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.

Your algorithm should run in O(n) complexity.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// Important
// 一看到O(n)，就想起来哈希表。
// 可是我标准库不熟，没想起来unordered_map。
class Solution {
public:
	int longestConsecutive(vector<int> &num) {
		if (!num.size()) {return 0;}
		if (num.size() == 1) {return 1;}
		unordered_map<int, bool> used;
		for (auto i : num)
		{
			used[i] = false;
		}
		int max_len(0);
		for (auto i : num)
		{
			if(used[i]) continue;
			int length = 1;
			used[i] = true;

			for (int j = i + 1; used.find(j) != used.end(); ++j)
			{
				used[j] = true;
				++length;
			}

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
