//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,

You should return the following matrix:
[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (!n) return vector<vector<int>>();
        int num = 1;
        vector<vector<int>> res(n, vector<int>(n,0));
#if (__cplusplus >= 201103L)
        vector<vector<int>> dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> nSteps{n, n-1};
#else
		int dir1[2] = {0,1};
		int dir2[2] = {1,0};
		int dir3[2] = {0,-1};
		int dir4[2] = {-1,0};
		vector<vector<int>> dirs;
		dirs.push_back(vector<int>(dir1,dir1+2));
		dirs.push_back(vector<int>(dir2,dir2+2));
		dirs.push_back(vector<int>(dir3,dir3+2));
		dirs.push_back(vector<int>(dir4,dir4+2));
		int steps[2] = {n, n-1};
		vector<int> nSteps(steps, steps+2);
#endif
        int iDir(0);
        int ir(0), ic(-1);
        while (nSteps[iDir%2])
        {
            for (int i = 0; i < nSteps[iDir%2]; ++i)
            {
                ir += dirs[iDir][0];
                ic += dirs[iDir][1];
                res[ir][ic] = num++;
            }
            nSteps[iDir%2]--;
            iDir = (iDir+1) % 4;
        }
        return res;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Spiral_Matrix_II", "[Arrays]"){
	Solution s;
	SECTION("Empty Vector"){
		vector<vector<int>> num;
		REQUIRE(s.generateMatrix(0) == num);
	}
	SECTION("Normal Vector1"){
		int l1[3] = {1,2,3};
		int l2[3] = {8,9,4};
		int l3[3] = {7,6,5};
		vector<vector<int>> num;
		num.push_back(vector<int>(l1,l1+3));
		num.push_back(vector<int>(l2,l2+3));
		num.push_back(vector<int>(l3,l3+3));
		REQUIRE(s.generateMatrix(3) == num);
	}
}