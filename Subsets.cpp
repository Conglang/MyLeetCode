//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/9
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
//--------------------------------------------------------------------------------------------------------------*/
// My Way，时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<vector<int> > result;
		result.push_back(vector<int>{});

		for (auto elem : S)
		{
			vector<vector<int> > acopy(result);
			for (auto prev : acopy)
			{
				prev.push_back(elem);
				result.push_back(prev);
			}
		}
		return result;
	}
};
// Learned Way 1
// 更好的写法，时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end()); // 输出要求有序
		vector<vector<int> > result(1);
		for (auto elem : S) {
			result.reserve(result.size() * 2);
			auto half = result.begin() + result.size();
			copy(result.begin(), half, back_inserter(result));
			for_each(half, result.end(), [&elem](decltype(result[0]) &e){
				e.push_back(elem);
			});
		}
		return result;
	}
};

// Learned Way 2
// 二进制法，时间复杂度O(n^2)，空间复杂度O(1)
/*
集合的元素不超过 int 位数。用一个 int 整数表示位向量，第 i 位为 1，则表示
选择 S [ i ]，为 0 则不选择。例如 S={A,B,C,D}，则 0110=6 表示子集 {B,C}。
*/
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end()); // 输出要求有序
		vector<vector<int> > result;
		const size_t n = S.size();
		vector<int> v;
		for (size_t i = 0; i < 1 << n; i++)		// 生成所有序列
		{
			for (size_t j = 0; j < n; j++)	// 解析二进制数
			{
				if (i & 1 << j) v.push_back(S[j]);	// 哪一位是1就加入哪个对应数字
			}
			result.push_back(v);
			v.clear();
		}
		return result;
	}
};