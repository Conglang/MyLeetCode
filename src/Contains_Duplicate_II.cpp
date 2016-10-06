//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/02
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of integers and an integer k, find out whether there are
* two distinct indices i and j in the array such that nums[i] = nums[j] and
* the difference between i and j is at most k.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Time complexity O(n), Space complexity O(n).
// hash table
#define W1

#ifdef W1
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (counts.find(nums[i]) != counts.end())
            {
                if (i - counts[nums[i]] <= k)
                    return true;
            }
            counts[nums[i]] = i;
        }
        return false;
    }
};
#endif

#ifdef W2
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> counts;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > k)
                counts.erase(nums[i-k-1]);
            if (counts.count(nums[i]))
                return true;
            counts.insert(nums[i]);
        }
        return false;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Contains_Duplicate_II", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int a1[5] = {5,4,3,1,2};
		int a2[5] = {5,1,2,4,5};
		REQUIRE(s.containsNearbyDuplicate(vector<int>(),10) == false);
		REQUIRE(s.containsNearbyDuplicate(vector<int>(a1,a1+5),10) == false);
		REQUIRE(s.containsNearbyDuplicate(vector<int>(a2,a2+5),10) == true);
		REQUIRE(s.containsNearbyDuplicate(vector<int>(a2,a2+5),1) == false);
	}
}
