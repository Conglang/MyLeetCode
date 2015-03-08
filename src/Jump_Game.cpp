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
// 贪心法，时间复杂度O(n)，空间复杂度O(1)。
// 正向，一层一层往上跳，计算最远可跳范围，看最后能不能超过最高层。
class Solution {
public:
	bool canJump(int A[], int n) {
		if(!A || !n) {return true;}
		int reach(1);	// 从1开始计数，最右能跳到哪里。
		// 遍历可以跳到的范围，逐步扩大可跳的距离。
		for (int i = 0; i < reach && reach < n; ++i)
		{
			reach = max(reach, i + 1 + A[i]);
		}
		// 看最右可跳的距离是否大于n。
		return reach >= n;
	}
};
#endif

#ifdef W2
// 贪心法，时间复杂度O(n)，空间复杂度O(1)。
// 逆向，从最高层下楼梯，一层一层往下降，计算最低可到达的位置，看能否回到第0层。
class Solution {
public:
	bool canJump (int A[], int n) {
		if (!A || !n) return true;
		// 逆向下楼梯，最左能下降到第几层
		int left_most = n - 1;
		for (int i = n - 2; i >= 0; --i)
			if (i + A[i] >= left_most)
				left_most = i;
		return left_most == 0;
	}
};
#endif

#ifdef W3
// 动态规划，时间复杂度O(n)，空间复杂度O(n)。
// 设状态为f[i]，表示从0出发，走到A[i]时剩余的最大步数，则状态转移方程为f[i]=max(f[i-1),A[i-1])-1;
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