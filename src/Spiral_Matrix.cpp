//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
* 
* For example,
* Given the following matrix:
* 
* [
*  [ 1, 2, 3 ],
*  [ 4, 5, 6 ],
*  [ 7, 8, 9 ]
* ]
* You should return [1,2,3,6,9,8,7,4,5].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W1
#ifdef W1
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if (matrix.empty() || matrix[0].empty()) return result;
        int m(matrix.size()), n(matrix[0].size());
        for (int layer = 0; layer < min(m,n)/2; ++layer)
        {
            for (int t = layer; t < n-layer-1; ++t)
            {
                result.push_back(matrix[layer][t]);
            }
            for (int t = layer; t < m-layer-1; ++t)
            {
                result.push_back(matrix[t][n-layer-1]);
            }
            for (int t = n-layer-1; t > layer; --t)
            {
                result.push_back(matrix[m-layer-1][t]);
            }
            for (int t = m-layer-1; t > layer; --t)
            {
                result.push_back(matrix[t][layer]);
            }
        }
        if (min(m,n)%2)
        {
            int layer = min(m,n)/2;
            if (m < n)
            {
                for (int t = layer; t < n-layer; ++t)
                {
                    result.push_back(matrix[layer][t]);
                }
            }else
            {
                for (int t = layer; t < m-layer; ++t)
                {
                    result.push_back(matrix[t][n-layer-1]);
                }
            }
        }
        return result;
    }
};
#endif

#ifdef W2
// Ref: https://discuss.leetcode.com/topic/15558/a-concise-c-implementation-based-on-directions
/*
When traversing the matrix in the spiral order, at any time we follow one out of the following four directions: RIGHT DOWN LEFT UP.
Suppose we are working on a 5 x 3 matrix as such:

0	1	2	3	4	5
	6	7	8	9	10
	11	12	13	14	15

Imagine a cursor starts off at (0, -1), i.e. the position at '0', then we can achieve the spiral order by doing the following:

Go right 5 times
Go down 2 times
Go left 4 times
Go up 1 times.
Go right 3 times
Go down 0 times -> quit
Notice that the directions we choose always follow the order 'right->down->left->up', and for horizontal movements,
the number of shifts follows:{5, 4, 3}, and vertical movements follows {2, 1, 0}.

Thus, we can make use of a direction matrix that records the offset for all directions,
then an array of two elements that stores the number of shifts for horizontal and vertical movements, respectively.
This way, we really just need one for loop instead of four.

Another good thing about this implementation is that: If later we decided to do spiral traversal on a different direction 
(e.g. Counterclockwise), then we only need to change the Direction matrix; the main loop does not need to be touched.
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        vector<int> res;
        int nr = matrix.size();     if (nr == 0) return res;
        int nc = matrix[0].size();  if (nc == 0) return res;
        
        vector<int> nSteps{nc, nr-1};
        
        int iDir = 0;   // index of direction.
        int ir = 0, ic = -1;    // initial position
        while (nSteps[iDir%2]) {
            for (int i = 0; i < nSteps[iDir%2]; ++i) {
                ir += dirs[iDir][0]; ic += dirs[iDir][1];
                res.push_back(matrix[ir][ic]);
            }
            nSteps[iDir%2]--;
            iDir = (iDir + 1) % 4;
        }
        return res;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Spiral_Matrix", "[Arrays]"){
	Solution s;
	SECTION("Empty Vector"){
		vector<vector<int>> num;
		REQUIRE(s.spiralOrder(num).empty() == true);
	}
	SECTION("Normal Vector1"){
		int l1[3] = {1,2,3};
		int l2[3] = {4,5,6};
		int l3[3] = {7,8,9};
		vector<vector<int>> num;
		num.push_back(vector<int>(l1,l1+3));
		num.push_back(vector<int>(l2,l2+3));
		num.push_back(vector<int>(l3,l3+3));
		int r[9] = {1,2,3,6,9,8,7,4,5};
		REQUIRE(s.spiralOrder(num) == vector<int>(r,r+9));
	}
	SECTION("Normal Vector2"){
		int l[2] = {2,3};
		vector<vector<int>> num;
		num.push_back(vector<int>(l,l+2));
		REQUIRE(s.spiralOrder(num) == vector<int>(l,l+2));
	}
}