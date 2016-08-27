//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/08/27
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given an array of citations (each citation is a non-negative integer) of a researcher,
* write a function to compute the researcher's h-index.
* 
* According to the definition of h-index on Wikipedia: "A scientist has index h if h of
* his/her N papers have at least h citations each, and the other N − h papers have no more than
* h citations each."
* 
* For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers
* in total and each of them had received 3, 0, 6, 1, 5 citations respectively.
* Since the researcher has 3 papers with at least 3 citations each and the remaining
* two with no more than 3 citations each, his h-index is 3.
* 
* Note: If there are several possible values for h, the maximum one is taken as the h-index.
* 
* Hint:
* 
* An easy approach is to sort the array first.
* What are the possible values of h-index?
* A faster approach is to use extra space.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

#define W2
#ifdef W1
// 时间复杂度O(nlogn)，空间复杂度O(1)
// 先排序，然后从大到小看找到第一个引用数小于索引数的
class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i = 0; i < citations.size(); i++)
		{
            if (citations[i] < i+1) return i;
        }
        return citations.size();
    }
};
#endif

#ifdef W2
// 时间复杂度O(n)，空间复杂度O(n)
// 先扫一遍，记录满足每个引用数的有几个，每个数值都是当前数值和比自己大的那个数值之和，找到最大的那个即可。
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int len(citations.size());
        vector<int> hash(len+1,0);
        for(int i = 0; i < len; ++i)
        {
            if(citations[i] >= len) ++hash[len];
            else ++hash[citations[i]];
        }
        for(int i = len-1; i >= 0; --i)
        {
            hash[i] += hash[i+1];
        }
        for(int i=len; i >= 0; --i)
        {
            if(hash[i] >= i) return i;
        }
        return 0;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("H-Index", "[Sorting]"){
	Solution s;
	SECTION("Invalid Input"){
		vector<int> citations;
		REQUIRE(s.hIndex(citations) == 0);
	}
	SECTION("Normal Input"){
		int a[1] = {2};
		int b[2] = {1,1};
		int c[2] = {2,2};
		int d[5] = {3,0,6,1,5};
		vector<int> ra(a,a+1);
		vector<int> rb(b,b+2);
		vector<int> rc(c,c+2);
		vector<int> rd(d,d+5);
		REQUIRE(s.hIndex(ra) == 1);
		REQUIRE(s.hIndex(rb) == 1);
		REQUIRE(s.hIndex(rc) == 2);
		REQUIRE(s.hIndex(rd) == 3);
	}
}
