//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/3
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

For example:
Given the below binary tree and sum = 22,
                   5
                  / \
               4     8
              /      / \
           11   13   4
           /  \         / \
         7    2      5   1
return
[
   [5,4,11,2],
   [5,8,4,5]
]
//--------------------------------------------------------------------------------------------------------------*/
// My Way
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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > result;
        if (!root) {return result;}
        vector<int> layer;
        tranverse(root, result, layer, sum);
        return result;
    }
private:
    void tranverse(TreeNode* node, vector<vector<int> >& result, vector<int>& layer, int sum)
    {
        if (!node) return;
        layer.push_back(node->val);
        if(!node->left && !node->right)
        {
            if (accumulate(layer.begin(), layer.end(), 0) == sum)
            {
                result.push_back(layer);
            }
        }
        if (node->left) {tranverse(node->left, result, layer, sum);}
        if (node->right) {tranverse(node->right, result, layer, sum);}
        layer.pop_back();
    }
};