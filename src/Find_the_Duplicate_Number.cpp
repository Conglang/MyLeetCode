//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/20
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive),
* prove that at least one duplicate number must exist. Assume that there is only one duplicate number,
* find the duplicate one.
* 
* Note:
* You must not modify the array (assume the array is read only).
* You must use only constant, O(1) extra space.
* Your runtime complexity should be less than O(n2).
* There is only one duplicate number in the array, but it could be repeated more than once.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(1)
// ���ö��ֲ��ҵ�˼�롣��������ѡһ��λ�ã�Ȼ�����һ�鿴�������λ��������С���ж��ٸ������������������
// ������Ŀ���壬�ظ���һ����������䣬��֮�����ұ����䡣����ͣ�������Ǹ������������������������Ǳ��ظ����Ǹ���
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int left(1), right(nums.size());
        while (left < right)
        {
            int mid(left + ((right - left) >> 1));
            int count(0);
            for (int i = 0; i < nums.size(); ++i)
            {
                if (nums[i] <= mid) {++count;}
            }
            if (count <= mid) {left = mid + 1;}
            else {right = mid;}
        }
        return left;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Find_the_Duplicate_Number", "[Devide and Conquer]"){
	Solution s;
	SECTION("Normal Input"){
		int t1[2] = {1,1};
		int t2[6] = {1,3,2,5,4,3};
		vector<int> v1(t1,t1+2);
		vector<int> v2(t2,t2+6);
		REQUIRE(s.findDuplicate(v1) == 1);
		REQUIRE(s.findDuplicate(v2) == 3);
	}
}
