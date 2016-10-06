//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/06
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a sorted integer array without duplicates, return the summary of its ranges.
* 
* For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// Time complexity O(n), Space complexity O(1)
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if (nums.empty()) return result;
        auto pre = nums.begin();
        auto left(*nums.begin());
        bool con(false);
        for (auto it = nums.begin()+1; ;++it)
        {
            if (it == nums.end() || *it != (*pre)+1)
            {
                if (con)
                {
                    result.push_back(to_string((long long)left)+"->"+to_string((long long)*pre));
                    if (it != nums.end()) left = *it;
                    con = false;
                }else
                {
                    result.push_back(to_string((long long)left));
                    if (it != nums.end()) left = *it;
                }
            }else
            {
                con = true;
            }
            pre = it;
			if (it == nums.end()) break;
        }
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Summary_Ranges", "[Arrays]"){
	Solution s;
	SECTION("Normal Input"){
		int a[7] = {1,3,4,7,8,9,12};
		string r[4] = {"1","3->4","7->9","12"};
		REQUIRE(s.summaryRanges(vector<int>(a,a+7)) == vector<string>(r,r+4));
	}
}