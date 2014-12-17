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
// My Way��ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
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
// ���õ�д����ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end()); // ���Ҫ������
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
// �����Ʒ���ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
/*
���ϵ�Ԫ�ز�����intλ������һ��int������ʾλ��������iλΪ1�����ʾ
ѡ��S[i]��Ϊ0��ѡ������S={A,B,C,D}����0110=6��ʾ�Ӽ� {B,C}��
*/
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end()); // ���Ҫ������
		vector<vector<int> > result;
		const size_t n = S.size();
		vector<int> v;
		for (size_t i = 0; i < 1 << n; i++)		// ������������
		{
			for (size_t j = 0; j < n; j++)	// ������������
			{
				if (i & 1 << j) v.push_back(S[j]);	// ��һλ��1�ͼ����ĸ���Ӧ����
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
