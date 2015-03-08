#include "include.h"
vector<int> get_nodes_val( ListNode* head )
{
	vector<int> val;
	while (head)
	{
		val.push_back(head->val);
		head = head->next;
	}
	return val;
}

vector<int> array_to_vector( int* A, int n )
{
	return vector<int>(A,A+n);;
}

std::string serialize_graph( UndirectedGraphNode* node )
{
	if (!node) return "";
	string result;
	queue<UndirectedGraphNode*> nodes;
	unordered_set<UndirectedGraphNode*> visited;
	nodes.push(node);
	visited.insert(node);
	while (!nodes.empty())
	{
		UndirectedGraphNode* node = nodes.front();
		nodes.pop();
		string tmp(to_string((long double)node->label));
		if (tmp.find(".") != string::npos)
		{
			result += tmp.substr(0,tmp.find("."));
		}else
		{
			result += tmp;
		}
		
		for (auto it = node->neighbors.begin(); it != node->neighbors.end(); ++it)
		{
			UndirectedGraphNode* neighbor = *it;
			if (!visited.count(neighbor))
			{
				nodes.push(neighbor);
				visited.insert(neighbor);
			}
			string temp(to_string((long double)neighbor->label));
			if (temp.find(".") != string::npos)
			{
				result += "," + temp.substr(0,temp.find("."));
			}else
			{
				result += "," + temp;
			}
			
		}
		result += "#";
	}
	return result;
}

std::string serialize_tree( TreeNode* root )
{
	string result;
	if(!root) return result;
	queue<TreeNode*> tree_stack;
	tree_stack.push(root);
	TreeNode* node(NULL);
	while (!tree_stack.empty())
	{
		node = tree_stack.front();
		tree_stack.pop();
		string temp(node ? to_string((long double)node->val) : "");
		if (temp.find(".") != string::npos)
		{
			result += node ? temp.substr(0,temp.find(".")) : "#";
		}else
		{
			result += node ? temp : "#";
		}
		
		result += ",";
		if (node)
		{
			tree_stack.push(node->left);
			tree_stack.push(node->right);
		}
	}
	result.resize(result.size()-1);
	return result;
}
