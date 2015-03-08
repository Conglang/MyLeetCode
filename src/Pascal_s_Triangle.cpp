//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given numRows, generate the first numRows of Pascal's triangle.
* 
* For example, given numRows = 5,
* Return
* 
* [
* [1],
* [1,1],
* [1,2,1],
* [1,3,3,1],
* [1,4,6,4,1]
* ]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1

#ifdef W1
// ������
// ��һ�е�һ��Ԫ�غ����һ��Ԫ�ظ�ֵΪ1���м��ÿ��Ԫ�أ�������һ�е����ϽǺ����Ͻ�Ԫ��֮�͡�
// ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)��
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result;
		if (numRows == 0) return result;
		result.push_back(vector<int>(1,1));	// ��һ��
		for (int i = 2; i <= numRows; ++i)
		{
			vector<int> current(i,1);	// ����
			const vector<int>& prev = result[i-2];	// ��һ��
			for (int j = 1; j < i-1; ++j)
			{
				current[j] = prev[j-1] + prev[j];	// ���ϽǺ����Ͻ�֮��
			}
			result.push_back(current);
		}
		return result;
	}
};
#endif

#ifdef W2
// ���ҵ���
// ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)��
class Solution {
public:
	vector<vector<int> > generate(int numRows) {
		vector<vector<int> > result;
		if (numRows == 0) return result;
		vector<int> array;
		for (int i = 1; i <= numRows; ++i)
		{
			for (int j = i-2; j > 0; --j)
			{
				// �������󣬸��Ǵ������顣���޸ĵ�0λ��1�����������������һλ�ġ�
				array[j] = array[j-1] + array[j];
			}
			array.push_back(1);	// �������һλ1��
			result.push_back(array);
		}
		return result;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Pascal's Triangle", "[Detail]"){
	Solution sln;
	vector<vector<int> > result;
	SECTION("Empty Input"){
		REQUIRE(sln.generate(0) == result);
	}
	SECTION("Normal Input"){
		vector<int> r1(1,1);
		vector<int> r2(2,1);
		int t3[3] = {1,2,1};
		vector<int> r3(t3, t3+3);
		int t4[4] = {1,3,3,1};
		vector<int> r4(t4, t4+4);
		int t5[5] = {1,4,6,4,1};
		vector<int> r5(t5, t5+5);
		result.push_back(r1);
		result.push_back(r2);
		result.push_back(r3);
		result.push_back(r4);
		result.push_back(r5);
		REQUIRE(sln.generate(5) == result);
	}
}