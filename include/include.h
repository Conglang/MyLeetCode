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
#include <cstring>
#include <cctype>
#include <iostream>
#include <cmath>
#include <string>

using namespace std;
#define INT_MIN     (-2147483647 - 1) /* minimum (signed) int value */
#define INT_MAX       2147483647    /* maximum (signed) int value */
#include "../catch/catch.hpp"
//---------------------------------------------------
// For Linked List
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

string serialize_tree(TreeNode* node);

// Definition for binary tree with next pointer.
struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};

struct Interval {
	int start;
	int end;
	Interval(int _start, int _end) : start(_start), end(_end) {}
	string serialize() {return "[" + to_string(start) + "," + to_string(end) + "]";}
}