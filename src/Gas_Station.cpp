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
// ����O(n^2)�İ취�ᳬʱ��������O(n)�ķ�����
// ��������޽⣬��ôgas�����ض�С��cost������
// ��ô���gas��������cost������һ���н⣬gas����ĵ����һ���������㡣
// sum�����жϵ�ǰ��gas�Ƿ��㹻��total�����ж�ȫ���Ƿ��н⡣
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)��
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
