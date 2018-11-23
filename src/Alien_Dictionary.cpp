//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/02
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
* Example 1:
* Given the following words in dictionary,
* [
*   "wrt",
*   "wrf",
*   "er",
*   "ett",
*   "rftt"
* ]
* The correct order is: "wertf".
* Example 2:
* Given the following words in dictionary,
* [
*   "z",
*   "x"
* ]
* The correct order is: "zx".
* Example 3:
* Given the following words in dictionary,
* [
*   "z",
*   "x",
*   "z"
* ]
* The order is invalid, so return "".
* Note:
* You may assume all letters are in lowercase.
* You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
* If the order is invalid, return an empty string.
* There may be multiple valid order of letters, return any one of them is fine.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
/*
    比较词典首字、后续字、依次类推，类似 BFS。在此过程中构建一个图。
    然后根据生成的图，从没有后续节点的字删除，逆序就是结果。
*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty())
            return "";
        Graph graph;
        try {
            make_graph(words, graph);   // 生成图
            // graph.print_graph();
            return build_order(graph);  // 没有后续节点的逆序
        } catch(char const* e) {
            return e;
        }
        
    }
    
private:
    // 简单的图数据结构，主要就是 map (key, children)
    // 方法：添加节点(包含合法性检查)、删除节点、找到没孩子的节点
    class Graph {
    private:
        unordered_map<char, unordered_set<char>> m_graph;
        
    public:
        void add_node(char parent, char child) {
            if (parent == child)
                return;
            if (!m_graph.count(child)) {
                m_graph[child] = unordered_set<char>();
            }
            if (m_graph[child].count(parent))
                throw "";
            if (parent != ' ') {
                m_graph[parent].insert(child);
            }
        }
        
        void delete_node(char child) {
            for (auto& node : m_graph) {
                if (node.first != child && node.second.count(child)) {
                    node.second.erase(child);
                }
            }
            m_graph.erase(child);
        }
        
        char get_no_children() {
            for (auto node : m_graph) {
                if (node.second.empty())
                    return node.first;
            }
            return ' ';
        }
        
        bool empty() {
            return m_graph.empty();
        }
        
        void print_graph() {
            for (auto node : m_graph) {
                cout << node.first << ": ";
                for (auto child : node.second) {
                    cout << child << ", ";
                }
                cout << endl;
            }
            cout << endl;
        }
    };

    void make_graph(vector<string> words, Graph& graph) {
        using Iterator = vector<string>::iterator;
        
        queue<pair<Iterator, Iterator>> q;  // 用一个队列来记录要检查的词的区间，之前字符全都相等的在同一个区间
        q.push(make_pair(words.begin(), words.end()));  // 初始是整个词列表
        
        int level_count(1); // 在处理第 level 个字符的时候，有 level_count 个区间存在
        int level(0);

        while (!q.empty()) {
            for (int i = 0; i < level_count; ++i) {  // 用记录区间数量的方式来区分每一层，BFS的一种实现
                auto range = q.front();
                q.pop();
                char prev_val = ' ';
                
                auto next_iter_start = range.first; // 用于生成下一层的区间
                auto next_iter_end = range.first;
                
                for (auto it = range.first; it != range.second; ++it, ++next_iter_end) {    // 对于区间内所有第 level 个字符进行比较，生成图，生成区间
                    if ((*it).size() < level + 1) { // 这个词在这没字符了
                        continue;
                    }
                    // 处理图
                    auto cur_val = (*it)[level];
                    graph.add_node(prev_val, cur_val);
                    // 处理区间
                    if (prev_val != ' ' && prev_val != cur_val) {   // 出现字符变化的时候就应该生成区间了
                        q.push(make_pair(next_iter_start, next_iter_end));
                        // cout << "pair: " <<prev_val << "|" << cur_val << " " << distance(words.begin(), next_iter_start) << ", " << distance(words.begin(), next_iter_end) << endl;
                        next_iter_start = next_iter_end;
                    }
                    prev_val = cur_val;
                }
                
                if (prev_val != ' ') {  // 最后一个区间也要放进去
                    q.push(make_pair(next_iter_start, next_iter_end));
                    // cout << "pair: " <<prev_val << "| " << " " << distance(words.begin(), next_iter_start) << ", " << distance(words.begin(), next_iter_end) << endl;
                }
                
            }

            level_count = q.size(); // 记录一下当前层有几个区间
            ++level;    // 比较下一个字符
        }
    }
    
    string build_order(Graph& graph) {
        string result;
        while (!graph.empty()) {
            char now = graph.get_no_children();
            if (now == ' ')
                throw "";
            graph.delete_node(now);
            result += now;
        }
        
        reverse(result.begin(), result.end());  // 逆序
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Alien_Dictionary", "[Graph]"){
	Solution s;
	SECTION("Normal Input 1"){
        vector<string> words = {"wrt", "wrf", "er", "ett", "rftt"};
		REQUIRE(s.alienOrder(words) == "wertf");
	}
    SECTION("Normal Input 2"){
        vector<string> words = {"z", "x"};
		REQUIRE(s.alienOrder(words) == "zx");
	}
    SECTION("Invalid Input"){
        vector<string> words = {"z", "x", "z"};
		REQUIRE(s.alienOrder(words) == "");
	}
}