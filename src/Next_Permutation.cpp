//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/9
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
* 
* If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
* 
* The replacement must be in-place, do not allocate extra memory.
* 
* Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
* 1,2,3 �� 1,3,2
* 3,2,1 �� 1,2,3
* 1,1,5 �� 1,5,1
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// http://fisherlei.blogspot.com/2012/12/leetcode-next-permutation.html
/*
*	Example		 6	 8	 7	4	3	2
*	Step1		(6)	 8	 7	4	3	2
*	Step2		 6	 8	(7)	4	3	2
*	Step3		 7	(8	 6	4	3	2)
*	Step4		 7	 2	 3	4	6	8
*	
*	1. From right to left, find the first digit (PartitionNumber) which violate the increase trend,
*		in this example, 6 will be selected since 8,7,4,3,2 already in a increase trend.
*	2. From right to left, find the first digit which larger than PartitionNumber, call it changeNumber.
*		Here the 7 will be selected.
*	3. Swap the PartitionNumber and ChangeNumber.
*	4. Reverse all the digit on the right of partition index.
*/
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
class Solution {
public:
	void nextPermutation(vector<int> &num) {
		if (num.size() < 2) {return;}
		vector<int>::reverse_iterator PartitionIt = num.rend();
		vector<int>::reverse_iterator ChangeIt = num.rend();
		for (vector<int>::reverse_iterator it = num.rbegin(); it != num.rend()-1; ++it)
		{
			if (*it > *(it+1))
			{
				PartitionIt = it+1;
				break;
			}
		}
		if (PartitionIt == num.rend())
		{
			sort(num.begin(), num.end()); return;
		}
		for (vector<int>::reverse_iterator it = num.rbegin(); it != num.rend()-1; ++it)
		{
			if (*it > *PartitionIt)
			{
				ChangeIt = it;
				break;
			}
		}
		*PartitionIt += *ChangeIt;
		*ChangeIt = *PartitionIt - *ChangeIt;
		*PartitionIt -= *ChangeIt;
		reverse(num.rbegin(), PartitionIt);
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Next_Permutation", "[Arrays]"){
	Solution s;
	SECTION("Empty Input") {
		vector<int> num;
		vector<int> empty;
		s.nextPermutation(num);
		REQUIRE(num == empty);
	}
	SECTION("Normal Input") {
		int t1[3] = {1,2,3};
		vector<int> num(t1, t1+3);
		int r1[3] = {1,3,2};
		vector<int> res(r1, r1+3);
		s.nextPermutation(num);
		REQUIRE(num == res);
		num.assign(1,1);
		res.assign(1,1);
		s.nextPermutation(num);
		REQUIRE(num == res);
		int t2[3] = {3,2,1};
		int r2[3] = {1,2,3};
		num.assign(t2, t2+3);
		res.assign(r2, r2+3);
		s.nextPermutation(num);
		REQUIRE(num == res);
	}
}