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
// 从左向右，每次从可跳范围的左端到右端遍历，找到能跳到最远的距离，然后把左端移到上一次的右端后一位。
// |----|=======|*******|
// 每一层次的人在一起找到最远能跳到的下一层次，下一层次再找下一层次能跳到的最远，直到跳过。
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
	int jump(int A[], int n) {
		if (!A || !n) return 0;
		if (n == 1) return 0;
		int left(0),right(0);	// [left, right]是当前能覆盖的区间
		int step(0);	// 最小步数
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
// 从左到右，每次超过上一层计算的最远距离，就把步数加1。
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
	int jump(int A[], int n) {
		int result(0);
		int last(0);	// 能达到的最远距离。
		int cur(0);	// result+1步能到达的最远距离。
		for (int i = 0; i < n; ++i)
		{
			if (i > last)
			{
				if (cur <= last) return 0;	// 如果不能走更远，说明无法到达，返回0。
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