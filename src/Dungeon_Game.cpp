//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/10
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon.
The dungeon consists of M x N rooms laid out in a 2D grid.
Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon
to rescue the princess.

The knight has an initial health point represented by a positive integer.
If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms;
other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in
each step.


Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the
optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

-2(K)	-3		3
-5		-10		1
10		30		-5(P)

Notes:

The knight's health has no upper bound.
Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room
where the princess is imprisoned.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Ref: https://discuss.leetcode.com/topic/6912/c-dp-solution/2
class Solution {
public:
	int calculateMinimumHP(vector<vector<int> > &dungeon) {
		int M = dungeon.size();
		int N = dungeon[0].size();
		// hp[i][j] represents the min hp needed at position (i, j)
		// Add dummy row and column at bottom and right side
		vector<vector<int> > hp(M + 1, vector<int>(N + 1, INT_MAX));
		hp[M][N - 1] = 1;
		hp[M - 1][N] = 1;
		for (int i = M - 1; i >= 0; i--) {
			for (int j = N - 1; j >= 0; j--) {
				int need = min(hp[i + 1][j], hp[i][j + 1]) - dungeon[i][j];
				hp[i][j] = need <= 0 ? 1 : need;
			}
		}
		return hp[0][0];
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Dungeon_Game", "[Dynamic_Programming]"){
	Solution s;
	SECTION("Normal Input"){
		vector<vector<int> > dungeon1(1, vector<int>(1,1));
		REQUIRE(s.calculateMinimumHP(dungeon1) == 1);
		int a[3] = {-2,-3,3};
		int b[3] = {-5,-10,1};
		int c[3] = {10,30,-5};
		vector<int> l1(a, a+3);
		vector<int> l2(b, b+3);
		vector<int> l3(c, c+3);
		vector<vector<int>> dungeon2;
		dungeon2.push_back(l1);
		dungeon2.push_back(l2);
		dungeon2.push_back(l3);
		REQUIRE(s.calculateMinimumHP(dungeon2) == 7);
	}
}