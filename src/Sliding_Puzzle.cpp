//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/02
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.
* 
* A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
* 
* The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
* 
* Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
* 
* Examples:
* 
* Input: board = [[1,2,3],[4,0,5]]
* Output: 1
* Explanation: Swap the 0 and the 5 in one move.
* Input: board = [[1,2,3],[5,4,0]]
* Output: -1
* Explanation: No number of moves will make the board solved.
* Input: board = [[4,1,2],[5,0,3]]
* Output: 5
* Explanation: 5 is the smallest number of moves that solves the board.
* An example path:
* After move 0: [[4,1,2],[5,0,3]]
* After move 1: [[4,1,2],[0,5,3]]
* After move 2: [[0,1,2],[4,5,3]]
* After move 3: [[1,0,2],[4,5,3]]
* After move 4: [[1,2,0],[4,5,3]]
* After move 5: [[1,2,3],[4,5,0]]
* Input: board = [[3,2,4],[1,5,0]]
* Output: 14
* Note:
* 
* board will be a 2 x 3 array as described above.
* board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

// BFS, 两层交替扫
// todo: change to string at first, using string for processing
// todo: better data structure
class Solution {
public:
    using Board = vector<vector<int>>;
    
    int slidingPuzzle(vector<vector<int>>& board) {
        int count(0);
        deque<Board> cur_level, next_level;
        cur_level.push_back(board);
        visited.insert(serialize_board(board));
        
        while (!cur_level.empty()) {
            while (!cur_level.empty()) {
                Board now = cur_level.front();
                cur_level.pop_front();
                if (is_done(now))
                    return count;
                vector<Board> next_part = get_next_level(now);
                copy(next_part.begin(), next_part.end(), back_inserter(next_level));
            }
            cur_level = next_level;
            next_level.clear();
            ++count;
        }
        return -1;
    }
private:
    unordered_set<string> visited;
    unordered_map<string, pair<int,int>> zero_positions;
    
    static vector<pair<int,int>> dirs() {
        return {{-1,0},{1,0},{0,-1},{0,1}};
    }
    
    static Board success_board() {
        return {{1,2,3}, {4,5,0}};
    }
    
    vector<Board> get_next_level(const Board& now) {
        vector<Board> next_level;
        pair<int, int> zero = get_zero(now);
        for (auto dir : dirs()) {
            Board next(now);
            int x = zero.first + dir.first;
            int y = zero.second + dir.second;
            if (x >= 0 && x < now.size() && y >= 0 && y < now[0].size()) {
                next[zero.first][zero.second] = next[x][y];
                next[x][y] = 0;
                zero_positions.insert(make_pair(serialize_board(next), make_pair(x,y)));
                if (!visited.count(serialize_board(next))) {
                    visited.insert(serialize_board(next));
                    next_level.push_back(next);
                }
            }
        }
        return next_level;
    }
    
    pair<int,int> get_zero(Board now) {
        if (zero_positions.count(serialize_board(now))) {
            return zero_positions[serialize_board(now)];
        }
        for (int i = 0; i < now.size(); ++i) {
            for (int j = 0; j < now[0].size(); ++j) {
                if (now[i][j] == 0) {
                    zero_positions.insert(make_pair(serialize_board(now), make_pair(i,j)));
                    return make_pair(i,j);
                }
            }
        }
        return make_pair(-1, -1);
    }
    
    bool is_done(const Board& board) {
        return success_board() == board;
    }
    
    string serialize_board(Board now) {
        string result;
        for_each(now.begin(), now.end(), [&result](vector<int> line) {
            for_each(line.begin(), line.end(), [&result](int num){result += to_string(num);});
        });
        return result;
    }
};

//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Sliding_Puzzle", "[BFS]"){
	Solution s;
	SECTION("Normal Input"){
        vector<vector<int>> board = {{1,2,3},{4,0,5}};
		REQUIRE(s.slidingPuzzle(board) == 1);
	}
}