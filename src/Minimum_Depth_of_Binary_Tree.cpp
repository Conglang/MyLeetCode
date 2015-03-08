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
// 递归版，时间复杂度O(n)，空间复杂度O(logn).
class Solution {
public:
	int minDepth(const TreeNode *root) {
		return minDepth(root, false);
	}
private:
	static int minDepth(const TreeNode *root, bool hasbrother) {
		// 如果本NULL的父节点还有另一颗子树，它不是叶节点，此处无最小一说，返回INT_MAX；如果父节点没有孩子，那么是叶节点，返回0。
		if (!root) return hasbrother ? INT_MAX : 0;
		return 1 + min(minDepth(root->left, root->right != NULL), minDepth(root->right, root->left != NULL));
	}
};
#endif

#ifdef W2
// 迭代法。时间复杂度O(n)，空间复杂度O(logn)。
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
            if(node->left && result > layer)	// 深度控制，剪枝
            {
                s.push(make_pair(layer+1, node->left));
            }
            if(node->right && result > layer)	// 深度控制，剪枝
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