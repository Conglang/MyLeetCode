//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a 2D board and a list of words from the dictionary, find all words in the board.
* 
* Each word must be constructed from letters of sequentially adjacent cell, 
* where "adjacent" cells are those horizontally or vertically neighboring. 
* The same letter cell may not be used more than once in a word.
* 
* Example:
* 
* Input: 
* words = ["oath","pea","eat","rain"] and board =
* [
*   ['o','a','a','n'],
*   ['e','t','a','e'],
*   ['i','h','k','r'],
*   ['i','f','l','v']
* ]
* 
* Output: ["eat","oath"]
* Note:
* You may assume that all inputs are consist of lowercase letters a-z.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

// 先构造一个数据结构，便于判断给定前面的字符，后面可选的字符有哪些。比如o:a, oa:t, oat:h。
// 然后再 dfs

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        // words to trie and dict
        unordered_set<string> dict;
        map<string, unordered_set<char>> trie;
        for (auto word : words) {
            dict.insert(word);
            for (int i = 0; i < word.size(); ++i) {
                if (i != word.size() - 1) {
                    trie[word.substr(0,i+1)].insert(word[i+1]);
                }
            }
        }
        
        // dfs
        vector<string> result;
        
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                unordered_set<string> visited;
                visited.insert(to_string(i)+","+to_string(j));
                string path(1, board[i][j]);
                dfs(board, result, path, visited, trie, dict, make_pair(i,j));
            }
        }
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
    
    void dfs(const vector<vector<char>>& board,
            vector<string>& result,
            string path,
            unordered_set<string>& visited,
            const map<string, unordered_set<char>>& trie,
            const unordered_set<string>& dict,
            pair<int, int> pos) {
        const vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};
        // path in the dict, add to result
        if (dict.count(path)) {
            result.push_back(path);
        }
        // for every possible next letter
        for (auto dir : dirs) {
            int x = pos.first + dir.first;
            int y = pos.second + dir.second;
            // whether it's in the words and not visited
            if (x >= 0 && y >=0 && x < board.size() && y < board[0].size() &&
                trie.count(path) &&
                trie.at(path).count(board[x][y]) &&
                !visited.count(to_string(x)+","+to_string(y))) {
                    visited.insert(to_string(x)+","+to_string(y));
                    dfs(board, result, path+board[x][y], visited, trie, dict, make_pair(x,y));
                    visited.erase(to_string(x)+","+to_string(y));
            }
        }
    }
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Word_Search_II", "[BFS]"){
	Solution s;
	SECTION("Normal Input"){
        vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};
        vector<string> words = {"oath","pea","eat","rain"};
        vector<string> result = {"eat","oath"};
		REQUIRE(s.findWords(board, words) == result);
	}
}