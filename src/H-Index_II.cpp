//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/10/12
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Follow up for H-Index: What if the citations array is sorted in ascending order? 
* Could you optimize your algorithm?
* 
* Hint:
* 
* Expected runtime complexity is in O(log n) and the input is sorted.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
class Solution {
public:
	int hIndex(vector<int>& citations) {
		int left(0), right(citations.size());
		while (left < right)
		{
			int mid = left + (right - left) / 2;
			if (citations.size() - mid > citations[mid])
			{
				left = mid+1;
			}else
			{
				right = mid;
			}
		}
		return citations.size()-left;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("H-Index_II", "[Binary_Search]"){
	Solution s;
	SECTION("Normal Input"){
		int c1[5] = {1,3,5,7,9};
		int c2[6] = {1,3,5,7,9,11};
		vector<int> v1(c1,c1+5);
		REQUIRE(s.hIndex(v1) == 3);
		vector<int> v2(c2,c2+6);
		REQUIRE(s.hIndex(v2) == 4);
	}
}