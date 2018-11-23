//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/17
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a complete binary tree, count the number of nodes.
* 
* Definition of a complete binary tree from Wikipedia: https://en.wikipedia.org/wiki/Binary_tree#Types_of_binary_trees
* In a complete binary tree every level, except possibly the last, is completely filled,
* and all nodes in the last level are as far left as possible.
* It can have between 1 and 2h nodes inclusive at the last level h.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 类似二分查找，每次向下一层，寻找最左那个叶节点，通过找左节点的右子树。
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        int height(0), leafNum(0);
        TreeNode *parent(root), *temp(nullptr);
        // get the height of the tree
        while(parent)
        {
            parent = parent->left;
            ++height;
        }
        parent = root;
        // levels under the child of root
        int level(height - 2);
        // collect the bottom-level nodes by halving them apart
        while (level > -1)
        {
            temp = parent->left;
            for(int i = 0; i < level; ++i)
            {
                temp = temp->right;
            }
            // rightmost node is not null
            if (temp)
            {
                leafNum += 1 << level;
                parent = parent->right;
            }
            else
            {
                parent = parent->left;
            }
            --level;    // move to the next level
        }
        if (parent) ++leafNum;  // if it's a complete tree, collect the last right node
        return leafNum + ((1 << (height - 1)) - 1);
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Count_Complete_Tree_Nodes", "[Tree_Tranverse]"){
	Solution s;
	SECTION("Empty Input") {
		REQUIRE(s.countNodes(NULL) == 0);
	}
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3),a4(4),a5(5);
		a1.left = &a2; a1.right = &a3;
		a2.left = &a4; a2.right = &a5;
		REQUIRE(s.countNodes(&a1) == 5);
	}
}
