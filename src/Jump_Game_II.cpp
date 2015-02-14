//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of non-negative integers, you are initially positioned at the first index of the array.
* 
* Each element in the array represents your maximum jump length at that position.
* 
* Your goal is to reach the last index in the minimum number of jumps.
* 
* For example:
* Given array A = [2,3,1,1,4]
* 
* The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
#define W2
#ifdef W1
// �������ң�ÿ�δӿ�����Χ����˵��Ҷ˱������ҵ���������Զ�ľ��룬Ȼ�������Ƶ���һ�ε��Ҷ˺�һλ��
// |----|=======|*******|
// ÿһ��ε�����һ���ҵ���Զ����������һ��Σ���һ���������һ�������������Զ��ֱ��������
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
class Solution {
public:
	int jump(int A[], int n) {
		if (!A || !n) return 0;
		if (n == 1) return 0;
		int left(0),right(0);	// [left, right]�ǵ�ǰ�ܸ��ǵ�����
		int step(0);	// ��С����
		while (left <= right)
		{
			++step;
			const int old_right = right;
			for (int i = left; i <= old_right; ++i)
			{
				int new_right = i + A[i];
				if (new_right >= n-1) {return step;}
				if (new_right > right) {right = new_right;}
			}
			left = old_right + 1;
		}
		return 0;
	}
};
#endif

#ifdef W2
// �����ң�ÿ�γ�����һ��������Զ���룬�ͰѲ�����1��
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
class Solution {
public:
	int jump(int A[], int n) {
		int result(0);
		int last(0);	// �ܴﵽ����Զ���롣
		int cur(0);	// result+1���ܵ������Զ���롣
		for (int i = 0; i < n; ++i)
		{
			if (i > last)
			{
				if (cur <= last) return 0;	// ��������߸�Զ��˵���޷��������0��
				last = cur;
				++result;
			}
			cur = max(cur, i+A[i]);
		}
		return result;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Jump_Game_II", "[Greedy Technique]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.jump(NULL,0) == 0);
	}
	SECTION("Normal Input") {
		int A[5] = {2,3,1,1,4};
		int B[5] = {3,2,1,0,4};
		int C[5] = {2,0,1,1,4};
		int D[5] = {3,3,1,0,4};
		REQUIRE(sln.jump(A,5) == 2);
		REQUIRE(sln.jump(B,5) == 0);
		REQUIRE(sln.jump(C,5) == 3);
		REQUIRE(sln.jump(D,5) == 2);
	}
}