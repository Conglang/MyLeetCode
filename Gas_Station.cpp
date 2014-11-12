//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/12
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
There are N gas stations along a circular route, where the amount of gas at station i is gas[i].

You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1). You begin the journey with an empty tank at one of the gas stations.

Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.

Note:
The solution is guaranteed to be unique.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// ����O(n^2)�İ취�ᳬʱ��������O(n)�ķ�����
// ��������޽⣬��ôgas�����ض�С��cost������
// ��ô���gas��������cost������һ���н⣬gas�������һ���������㡣
// sum�����жϵ�ǰ��gas�Ƿ��㹻��total�����ж�ȫ���Ƿ��н⡣
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