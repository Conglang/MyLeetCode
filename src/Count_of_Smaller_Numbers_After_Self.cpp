//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* You are given an integer array nums and you have to return a new counts array.
* The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].
* 
* Example:
* 
* Given nums = [5, 2, 6, 1]
* 
* To the right of 5 there are 2 smaller elements (2 and 1).
* To the right of 2 there is only 1 smaller element (1).
* To the right of 6 there is 1 smaller element (1).
* To the right of 1 there is 0 smaller element.
* Return the array [2, 1, 1, 0].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
#define W2
// ������һ��vector�����������������һ��������ݣ�����㵽��߽��ֵ����С�����������������̿����ö��֣��Ϳ�����nlogn�ˡ�
#ifdef W1
// ʱ�临�Ӷ�O(n^2)���ռ临�Ӷ�O(n)
// ����һ��vector�洢�ź���ĵ�ǰ�Ҳ�Ԫ�أ�ÿ�μ���һ�¾���begin�ľ��롣
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result, record;
        if (nums.empty()) return result;
        
        for (int i = nums.size()-1; i >= 0; --i)
        {
            auto pos = lower_bound(record.begin(), record.end(), nums[i]);
            int count(pos - record.begin());
            record.insert(record.begin()+count, nums[i]);
            result.push_back(count);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
#endif

#ifdef W2
// ��¼�Ĺ��̲�����vector�����ǹ���һ��BST�������Ǹо��˴����㷨ʵ�ֵ��е㲻��Ȼ�������ǲ����ҽڵ�ʱ��leftCount�Ĵ����������
// ��������Ҳ������mergesort����֮���ǽ���¼�����������ĳ�ֲ�ѯ�㷨ʵ�֡�
// ʱ�临�Ӷ�O(nlogn)���ռ临�Ӷ�O(n)
// Ref: https://discuss.leetcode.com/topic/43595/c-36ms-bst-solution
struct SpecificTreeNode {
    int val;
    int copy;
    int leftCount;
    SpecificTreeNode *left;
    SpecificTreeNode *right;
    SpecificTreeNode(int x) : val(x), copy(1), leftCount(0), left(NULL), right(NULL) {}
};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> result;
        if (nums.empty()) return result;
        result.assign(nums.size(), 0);
        SpecificTreeNode root(nums[nums.size()-1]);
        for (int i = nums.size()-2; i >= 0; --i)
        {
            result[i] = insert(&root, nums[i]);
        }
        return result;
    }
private:
    int insert(SpecificTreeNode* root, int x)
    {
        if (root->val == x)
        {
            ++root->copy;
            return root->leftCount;
        }else if (root->val > x)
        {
            ++root->leftCount;
            if (!root->left)
            {
                root->left = new SpecificTreeNode(x);
                return 0;
            }else
            {
                return insert(root->left, x);
            }
        }else
        {
            if (!root->right)
            {
                root->right = new SpecificTreeNode(x);
                return root->leftCount + root->copy;
            }else
            {
                return root->leftCount + root->copy + insert(root->right, x);
            }
        }
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Count_of_Smaller_Numbers_After_Self", "[Devide and Conquer]") {
	Solution s;
	SECTION("Normal Input") {
		int nums[6] = {5,2,6,1,3,4};
		int result[6] = {4,1,3,0,0,0};
		REQUIRE(s.countSmaller(vector<int>(nums, nums+6)) == vector<int>(result,result+6));
		int nums1[6] = {1,3,2,4,2,2};
		int result1[6] = {0,3,0,2,0,0};
		REQUIRE(s.countSmaller(vector<int>(nums1, nums1+6)) == vector<int>(result1,result1+6));
	}
}
