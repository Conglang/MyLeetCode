//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 和Permutations解法一样。
class Solution {
public:
	vector<vector<int> > permuteUnique(vector<int> &num) {
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