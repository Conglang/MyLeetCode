//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/14
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
* 
* 
* OJ's undirected graph serialization:
* Nodes are labeled uniquely.
* 
* We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
* As an example, consider the serialized graph {0,1,2#1,2#2,2}.
* 
* The graph has a total of three nodes, and therefore contains three parts as separated by #.
* 
* First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
* Second node is labeled as 1. Connect node 1 to node 2.
* Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
* Visually, the graph looks like the following:
* 
*        1
*       / \
*      /   \
*     0 --- 2
*          / \
*          \_/
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// ������ȱ�����ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)��
/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node) {return NULL;}
        unordered_map<int, UndirectedGraphNode*> node_map;	// ��¼label���½ڵ�ָ���map��
        queue<UndirectedGraphNode*> original_nodes;	// ������ȱ���ԭͼ�Ķ��С�
		// ������ʼ�㵽map��queue��ȷ��ÿ����queue�з��ʵ��ĵ������map���Ѿ��½����ġ�
        node_map.insert(make_pair(node->label, new UndirectedGraphNode(node->label)));
        original_nodes.push(node);	
        // ��ȱ������С�
        while (!original_nodes.empty())
        {
            UndirectedGraphNode* node = original_nodes.front();
            original_nodes.pop();
#if __cplusplus < 201103L
			for (auto it = node->neighbors.begin(); it != node->neighbors.end(); ++it)
			{
				UndirectedGraphNode* neighbor = *it;
#else
            for (auto neighbor : node->neighbors)
            {
#endif
                if (!node_map.count(neighbor->label))
                {	// �����½��½ڵ㣬ȷ�����α���������neighbour��������������һ�α������Ƴɹ���
                    node_map.insert(make_pair(neighbor->label, new UndirectedGraphNode(neighbor->label)));
                    original_nodes.push(neighbor);
                }
                UndirectedGraphNode* new_node = node_map[node->label];
                new_node->neighbors.push_back(node_map[neighbor->label]);
            }
        }
        
        return node_map[node->label];
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Clone_Graph", "[Graph]"){
	Solution sln;
	SECTION("Empty Input") {
		REQUIRE(sln.cloneGraph(NULL) == NULL);
	}
	SECTION("Normal Input"){
		UndirectedGraphNode a(0),b(1),c(2);
		a.neighbors.push_back(&b);
		a.neighbors.push_back(&c);
		b.neighbors.push_back(&c);
		c.neighbors.push_back(&c);
		REQUIRE(serialize_graph(sln.cloneGraph(&a)) == "0,1,2#1,2#2,2#");
	}
}