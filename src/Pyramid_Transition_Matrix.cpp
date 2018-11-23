//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2018/09/23
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.
* 
* For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`. We are allowed to place the block there only if `(A, B, C)` is an allowed triple.
* 
* We start with a bottom row of bottom, represented as a single string. We also start with a list of allowed triples allowed. Each allowed triple is represented as a string of length 3.
* 
* Return true if we can build the pyramid all the way to the top, otherwise false.
* 
* Example 1:
* Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
* Output: true
* Explanation:
* We can stack the pyramid like this:
*     A
*    / \
*   D   E
*  / \ / \
* X   Y   Z
* 
* This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
* Example 2:
* Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
* Output: false
* Explanation:
* We can't stack the pyramid to the top.
* Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
* Note:
* bottom will be a string with length in range [2, 8].
* allowed will have length in range [0, 200].
* Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"

// todo: better structure
// 先把当前 string 两两字符分组，针对每一个 2gram 得到所有可能的 next，和前面 2gram 得到的可能集合组合起来，得到所有可能的组合
// 然后组合中每一种可能重复此过程，得到下一层所有可能的组合，类似这样树的节点一层层展开
// 直到组合中的可能长度为1，就是到了ROOT节点，是终止条件

class Solution {
public:
    unordered_set<string> allowed_set;
    
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for_each(allowed.begin(), allowed.end(), [&](string str){allowed_set.insert(str);});
        return bfs(bottom);
    }
    
    bool bfs(string cur) {
        if (cur.size() <= 1)
            return true;
        vector<string> grams = split2grams(cur);
        vector<string> nexts(1,"");
        for (auto gram : grams) {
            vector<string> possibles = get_possible_nexts(gram);
            vector<string> temps;
            for (auto part : possibles) {
                for (auto old : nexts) {
                    temps.push_back(old + part);
                }   
            }
            nexts = temps;
        }
        for (auto next : nexts) {
            if (bfs(next))
                return true;
        }
        return false;
    }
    
    vector<string> get_possible_nexts(string str) {
        vector<string> result;
        for (char c = 'A'; c <= 'G'; ++c) {
            string compare(str);
            if (allowed_set.count(str+c)) {
                result.push_back(string(1,c));
            }
        }
        return result;
    }
    
    vector<string> split2grams(string str) {
        vector<string> result;
        for(int i = 1; i < str.size(); ++i) {
            result.push_back(str.substr(i-1, 2));
        }
        return result;
    }
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Pyramid_Transition_Matrix", "[BFS]"){
	Solution s;
	SECTION("Normal Input"){
        vector<string> allowed = {"ABD","BCE","DEF","FFF"};
		REQUIRE(s.pyramidTransition("ABC", allowed) == true);
	}
}