//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
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
#include "project/include.h"
#define W1

#ifdef W1
// My Way，时间复杂度O(n^2)，空间复杂度O(1)
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<vector<int> > result;
#if __cplusplus < 201103L
		vector<int> temp;
		result.push_back(temp);
		for (vector<int>::iterator it = S.begin(); it != S.end(); ++it)
		{
			int elem = *it;
			vector<vector<int> > acopy(result);
			for (vector<vector<int> >::iterator i = acopy.begin(); i != acopy.end(); ++i)
			{
				vector<int> prev = *i;
#else
		result.push_back(vector<int>{});
		for (auto elem : S)
		{
			vector<vector<int> > acopy(result);
			for (auto prev : acopy)
			{
#endif
				prev.push_back(elem);
				result.push_back(prev);
			}
		}
		return result;
	}
};
#endif

#ifdef W2
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
#endif

#ifdef W3
// Learned Way 2
// 二进制法，时间复杂度O(n^2)，空间复杂度O(1)
/*
集合的元素不超过int位数。用一个int整数表示位向量，第i位为1，则表示
选择S[i]，为0则不选择。例如S={A,B,C,D}，则0110=6表示子集 {B,C}。
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
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Subsets", "[Subsets]"){
	Solution s;
	SECTION("Empty Vector"){
		vector<int> num;
		vector<vector<int> > result(1, num);
		REQUIRE(s.subsets(num) == result);
	}
	SECTION("Normal Vector"){
		int temp[3] = {1, 2, 3};
		vector<int> sum(temp, temp+3);
		vector<vector<int> > my(s.subsets(sum));
		vector<int> a(1, 3);
		vector<int> b(1, 1);
		vector<int> c(1, 2);
		vector<int> d(3, 3);
		d[0] = 1;
		d[1] = 2;
		vector<int> e(2, 3);
		e[0] = 1;
		vector<int> f(2, 3);
		f[0] = 2;
		vector<int> g(2, 2);
		g[0] = 1;
		vector<int> h;
		vector<vector<int> > result;
		result.push_back(a);
		result.push_back(b);
		result.push_back(c);
		result.push_back(d);
		result.push_back(e);
		result.push_back(f);
		result.push_back(g);
		result.push_back(h);
		sort(result.begin(), result.end());
		sort(my.begin(), my.end());
		REQUIRE(my == result);
	}
}
