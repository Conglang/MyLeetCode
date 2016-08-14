//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/9
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a collection of integers that might contain duplicates, S, return all possible subsets.
* 
* Note:
* Elements in a subset must be in non-descending order.
* The solution set must not contain duplicate subsets.
* For example,
* If S = [1,2,2], a solution is:
* 
* [
*   [2],
*   [1],
*   [1,2,2],
*   [2,2],
*   [1,2],
*   []
* ]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1

#ifdef W1
// д��������ʱ�临�Ӷ�O(2^n)���ռ临�Ӷ�O(1)
class Solution {
public:
	vector<vector<int> > subsetsWithDup(vector<int> &S) {
		sort(S.begin(), S.end()); // ��������
		vector<vector<int> > result(1);
		size_t previous_size = 0;
		for (size_t i = 0; i < S.size(); ++i) {
			const size_t size = result.size();
			for (size_t j = 0; j < size; ++j) {
				// Ҫô�ǳ�ʼ״̬��Ҫô��ǰһ��Ԫ�ز��ظ���Ҫô�ų�����һ��Ԫ������֮ǰ�Ĳ��֡�
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
#endif

#ifdef W2
// �����Ʒ���ʱ�临�Ӷ� O(2^n) ���ռ临�Ӷ� O(1)
// ��setȥ�ؾͱȽ�û��˼�ˡ�
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
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Subsets_II", "[Brute Force]"){
	Solution s;
	SECTION("Empty Vector"){
		vector<int> num;
		vector<vector<int> > result(1, num);
		REQUIRE(s.subsetsWithDup(num) == result);
	}
	SECTION("Normal Vector"){
		int temp[3] = {1, 2, 2};
		vector<int> sum(temp, temp+3);
		vector<vector<int> > my(s.subsetsWithDup(sum));
		vector<int> a(1, 2);
		vector<int> b(1, 1);
		vector<int> c(3, 2);
		c[0] = 1;
		vector<int> d(2, 2);
		vector<int> e(2, 2);
		e[0] = 1;
		vector<int> f;
		vector<vector<int> > result;
		result.push_back(a);
		result.push_back(b);
		result.push_back(c);
		result.push_back(d);
		result.push_back(e);
		result.push_back(f);
		sort(result.begin(), result.end());
		sort(my.begin(), my.end());
		REQUIRE(my == result);
	}
}
