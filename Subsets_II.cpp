//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/9
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a collection of integers that might contain duplicates, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,2], a solution is:

[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]
//--------------------------------------------------------------------------------------------------------------*/
// My Way
// �������һ��Ԫ����ͬ���Ͱ���һ��Ԫ�ؿ�ʼʱ֮ǰ�����н��ȫ���ų�����
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end());

		vector<vector<int> > result;
		result.push_back(vector<int>{});
		int last_elem{INT_MIN};
		int last_2_result = 0;
		int last_result = result.size();
		for (auto elem : S)
		{
			vector<vector<int> > acopy;
			if (elem != last_elem)  {acopy.assign(result.begin(),								result.end());}
			else									{acopy.assign(result.begin() + last_2_result,	result.end());}

			for (auto prev : acopy)
			{
				prev.push_back(elem);
				result.push_back(prev);
			}
			last_elem = elem;
			last_2_result = last_result;
			last_result = result.size();
		}
		return result;
	}
};

// Learned Way 1
// д��������ʱ�临�Ӷ� O(2^n) ���ռ临�Ӷ� O(1)
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end()); // ��������
		vector<vector<int> > result(1);
		size_t previous_size = 0;
		for (size_t i = 0; i < S.size(); ++i) {
			const size_t size = result.size();
			for (size_t j = 0; j < size; ++j) {
				if (i == 0 || S[i] != S[i-1] || j >= previous_size) {
					result.push_back(result[j]);
					result.back().push_back(S[i]);
				}
			}
			previous_size = size;
		}
		return result;
	}
};

// Learned Way 2
// �����Ʒ���ʱ�临�Ӷ� O(2^n) ���ռ临�Ӷ� O(1)
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end()); // ��������
		// �� set ȥ�أ������� unordered_set����Ϊ���Ҫ������
		set<vector<int> > result;
		const size_t n = S.size();
		vector<int> v;
		for (size_t i = 0; i < 1U << n; ++i) {
			for (size_t j = 0; j < n; ++j) {
				if (i & 1 << j)
					v.push_back(S[j]);
			}
			result.insert(v);
			v.clear();
		}
		vector<vector<int> > real_result;
		copy(result.begin(), result.end(), back_inserter(real_result));
		return real_result;
	}
};