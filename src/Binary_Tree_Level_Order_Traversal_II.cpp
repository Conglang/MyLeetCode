//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/29
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
   3
  / \
9  20
    /  \
 15   7
return its bottom-up level order traversal as:
[
	[15,7],
	[9,20],
	[3]
]
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//--------------------------------------------------------------------------------------------------------------*/
// Important
// µÝ¹é°æ
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
    void tranverse(TreeNode* node, int layer, vector<vector<int> >& result)
    {
        if (!node) {return;}
        if (layer > result.size())
        {
            result.push_back(vector<int>());
        }
        result[layer-1].push_back(node->val);
        tranverse(node->left, layer+1, result);
        tranverse(node->right, layer+1, result);
    }
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > result;
        tranverse(root, 1, result);
        reverse(result.begin(), result.end());
        return result;
    }
};