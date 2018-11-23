//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/01
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of integers, find if the array contains any duplicates. 
* Your function should return true if any value appears at least twice in the array, 
* and it should return false if every element is distinct.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// sorting or hash table
// hash table
// Time complexity: O(n), Space complexity: O(n)
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> counts;
        for (auto it = nums.begin(); it != nums.end(); ++it)
        {
            if (counts.count(*it))
                return true;
            counts.insert(*it);
        }
        return false;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Contains_Duplicate", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int a1[5] = {5,4,3,1,2};
		int a2[5] = {5,1,2,4,5};
        vector<int> v1;
        vector<int> v2(a1,a1+5);
        vector<int> v3(a2,a2+5);
		REQUIRE(s.containsDuplicate(v1) == false);
		REQUIRE(s.containsDuplicate(v2) == false);
		REQUIRE(s.containsDuplicate(v3) == true);
	}
}
