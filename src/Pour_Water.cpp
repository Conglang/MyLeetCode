//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* We are given an elevation map, heights[i] representing the height of the terrain at that index. 
* The width at each index is 1. After Vunits of water fall at index K, how much water is at each index?
* 
* Water first drops at index K and rests on top of the highest terrain or water at that index. 
* Then, it flows according to the following rules:
* 
* If the droplet would eventually fall by moving left, then move left. Otherwise, 
* if the droplet would eventually fall by moving right, then move right. Otherwise, 
* rise at it's current position.Here, "eventually fall" means that the droplet will eventually be 
* at a lower level if it moves in that direction. Also, "level" means the height of the terrain plus 
* any water in that column.
* We can assume there's infinitely high terrain on the two sides out of bounds of the array. 
* Also, there could not be partial water being spread out evenly on more than 1 grid block - each unit of
* water has to be in exactly one block.
* 
* Example 1:
* 
* Input: heights = [2,1,1,2,1,2,2], V = 4, K = 3
* Output: [2,2,2,3,2,2,2]
* Explanation:
* #       #
* #       #
* ##  # ###
* #########
*  0123456    <- index
* 
* The first drop of water lands at index K = 3:
* 
* #       #
* #   w   #
* ##  # ###
* #########
*  0123456    
* 
* When moving left or right, the water can only move to the same level or a lower level.
* (By level, we mean the total height of the terrain plus any water in that column.)
* Since moving left will eventually make it fall, it moves left.
* (A droplet "made to fall" means go to a lower height than it was at previously.)
* 
* #       #
* #       #
* ## w# ###
* #########
*  0123456    
* 
* Since moving left will not make it fall, it stays in place.  The next droplet falls:
* 
* #       #
* #   w   #
* ## w# ###
* #########
*  0123456  
* 
* Since the new droplet moving left will eventually make it fall, it moves left.
* Notice that the droplet still preferred to move left,
* even though it could move right (and moving right makes it fall quicker.)
* 
* #       #
* #  w    #
* ## w# ###
* #########
*  0123456  
* 
* #       #
* #       #
* ##ww# ###
* #########
*  0123456  
* 
* After those steps, the third droplet falls.
* Since moving left would not eventually make it fall, it tries to move right.
* Since moving right would eventually make it fall, it moves right.
* 
* #       #
* #   w   #
* ##ww# ###
* #########
*  0123456  
* 
* #       #
* #       #
* ##ww#w###
* #########
*  0123456  
* 
* Finally, the fourth droplet falls.
* Since moving left would not eventually make it fall, it tries to move right.
* Since moving right would not eventually make it fall, it stays in place:
* 
* #       #
* #   w   #
* ##ww#w###
* #########
*  0123456  
* 
* The final answer is [2,2,2,3,2,2,2]:
* 
*     #    
*  ####### 
*  ####### 
*  0123456 
* Example 2:
* 
* Input: heights = [1,2,3,4], V = 2, K = 2
* Output: [2,3,3,4]
* Explanation:
* The last droplet settles at index 1, since moving further left would not cause it to eventually fall to 
* a lower height.
* Example 3:
* 
* Input: heights = [3,1,3], V = 5, K = 1
* Output: [4,4,4]
* Note:
* 
* heights will have length in [1, 100] and contain integers in [0, 99].
* V will be in range [0, 2000].
* K will be in range [0, heights.length - 1].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

/*
Ref: http://www.cnblogs.com/grandyang/p/8460541.html
这道题说有不同高度的地面，每次都位置K有水滴落下，水滴落下后移动的方向有如下的规则：
1. 如果水滴向左移动后最终停止的位置低于落下的位置，则向左移动。
2. 否则若水滴向右移动后最终停止的位置低于落下的位置，则向右移动。
3. 否则停在原来的位置。

Greedy. 对于每滴水，如果左面有低的就一直向左滚，右面也是。如果左面的更低就优先左面。
*/
// todo
class Solution {
public:
    vector<int> pourWater(vector<int>& heights, int V, int K) {
        for (int i = 0; i < V; ++i) {
            int l(K), r(K), n(heights.size());
            while (l > 0 && heights[l] > heights[l - 1])
                --l;
            while (r < (n - 1) && heights[r] > heights[r + 1])
                ++r;
            heights[l] <= heights[r] ? ++heights[l] : ++heights[r];
        }
        return heights;
    }
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Pour_Water", "[Greedy]"){
	Solution s;
	SECTION("Normal Input"){
    /*
    Input: heights = [2,1,1,2,1,2,2], V = 4, K = 3
    Output: [2,2,2,3,2,2,2]
    Input: heights = [1,2,3,4], V = 2, K = 2
    Output: [2,3,3,4]
    Input: heights = [3,1,3], V = 5, K = 1
    Output: [4,4,4]
    */
    vector<int> heights1 = {2,1,1,2,1,2,2};
    vector<int> result1 = s.pourWater(heights1, 4, 3);
    vector<int> should1 = {2,2,2,3,2,2,2};
    vector<int> heights2 = {1,2,3,4};
    vector<int> result2 = s.pourWater(heights2, 2, 2);
    vector<int> should2 = {2,3,3,4};
    vector<int> heights3 = {3,1,3};
    vector<int> result3 = s.pourWater(heights3, 5, 1);
    vector<int> should3 = {4,4,4};
	REQUIRE(result1 == should1);
    REQUIRE(result2 == should2);
    REQUIRE(result3 == should3);
	}
}