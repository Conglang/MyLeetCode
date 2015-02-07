//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/12
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
* 
* You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.
* 
* Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
* 
* Note:
* The solution is guaranteed to be unique.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 采用O(n^2)的办法会超时，以下是O(n)的方法。
// 如果整个无解，那么gas总量必定小于cost总量。
// 那么如果gas总量大于cost总量，一定有解，gas不足的点的下一个点就是起点。
// sum用来判断当前点gas是否足够，total用来判断全局是否有解。
// 时间复杂度O(n)，空间复杂度O(1)。
class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int total = 0;
		int j = -1;
		for (int i = 0, sum = 0; i < gas.size(); ++i)
		{
			sum += gas[i] - cost[i];
			total += gas[i] - cost[i];
			if (sum < 0)
			{
				j = i;
				sum = 0;
			}
		}
		return total >= 0 ? j + 1 : -1;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Gas_Station", "[Arrays]"){
	Solution s;
	vector<int> gas;
	vector<int> cost;
	SECTION("Can"){
		int temp[3] = {1,2,3};
		gas.assign(temp, temp+3);
		cost.assign(3,2);
		REQUIRE(s.canCompleteCircuit(gas, cost) == 1);
	}
	SECTION("Can't"){
		int temp[3] = {1,1,1};
		gas.assign(temp, temp+3);
		cost.assign(3,2);
		REQUIRE(s.canCompleteCircuit(gas, cost) == -1);
	}
}
