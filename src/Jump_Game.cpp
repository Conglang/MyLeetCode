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
* Determine if you are able to reach the last index.
* 
* For example:
* A = [2,3,1,1,4], return true.
* 
* A = [3,2,1,0,4], return false.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1
#ifdef W1
// ̰�ķ���ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
// ����һ��һ����������������Զ������Χ��������ܲ��ܳ�����߲㡣
class Solution {
public:
	bool canJump(int A[], int n) {
		if(!A || !n) {return true;}
		int reach(1);	// ��1��ʼ�������������������
		// �������������ķ�Χ������������ľ��롣
		for (int i = 0; i < reach && reach < n; ++i)
		{
			reach = max(reach, i + 1 + A[i]);
		}
		// �����ҿ����ľ����Ƿ����n��
		return reach >= n;
	}
};
#endif

#ifdef W2
// ̰�ķ���ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
// ���򣬴���߲���¥�ݣ�һ��һ�����½���������Ϳɵ����λ�ã����ܷ�ص���0�㡣
class Solution {
public:
	bool canJump (int A[], int n) {
		if (!A || !n) return true;
		// ������¥�ݣ��������½����ڼ���
		int left_most = n - 1;
		for (int i = n - 2; i >= 0; --i)
			if (i + A[i] >= left_most)
				left_most = i;
		return left_most == 0;
	}
};
#endif

#ifdef W3
// ��̬�滮��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)��
// ��״̬Ϊf[i]����ʾ��0�������ߵ�A[i]ʱʣ������������״̬ת�Ʒ���Ϊf[i]=max(f[i-1),A[i-1])-1;
class Solution {
public:
	bool canJump(int A[], int n) {
		if (!A || !n) return true;
		vector<int> f(n, 0);
		f[0] = 0;
		for (int i = 1; i < n; i++) {
			f[i] = max(f[i - 1], A[i - 1]) - 1;
			if (f[i] < 0) return false;;
		}
		return f[n - 1] >= 0;
	}
};
#endif

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Jump_Game", "[Greedy Technique]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.canJump(NULL,0) == true);
	}
	SECTION("Normal Input") {
		int A[5] = {2,3,1,1,4};
		int B[5] = {3,2,1,0,4};
		int C[5] = {2,0,1,1,4};
		int D[5] = {3,3,1,0,4};
		REQUIRE(sln.canJump(A,5) == true);
		REQUIRE(sln.canJump(B,5) == false);
		REQUIRE(sln.canJump(C,5) == true);
		REQUIRE(sln.canJump(D,5) == true);
	}
}