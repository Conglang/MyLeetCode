//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2016/09/22
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Serialization is the process of converting a data structure or object into a sequence of bits
* so that it can be stored in a file or memory buffer, or transmitted across a network connection link
* to be reconstructed later in the same or another computer environment.
* 
* Design an algorithm to serialize and deserialize a binary tree.
* There is no restriction on how your serialization/deserialization algorithm should work.
* You just need to ensure that a binary tree can be serialized to a string and this string can be 
* deserialized to the original tree structure.
* 
* For example, you may serialize the following tree
* 
*     1
*    / \
*   2   3
*      / \
*     4   5
* as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree.
* You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
* Note: Do not use class member/global/static variables to store states.
* Your serialize and deserialize algorithms should be stateless.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define W1

#ifdef W1
// 广度优先遍历
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while (!nodes.empty())
        {
            TreeNode* cur = nodes.front();
            nodes.pop();
            result.append(cur ? to_string((long long)cur->val) : "#");
            result.append(",");
            if (cur)
            {
                nodes.push(cur->left);
                nodes.push(cur->right);
            }
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        TreeNode* root(nullptr);
        vector<TreeNode*> nodes;
        while (data.find(",") != string::npos)
        {
            auto pos = data.find(",");
            string part = data.substr(0,pos);
            data.erase(0, pos+1);
            if (part != "#")
            {
                TreeNode* node = new TreeNode(stoi(part));
                nodes.push_back(node);
                if (!root) root = node;
            }else
            {
                nodes.push_back(nullptr);
            }
        }
        for (vector<TreeNode*>::iterator head = nodes.begin(), cur = nodes.begin(); cur != nodes.end(), head != nodes.end(); ++head)
        {
            if (*head)
            {
                (*head)->left = *(++cur);
                (*head)->right = *(++cur);
            }
        }
        return root;
    }
};
#endif
// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Serialize_and_Deserialize_Binary_Tree", "[Tree_Traverse]"){
	SECTION("Normal Input") {
		TreeNode a1(1),a2(2),a3(3),a4(5);
		a1.right = &a3;
		a1.left = &a2;
		a2.right = &a4;
		Codec codec;
		codec.deserialize(codec.serialize(&a1));
		REQUIRE(a1.right == &a3);
		REQUIRE(a1.left == &a2);
		REQUIRE(a2.right == &a4);
	}

}