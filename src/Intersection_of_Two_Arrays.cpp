//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/18
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two arrays, write a function to compute their intersection.
* 
* Example:
* Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
* 
* Note:
* Each element in the result must be unique.
* The result can be in any order.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(n)
// 用一个unordered_set记录第一个vector中已经存在的数。
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        if (nums1.empty() || nums2.empty()) {return result;}
        unordered_set<int> temp;
        for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); ++it)
        {
            temp.insert(*it);
        }
        for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); ++it)
        {
            if (temp.count(*it))
            {
                result.push_back(*it);
                temp.erase(*it);
            }
        }
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Intersection_of_Two_Arrays", "[Arrays]"){
	Solution s;
	SECTION("Empty Input"){
		vector<int> emp;
		REQUIRE(s.intersection(emp, emp) == emp);
	}
	SECTION("Normal Input"){
		int t1[4] = {1,2,2,1};
		int t2[2] = {1,1};
		int r1[1] = {1};
		vector<int> n1(t1,t1+4);
		vector<int> n2(t2,t2+2);
		vector<int> result(r1,r1+1);
		REQUIRE(s.intersection(n1,n2) == result);
	}
}
