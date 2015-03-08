//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, return the postorder traversal of its nodes' values.
* 
* For example:
* Given binary tree {1,#,2,3},
* 	1
* 	 \
* 	  2
* 	 /
* 	3
* return [3,2,1].
* 
* Note: Recursive solution is trivial, could you do it iteratively?
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 时间复杂度O(n)，空间复杂度O(n)
// 有左节点时持续访问左结点，并将父节点入栈。
// 当没有左节点时，取出栈顶一个元素，如果其右节点已被访问，访问该栈顶元素。
// 如果右节点未被访问，栈顶元素重新入栈。从其右节点开始重复进行上述过程。
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> result;
        
        const TreeNode *p, *q;
        stack<const TreeNode *> s;
        p = root;
        do {
            while (p != NULL)
            {
                s.push(p);
                p = p->left;	// 往左下走
            }
            q = NULL;
            while (!s.empty())
            {
                p = s.top();
                s.pop();
				// 右孩子不存在或已被访问，访问之
                if (p->right == q)
                {
                    result.push_back(p->val);
                    q = p;	// 保存刚访问过的结点
                }else
                {
                    s.push(p);	// 当前结点不能访问，需二次进栈
                    p = p->right;	// 处理右子树
                    break;	// 重新开始循环，以从此节点开始，重新左下等等那一轮
                }
            }
        }while (!s.empty());
        
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Binary_Tree_Postorder_Traversal", "[Tree_Traverse]"){
	Solution sln;
	vector<int> result;
	SECTION("Empty Input") {
		REQUIRE(sln.postorderTraversal(NULL) == result);
	}
	SECTION("Normal Input") {
		TreeNode t1(1);
		TreeNode t2(2);
		TreeNode t3(3);
		t1.right = &t2;
		t2.left = &t3;
		int r[3] = {3,2,1};
		result.assign(r,r+3);
		REQUIRE(sln.postorderTraversal(&t1) == result);
	}
}