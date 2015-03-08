//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of integers, every element appears three times except for one. Find that single one.
* 
* Note:
* Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2
#ifdef W1
/*
*	����һ������Ϊsizeof(int)������count[sizeof(int)], 
*	count[i]��ʾ����iλ���ֵ�1�Ĵ�����
*	���count[i]��3��������������ԣ�
*	����ͰѸ�λȡ������ɴ𰸡�
*/
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
class Solution {
public:
	int singleNumber(int A[], int n) {
		int result(0);
		const int bit_len = sizeof(int) * 8;
		int count[bit_len];
		fill_n(&count[0], bit_len, 0);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < bit_len; ++j)
			{
				count[j] += (A[i] >> j) & 1;
				count[j] %= 3;
			}
		}
		for (int i = 0; i < bit_len; ++i)
		{
			result += count[i] << i;
		}
		return result;
	}
};
#endif

#ifdef W2
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
/*
��one��¼����ǰ�����Ԫ��Ϊֹ��������1����"1��"��mod 3֮���1��������Щ������λ��
��two��¼����ǰ����ı���Ϊֹ��������1����"2��"��mod 3֮���2��������Щ������λ��
��one��two�е�ĳһλͬʱΪ1ʱ��ʾ�ö�����λ��1������3�Σ���ʱ��Ҫ���㡣
���ö�����ģ�����������㡣����one��¼�������ս����
*/
class Solution {
public:
	int singleNumber(int A[], int n) {
		int one = 0, two = 0, three = 0;
		for (int i = 0; i < n; ++i) {
			two |= (one & A[i]);
			one ^= A[i];
			three = ~(one & two);
			one &= three;
			two &= three;
		}
		return one;
	}
};
#endif

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Single_Number_II", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.singleNumber(NULL,0) == 0);
	}
	SECTION("Normal Input"){
		int A[8] = {1,1,1,2,2,3,3,3};
		REQUIRE(s.singleNumber(A,8) == 2);
	}
}