//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/7
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a sorted array of integers, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].
//--------------------------------------------------------------------------------------------------------------*/
// My Way
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
// �Ľ��ռ䣺���֡�
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> result(2, -1);
		int left = 0;
		int right = n-1;
		if (A[left] > target || A[right] < target) {return result;}

		while (left < n-1 && A[left] < target) {++left;}
		while (right > -1 && A[right] > target) {--right;}

		if (left < right)
		{
			result[0] = left;
			result[1] = right;
		}else if (left == right)
		{
			result.assign(2, left);
		}
		return result;
	}
};

// Learned Way
// ͵����������ʹ�� STL
// ʱ�临�Ӷ� O(logn)���ռ临�Ӷ� O(1)
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		const int l = distance(A, lower_bound(A, A + n, target));
		const int u = distance(A, prev(upper_bound(A, A + n, target)));
		if (A[l] != target) // not found
			return vector<int> { -1, -1 };
		else
			return vector<int> { l, u };
	}
};

// Learned Way 1
// ����ʵ�� lower_bound �� upper_bound
// ʱ�临�Ӷ� O(logn) ���ռ临�Ӷ� O(1)
class Solution {
public:
	vector<int> searchRange (int A[], int n, int target) {
		auto lower = lower_bound(A, A + n, target);
		auto uppper = upper_bound(lower, A + n, target);
		if (lower == A + n || *lower != target)
			return vector<int> { -1, -1 };
		else
			return vector<int> {distance(A, lower), distance(A, prev(uppper))};
	}
	template<typename ForwardIterator, typename T>
	ForwardIterator lower_bound (ForwardIterator first, ForwardIterator last, T value)
	{
			while (first != last)
			{
				auto mid = next(first, distance(first, last) / 2);
				if (value > *mid) first = ++mid;
				else last = mid;
			}
			return first;
	}
	template<typename ForwardIterator, typename T>
	ForwardIterator upper_bound (ForwardIterator first, ForwardIterator last, T value)
	{
			while (first != last)
			{
				auto mid = next(first, distance (first, last) / 2);
				if (value >= *mid) first = ++mid; // �� lower_bound ���˲�ͬ
				else last = mid;
			}
			return first;
	}
};