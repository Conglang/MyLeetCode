//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
//--------------------------------------------------------------------------------------------------------------*/
#include "project/include.h"
#define W2

#ifdef W1
// Learned Way 1
// 标准库方法next_permutation()直接用的话。
// 时间复杂度 O(n!) ，空间复杂度 O(1)
class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > result;
		sort(num.begin(), num.end());
		do {
			result.push_back(num);
		} while(next_permutation(num.begin(), num.end()));
		return result;
	}
};
#endif

#ifdef W2
// Learned Way 2
// 自己实现next_permutation()，参看Next_Permutation。
class Solution {
public:
	vector<vector<int> > permute(vector<int> &num) {
		vector<vector<int> > result;
		if (num.empty()) return result;
		sort(num.begin(), num.end());
		do {
			result.push_back(num);
		} while(next_permutation(num.begin(), num.end()));
		return result;
	}
private:
	template<typename BidiIt>
	bool next_permutation(BidiIt first, BidiIt last)
	{
		// Get a reversed range to simplify reversed traversal.
		const auto rfirst = reverse_iterator<BidiIt>(last);
		const auto rlast = reverse_iterator<BidiIt>(first);

		// Begin from the second last element to the first element.
		auto pivot = next(rfirst);

		// Find `pivot`, which is the first element that is no less than its
		// successor. `Prev` is used since `pivort` is a `reversed_iterator`.
		while (pivot != rlast && *pivot >= *prev(pivot))
		{
			++pivot;
		}
		// No such elemenet found, current sequence is already the largest
		// permutation, then rearrange to the first permutation and return false.
		if (pivot == rlast)
		{
			reverse(rfirst, rlast);
			return false;
		}
		// Scan from right to left, find the first element that is greater than
		// `pivot`.
		auto change = find_if(rfirst, pivot, bind1st(less<int>(), *pivot));

		swap(*change, *pivot);
		reverse(rfirst, pivot);

		return true;
	}
};
#endif

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Permutations", "[Brute Force]"){
	Solution s;
	SECTION("Empty Vector"){
		vector<int> num;
		REQUIRE(s.permute(num).empty());
	}
	SECTION("One Element Vector"){
		vector<int> num(1, 1);
		vector<vector<int> > result(1, num);
		REQUIRE(s.permute(num) == result);
	}
	SECTION("Normal Vector"){
		int temp[3] = {1, 2, 3};
		vector<int> sum(temp, temp+3);
		vector<int> a;
		a.push_back(1);
		a.push_back(2);
		a.push_back(3);
		vector<int> b;
		b.push_back(1);
		b.push_back(3);
		b.push_back(2);
		vector<int> c;
		c.push_back(2);
		c.push_back(1);
		c.push_back(3);
		vector<int> d;
		d.push_back(2);
		d.push_back(3);
		d.push_back(1);
		vector<int> e;
		e.push_back(3);
		e.push_back(1);
		e.push_back(2);
		vector<int> f;
		f.push_back(3);
		f.push_back(2);
		f.push_back(1);
		vector<vector<int> > result;
		result.push_back(a);
		result.push_back(b);
		result.push_back(c);
		result.push_back(d);
		result.push_back(e);
		result.push_back(f);
		REQUIRE(s.permute(sum) == result);
	}
}