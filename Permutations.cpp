//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a collection of numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], and [3,2,1].
//--------------------------------------------------------------------------------------------------------------*/
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

// Learned Way 2
// 自己实现next_permutation()，参看Next_Permutation。
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