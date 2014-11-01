//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].
//--------------------------------------------------------------------------------------------------------------*/
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		set<int> exist_value;
		int index = 0;
		int i = 0;
		while (index < n)
		{
			if (exist_value.find(A[index]) != exist_value.end())
			{
				++index;
			}else
			{
				exist_value.insert(A[index]);
				A[i] = A[index];
				++i;
				++index;
			}
		}
		return i;
	}
};