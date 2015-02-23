#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <stack>
#include <queue>
using namespace std;

#include "../catch/catch.hpp"
//---------------------------------------------------
// For Linked List
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

vector<int> get_nodes_val(ListNode* head);
vector<int> array_to_vector(int* A, int n);

// For Undirected Graph
struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

string serialize_graph(UndirectedGraphNode* node);

// For BinaryTree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

string serialize_tree(TreeNode* node);

// Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};