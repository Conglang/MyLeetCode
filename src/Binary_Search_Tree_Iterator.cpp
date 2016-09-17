//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/16
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
* 
* Calling next() will return the next smallest number in the BST.
* 
* Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
* 
* Credits:
* Special thanks to @ts for adding this problem and creating all test cases.
* 
* Subscribe to see which companies asked this question
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
class BSTIterator {
private:
    stack<TreeNode *> myStack;
public:
    BSTIterator(TreeNode *root) {
        pushAll(root);
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !myStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *tempNode = myStack.top();
        myStack.pop();
        pushAll(tempNode->right);
        return tempNode->val;
    }
private:
    void pushAll(TreeNode *node)
    {
        for(; node != NULL; myStack.push(node), node = node->left);
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Binary_Search_Tree_Iterator", "[Binary Search Tree]"){
	SECTION("Empty Input") {
		BSTIterator i = BSTIterator(NULL);
		vector<int> result;
		while (i.hasNext())
		{
			result.push_back(i.next());
		}
		REQUIRE(result == vector<int>());
	}
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3),a4(4);
		a4.left = &a2;
		a2.left = &a1;
		a2.right = &a3;
		int r[4] = {1,2,3,4};

		vector<int> result;

		BSTIterator i = BSTIterator(&a4);
		result.clear();
		while (i.hasNext()) {result.push_back(i.next());}
		REQUIRE(result == vector<int>(r,r+4));

		BSTIterator j = BSTIterator(&a3);
		result.clear();
		while (j.hasNext()) {result.push_back(j.next());}
		REQUIRE(result == vector<int>(r+2,r+3));

		BSTIterator k = BSTIterator(&a2);
		result.clear();
		while (k.hasNext()) {result.push_back(k.next());}
		REQUIRE(result == vector<int>(r,r+3));
	}
}
