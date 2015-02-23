//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/28
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, flatten it to a linked list in-place.
* 
* For example,
* Given
* 
*          1
*         / \
*        2   5
*       / \   \
*      3   4   6
* The flattened tree should look like:
*    1
*     \
*      2
*       \
*        3
*         \
*          4
*           \
*            5
*             \
*              6
* click to show hints.
* 
* Hints:
* If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
#define W1

#ifdef W1
// 迭代法。时间复杂度O(n)，空间复杂度O(logn)。
// 用栈进行先序遍历。
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
    void flatten(TreeNode *root) {
        if (!root) return;
        stack<TreeNode*> wait;
        wait.push(root);
        //TreeNode* prev = nullptr;
        while(!wait.empty())
        {
            auto node = wait.top();
            wait.pop();
            if (node->right) {wait.push(node->right);}
            if (node->left) {wait.push(node->left);}
            
            node->left = nullptr/*prev*/;
            if (!wait.empty())
            {
                node->right = wait.top();
				//prev = node;
            }
        }
    }
};
#endif

#ifdef W2
// 递归法
class Solution {
public:
	void flatten(TreeNode *root) {
		if (root == nullptr) return; // 终止条件
		flatten(root->left);
		flatten(root->right);
		if (nullptr == root->left) return;
		// 三方合并，将左子树所形成的链表插入到 root 和 root->right 之间
		TreeNode *p = root->left;
		while(p->right) p = p->right; //寻找左链表最后一个节点
		p->right = root->right;
		root->right = root->left;
		root->left = nullptr;
	}
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Flatten_Binary_Tree_to_Linked_List", "[Tree_Traverse]"){
	Solution sln;
	SECTION("Empty Input") {
		sln.flatten(NULL);
	}
	SECTION("Normal Input") {
		TreeNode t1(1),t2(2),t3(3),t4(4),t5(5);
		t1.left = &t2;
		t1.right = &t3;
		t2.left = &t4;
		t3.right = &t5;
		sln.flatten(&t1);
		REQUIRE(serialize_tree(&t1) == "1,#,2,#,4,#,3,#,5,#,#");
	}
}
