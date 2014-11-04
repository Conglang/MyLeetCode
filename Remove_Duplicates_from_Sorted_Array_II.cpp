//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/4
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
//--------------------------------------------------------------------------------------------------------------*/
// My Way
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		map<int, int> existed;
		int index(0), i(0);
		while (index < n)
		{
			if ( existed.find(A[index]) != existed.end() && existed[A[index]] >= 2 )
			{
				++index;
			}else
			{
				if (existed.find(A[index]) == existed.end()) {existed.insert(make_pair(A[index], 1));}
				else {existed[A[index]] += 1;}
				A[i] = A[index];
				++i;
				++index;
			}
		}
		return i;
	}
};

// 未审清题，是已排序的数组。
// 更切题的方法。
class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (!n) {return 0;}
		int count(1);
		int index(0);
		for (int i = 1; i < n; ++i)
		{
			if (A[index] == A[i] && count < 2)
			{
				A[++index] = A[i];
				++count;
			}
			if (A[index] != A[i])
			{
				A[++index] = A[i];
				count = 1;
			}
		}
		return index + 1;
	}
};