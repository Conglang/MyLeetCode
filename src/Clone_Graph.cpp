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
// 广度优先遍历。时间复杂度O(n)，空间复杂度O(n)。
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
        unordered_map<int, UndirectedGraphNode*> node_map;	// 记录label和新节点指针的map。
        queue<UndirectedGraphNode*> original_nodes;	// 用来广度遍历原图的队列。
		// 放入起始点到map和queue。确保每次在queue中访问到的点均是在map中已经新建过的。
        node_map.insert(make_pair(node->label, new UndirectedGraphNode(node->label)));
        original_nodes.push(node);	
        // 广度遍历队列。
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
                {	// 马上新建新节点，确保本次遍历遇到的neighbour都创建过，可以一次遍历复制成功。
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