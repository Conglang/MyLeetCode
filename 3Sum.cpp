//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/8
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a �� b �� c)
The solution set must not contain duplicate triplets.
For example, given array S = {-1 0 1 2 -1 -4},

A solution set is:
(-1, 0, 1)
(-1, -1, 2)
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// Important
// �ٲ�ȥ����׼�����ǲ����ˡ�
// ������Ȼ������������ıƽ���
// ע���ֹ�ظ������Ż�������������һ�����Լ���ֵһ������û�б�Ҫ�ٶ����ظ��Լ�������һ���ˡ�
// �����������Ż���Time Limit Exceed.
class Solution {
public:
	vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > res;
		if (num.size() <= 2) return res;
		sort(num.begin(), num.end());
		int twoSum;
		for (int i = 0; i < num.size() - 2;)
		{
			int l = i + 1, r = num.size() - 1;
			twoSum = 0 - num[i];
			while (l < r)
			{
				if (num[l] + num[r] < twoSum) {l++;}
				else if (num[l] + num[r] > twoSum) {r--;}
				else
				{
					res.push_back({num[i], num[l], num[r]});
					do { l++; }while (l < r && num[l - 1] == num[l]);	// ע��˴��Ż��������ƣ��жϺ��Լ�֮ǰ����ͬ��
					do { r--; }while (l < r && num[r + 1] == num[r]);	// �Ż���
				}
			}
			do{ i++; }while (i < num.size() - 1 && num[i - 1] == num[i]);	// �Ż���
		}
		sort(res.begin(),res.end());	// �������յĽ������Ҫɾ���ظ�Ԫ�ء�
		return res;
	}
};
