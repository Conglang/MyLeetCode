//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* There are n cities connected by m flights. Each fight starts from city u and arrives at v with a price w.
* 
* Now given all the cities and fights, together with starting city src and the destination dst, your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
* 
* Example 1:
* Input: 
* n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
* src = 0, dst = 2, k = 1
* Output: 200
* Explanation: 
* The graph looks like this:
* 
* 
* The cheapest price from city 0 to city 2 with at most 1 stop costs 200, as marked red in the picture.
* Example 2:
* Input: 
* n = 3, edges = [[0,1,100],[1,2,100],[0,2,500]]
* src = 0, dst = 2, k = 0
* Output: 500
* Explanation: 
* The graph looks like this:
* 
* 
* The cheapest price from city 0 to city 2 with at most 0 stop costs 500, as marked blue in the picture.
* Note:
* 
* The number of nodes n will be in range [1, 100], with nodes labeled from 0 to n - 1.
* The size of flights will be in range [0, n * (n - 1) / 2].
* The format of each flight will be (src, dst, price).
* The price of each flight will be in the range [1, 10000].
* k is in the range of [0, n - 1].
* There will not be any duplicated flights or self cycles.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

// BFS

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        if (src == dst) return 0;
        
        // src: (dst, price)
        unordered_map<int, vector<pair<int, int>>> flightmap;
        for (auto vec : flights) {
            flightmap[vec[0]].push_back(make_pair(vec[1], vec[2]));
        }
        
        // BFS, (src, full_price_along_the_way)
        queue<pair<int, int>> q;
        q.push(make_pair(src, 0));
        
        int result(INT_MAX);
        int steps(0);
        
        while (!q.empty()) {
            int num = q.size();
            // this step
            for (int i = 0; i < num; ++i) {
                auto now = q.front();
                q.pop();
                if (now.first == dst) {
                    result = min(result, now.second);
                }
                
                for (auto next_pair : flightmap[now.first]) {
                    if (now.second + next_pair.second > result) // 剪枝
                        continue;
                    q.push(make_pair(next_pair.first, now.second + next_pair.second));
                }
            }
            // limit step
            if (++steps > K + 1)
                break;
            
        }
        
        return result == INT_MAX ? -1 : result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Cheapest_Flights_Within_K_Stops", "[BFS]"){
	Solution s;
	SECTION("Normal Input"){
        vector<vector<int>> flights = {{0,1,100},{1,2,100},{0,2,500}};
		REQUIRE(s.findCheapestPrice(3, flights, 0, 2, 1) == 200);
	}
}