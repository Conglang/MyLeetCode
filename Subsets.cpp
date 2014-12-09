//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/9
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
//--------------------------------------------------------------------------------------------------------------*/
// My Way��ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<vector<int> > result;
		result.push_back(vector<int>{});

		for (auto elem : S)
		{
			vector<vector<int> > acopy(result);
			for (auto prev : acopy)
			{
				prev.push_back(elem);
				result.push_back(prev);
			}
		}
		return result;
	}
};
// Learned Way 1
// ���õ�д����ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end()); // ���Ҫ������
		vector<vector<int> > result(1);
		for (auto elem : S) {
			result.reserve(result.size() * 2);
			auto half = result.begin() + result.size();
			copy(result.begin(), half, back_inserter(result));
			for_each(half, result.end(), [&elem](decltype(result[0]) &e){
				e.push_back(elem);
			});
		}
		return result;
	}
};

// Learned Way 2
// �����Ʒ���ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(1)
/*
���ϵ�Ԫ�ز����� int λ������һ�� int ������ʾλ�������� i λΪ 1�����ʾ
ѡ�� S [ i ]��Ϊ 0 ��ѡ������ S={A,B,C,D}���� 0110=6 ��ʾ�Ӽ� {B,C}��
*/
class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end()); // ���Ҫ������
		vector<vector<int> > result;
		const size_t n = S.size();
		vector<int> v;
		for (size_t i = 0; i < 1 << n; i++)		// ������������
		{
			for (size_t j = 0; j < n; j++)	// ������������
			{
				if (i & 1 << j) v.push_back(S[j]);	// ��һλ��1�ͼ����ĸ���Ӧ����
			}
			result.push_back(v);
			v.clear();
		}
		return result;
	}
};