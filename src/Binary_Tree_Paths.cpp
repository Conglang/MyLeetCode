//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/21
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a binary tree, return all root-to-leaf paths.
* 
* For example, given the following binary tree:
* 
*    1
*  /   \
* 2     3
*  \
*   5
* All root-to-leaf paths are:
* 
* ["1->2->5", "1->3"]
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// DFS
// 两种算法是一样的，只是写法不同
#define W1

#ifdef W1
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if (!root) return result;
        dfs(result, string(), root);
        return result;
    }
private:
    void dfs(vector<string>& result, string path, TreeNode* cur)
    {
        if (!cur) return;
        path.append(to_string((long long)(cur->val)) + "->");
        if (!cur->left && !cur->right)
        {
            path.pop_back();
            path.pop_back();
            result.push_back(path);
        }
        dfs(result, path, cur->left);
        dfs(result, path, cur->right);
    }
};
#endif

#ifdef W2
class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;

        if(!root) return res;
        else if(!root->left && !root->right) res.push_back(to_string(root->val));
        
        string head = to_string(root->val) + "->";
        
        for(auto item: binaryTreePaths(root->left)) res.push_back(head + item);
        for(auto item: binaryTreePaths(root->right)) res.push_back(head + item);
        
        return res;
    }
};
#endif
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Binary_Tree_Paths", "[Tree_Recursion]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.binaryTreePaths(NULL) == vector<string>());
	}
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3),a4(5);
		a1.right = &a3;
		a1.left = &a2;
		a2.right = &a4;
		vector<string> result;
		result.push_back("1->2->5");
		result.push_back("1->3");
		REQUIRE(sln.binaryTreePaths(&a1) == result);
	}
}