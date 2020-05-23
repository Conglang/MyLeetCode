//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/7/31
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Find the contiguous subarray within an array (containing at least one number) which has the largest product.
* 
* For example, given the array [2,3,-2,4],
* the contiguous subarray [2,3] has the largest product = 6.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(1)。
//min can turn max when encountering another negative number
//so we have to record all the min and max values;
class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        int size = nums.size();
        int minProduct = nums[0], maxProduct = nums[0], ret = nums[0];
        for(int i = 1; i < size; ++i)
        {
            if(nums[i] < 0) swap(minProduct, maxProduct);
            maxProduct = max(maxProduct*nums[i], nums[i]);
            minProduct = min(minProduct*nums[i], nums[i]);
            ret = max(ret, maxProduct);
        }
        return ret;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Maximum_Product_Subarray", "[Arrays]"){
	Solution s;
	SECTION("Empty Vector"){
		int A[1] = {-2};
		int B[2] = {-1,-1};
		int C[4] = {2,3,-2,4};
		int D[7] = {-2,3,-2,-4,5,2,-3};
		int E[5] = {-2,-2,-2,-2,-2};
		int F[31] = {2,5,-1,7,-5,-8,6,-4,1,-1,-1,-1,1,1,-1,-1,-1,-1,-1,-1,1,-1,1,-1,1,-1,-1,1,1,-1,-1};
		vector<int> v1(A,A+1);
		REQUIRE(s.maxProduct(v1) == -2);
		vector<int> v2(B,B+2);
		REQUIRE(s.maxProduct(v2) == 1);
		vector<int> v3(C,C+4);
		REQUIRE(s.maxProduct(v3) == 6);
		vector<int> v4(D,D+7);
		REQUIRE(s.maxProduct(v4) == 1440);
		vector<int> v5(E,E+5);
		REQUIRE(s.maxProduct(v5) == 16);
		vector<int> v6(F,F+11);
		REQUIRE(s.maxProduct(v6) == 67200);
	}
}