//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, find its minimum depth.
* 
* The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define W2

#ifdef W1
// �ݹ�棬ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(logn).
class Solution {
public:
	int minDepth(const TreeNode *root) {
		return minDepth(root, false);
	}
private:
	static int minDepth(const TreeNode *root, bool hasbrother) {
		// �����NULL�ĸ��ڵ㻹����һ��������������Ҷ�ڵ㣬�˴�����Сһ˵������INT_MAX��������ڵ�û�к��ӣ���ô��Ҷ�ڵ㣬����0��
		if (!root) return hasbrother ? INT_MAX : 0;
		return 1 + min(minDepth(root->left, root->right != NULL), minDepth(root->right, root->left != NULL));
	}
};
#endif

#ifdef W2
// ��������ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(logn)��
class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root) {return 0;}
		int result(INT_MAX);
        stack<pair<int, TreeNode*> > s;
        s.push(make_pair(1,root));
        while(!s.empty())
        {
            TreeNode* node = s.top().second;
            int layer = s.top().first;
            s.pop();
            if(!node->left && !node->right)
            {
                result = min(result,layer);
            }
            if(node->left && result > layer)	// ��ȿ��ƣ���֦
            {
                s.push(make_pair(layer+1, node->left));
            }
            if(node->right && result > layer)	// ��ȿ��ƣ���֦
            {
                s.push(make_pair(layer+1, node->right));
            }
        }
		return result;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Minimum_Depth_of_Binary_Tree", "[Tree_Recursion]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.minDepth(NULL) == 0);
	}
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3),a4(4);
		a1.left = &a4;
		a1.right = &a3;
		a3.left = &a2;
		REQUIRE(sln.minDepth(&a1) == 2);
	}
}