//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* The set [1,2,3,…,n] contains a total of n! unique permutations.
* 
* By listing and labeling all of the permutations in order,
* We get the following sequence (ie, for n = 3):
* 
* "123"
* "132"
* "213"
* "231"
* "312"
* "321"
* Given n and k, return the kth permutation sequence.
* 
* Note: Given n will be between 1 and 9 inclusive.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 康托编码
/*
*	编码：
*	举例：{1,2,3} 按从小到大排列一共6个：123 132 213 231 312 321。想知道321是{1,2,3}中第几个大的数。
*	第一位是3，小于3的数有1、2 。所以有2*2!个。
*	第二位是2，小于2的数只有1。所以有1*1!=1个。
*	所以小于32的{1,2,3}排列数有2*2!+1*1!=5个。
*	所以321是第6个大的数。2*2!+1*1!是康托展开。
*	解码：
*	举例：如何找出第16个（按字典序的）{1,2,3,4,5}的全排列？
*	1. 首先用16-1得到15
*	2. 用15去除4! 得到0余15
*	3. 用15去除3! 得到2余3
*	4. 用3去除2! 得到1余1
*	5. 用1去除1! 得到1余0
*	有0个数比它小的数是1，所以第一位是1
*	有2个数比它小的数是3，但1已经在之前出现过了所以是4
*	有1个数比它小的数是2，但1已经在之前出现过了所以是3
*	有1个数比它小的数是2，但1,3,4都出现过了所以是5
*	最后一个数只能是2
*	所以排列为1 4 3 5 2
*/
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
	string getPermutation(int n, int k) {
		if (!n) {return "";}
		string s(n, '0');
		string result;
		// 生成输入序列
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
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Permutation_Sequence", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.getPermutation(0,0) == "");
	}
	SECTION("Normal Input"){
		REQUIRE(s.getPermutation(5,16) == "14352");
	}
}