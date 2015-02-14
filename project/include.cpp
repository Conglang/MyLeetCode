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
		result += to_string((_LONGLONG)node->label);
		for (auto it = node->neighbors.begin(); it != node->neighbors.end(); ++it)
		{
			UndirectedGraphNode* neighbor = *it;
			if (!visited.count(neighbor))
			{
				nodes.push(neighbor);
				visited.insert(neighbor);
			}
			result += "," + to_string((_LONGLONG)neighbor->label);
		}
		result += "#";
	}
	return result;
}
