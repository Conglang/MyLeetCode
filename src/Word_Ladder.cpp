//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/12/12
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two words (start and end), and a dictionary, find the length of shortest transformation sequence
* from start to end, such that:
* 
* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
* For example,
* 
* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]
* As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
* return its length 5.
* 
* Note:
* 	Return 0 if there is no such transformation sequence.
* 	All words have the same length.
* 	All words contain only lowercase alphabetic characters.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// 广度遍历算法。时间复杂度O(n)，空间复杂度O(n)。
class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<string> current, next;	// 当前层，下一层
		unordered_set<string> visited;	// 判重

		int level(0);	// 层次
		bool found(false);	// 是否走到目标单词

		auto state_is_target = [&](const string &s) {return s == end;};	// 判断是否是目标单词的lambda函数
		auto state_extend = [&](const string &s)->vector<string> {	// 从当前词找到下一个所有可行词的lambda函数
			vector<string> result;

			for (size_t i = 0; i < s.size(); ++i)	// 对于当前词的每一个字符
			{
				string new_word(s);
				for (char c = 'a'; c <= 'z'; ++c)
				{
					if (c == new_word[i]) continue;
					swap(c, new_word[i]);	// 从a到c，如果与当前字符不一样，就放到新词该位置

					if ((dict.count(new_word) > 0 || new_word == end) && !visited.count(new_word))	// 新生成的这个词是否在dict中，并且没有访问过
					{
						result.push_back(new_word);	// 记录该新词到新词表
						visited.insert(new_word);	// 记录该新词已经访问过
					}
					swap(c, new_word[i]);	// 把这个词换回去，因为一次只能改变一个字母
				}
			}
			return result;	// 返回当前词所有可能的下一词
		};

		current.push(start);	// 第一层只有起始词
		while (!current.empty() && !found)
		{
			while (!next.empty()) next.pop();	// 清空下一层的队列
			++level;
			while (!current.empty() && !found)
			{
				const string str = current.front();	// 取出当前词
				current.pop();

				const auto& new_states = state_extend(str);	// 得到所有可行下一词
#if __cplusplus < 201103L
				for (auto it = new_states.begin(); it != new_states.end(); ++it)
				{
					const auto& state = *it;
#else
				for (const auto& state : new_states)	// 在下一层中放入所有可行词，如果该可行词就是目标词就跳出
				{
#endif
					next.push(state);
					if (state_is_target(state))	
					{
						found = true;
						break;
					}
				}
			}
			swap (next, current);	// 把所有下一层的词放入当前词
		}	// 这样就形成了一层、又一层、再一层的广度搜索，直到找到目标词，并且最先找到的词一定是最小步数
		if (found) return level + 1;
		else return 0;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Word_Ladder", "[Breadth-First Search]"){
	Solution sln;
	unordered_set<string> dict;
	SECTION("Empty Input") {
		REQUIRE(sln.ladderLength("","",dict) == 0);
	}
	SECTION("Normal Input") {
		dict.insert("hot");
		dict.insert("dot");
		dict.insert("dog");
		dict.insert("lot");
		dict.insert("log");
		REQUIRE(sln.ladderLength("hit","cog",dict) == 5);
	}
}
