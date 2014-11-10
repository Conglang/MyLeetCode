//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// 康托编码
/*
	利用康托编码的思路，假设有n个不重复的元素，第k个排列是 a(1) , a(2) , a(3) , ..., a(n)，那么a(1)是哪一个位置呢？
	我们把a1去掉，那么剩下的排列为 a(2) , a(3) , ..., a(n), 共计n − 1个元素，n − 1个元素共有(n − 1)!个排列，于是就可以知道 a(1) = k/( n − 1)!。
	同理， a(2) , a(3) , ..., a(n)的值推导如下：
	k(2) = k % (n − 1)!
	a(2) = k(2) / (n − 2)!
	...
	k(n − 1) = k(n − 2) % 2!
	a(n − 1) = k(n − 1) / 1!
	a(n) = 0
*/
class Solution {
public:
	string getPermutation(int n, int k) {
		string s(n, '0');
		string result;
		for (int i = 0; i < n; ++i)
		{
			s[i] += i+1;
		}
		return kth_permutation(s, k);
	}
private:
	int factorial(int n)
	{
		int result = 1;
		for (int i = 1; i <= n; ++i)
		{
			result *= i;
		}
		return result;
	}
	template<typename Sequence>
	Sequence kth_permutation(const Sequence& seq, int k)
	{
		const int n = seq.size();
		Sequence s(seq);
		Sequence result;

		int base = factorial(n-1);
		--k;
		for (int i = n-1; i > 0; k %= base, base /= i, --i)
		{
			auto a = next(s.begin(), k / base);
			result.push_back(*a);
			s.erase(a);
		}
		result.push_back(s[0]);
		return result;
	}
};