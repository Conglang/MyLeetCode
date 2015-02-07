//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/7
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
//--------------------------------------------------------------------------------------------------------------*/
// My Way
// 时间复杂度O(n)，空间复杂度O(1)
class Solution {
public:
	void sortColors(int A[], int n) {
		int ired = -1;
		int iblue = n;
		int ileft = 0;
		int iright = n-1;
		while (iright > ired || ileft < iblue)
		{
			while (ired < n-1 && A[ired + 1] < 1) {++ired;}
			while (iblue > 0 && A[iblue - 1] > 1) {--iblue;}
			while (ileft < iblue && A[ileft] < 2) {++ileft;}
			if (ileft < iblue) {swap(A[ileft], A[--iblue]);}
			while (iright > ired && A[iright] > 0) {--iright;}
			if (iright > ired) {swap(A[iright], A[++ired]);}
		}
	}
};

// Learned Way 1
// 和我的一个思路，但是简洁很多。
class Solution {
public:
	void sortColors(int A[], int n) {
		// 一个是 red 的 index，一个是 blue 的 index，两边往中间走
		int red = 0, blue = n - 1;
		for (int i = 0; i < blue + 1;) {
			if (A[i] == 0)
				swap(A[i++], A[red++]);
			else if (A[i] == 2)
				swap(A[i], A[blue--]);
			else
				i++;
		}
	}
};

// Learned Way 2
// use partition()
// 时间复杂度 O(n) ，空间复杂度 O(1)
class Solution {
public:
	void sortColors(int A[], int n) {
		partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n, bind1st(equal_to<int>(), 1));
	}
};

// Learned Way 3
// 重新实现 partition()
// 时间复杂度 O(n) ，空间复杂度 O(1)
class Solution {
public:
	void sortColors(int A[], int n) {
		partition(partition(A, A + n, bind1st(equal_to<int>(), 0)), A + n, bind1st(equal_to<int>(), 1));
	}
private:
	template<typename ForwardIterator, typename UnaryPredicate>
	ForwardIterator partition(ForwardIterator first, ForwardIterator last, UnaryPredicate pred)
	{
			auto pos = first;
			for (; first != last; ++first)
				if (pred(*first))
					swap(*first, *pos++);
			return pos;
	}
};