//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given two arrays, write a function to compute their intersection.

Example:
Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].

Note:
Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.
Follow up:
What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ������Ȼ��Two Pointers���Ƚϡ�ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(n)��
// ��һ�ֽⷨ����һ��unordered_map��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)��
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.empty() || nums2.empty()) {return result;}
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int>::iterator it1 = nums1.begin();
        vector<int>::iterator it2 = nums2.begin();
        
        while (it1 != nums1.end() && it2 != nums2.end())
        {
            if (*it1 == *it2) {result.push_back(*it1); ++it1; ++it2;}
            else if (*it1 < *it2) {++it1;}
            else {++it2;}
        }
        return result;
    }
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Intersection_of_Two_Arrays_II", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		vector<int> emp;
		REQUIRE(s.intersect(emp, emp) == emp);
	}
	SECTION("Normal Input"){
		int t1[4] = {1,2,2,1};
		int t2[2] = {2,2};
		vector<int> n1(t1,t1+4);
		vector<int> n2(t2,t2+2);
		REQUIRE(s.intersect(n1,n2) == n2);
	}
}
