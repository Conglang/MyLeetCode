#pragma once
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
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
