//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/1
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array and a value, remove all instances of that value in place and return the new length.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//--------------------------------------------------------------------------------------------------------------*/
// My way
class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		int i = 0;
		int index = 0;
		while (index < n)
		{
			if (A[index] == elem)
			{
				++index;
			}else
			{
				A[i++] = A[index++];
			}
		}
		return i;
	}
};