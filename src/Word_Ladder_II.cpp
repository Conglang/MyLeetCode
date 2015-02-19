//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2015/2/19
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given two words (start and end), and a dictionary, find all shortest transformation sequence(s) from start to end, such that:
* 
* Only one letter can be changed at a time
* Each intermediate word must exist in the dictionary
* For example,
* 
* Given:
* start = "hit"
* end = "cog"
* dict = ["hot","dot","dog","lot","log"]
* Return
*   [
*     ["hit","hot","dot","dog","cog"],
*     ["hit","hot","lot","log","cog"]
*   ]
* Note:
* All words have the same length.
* All words contain only lowercase alphabetic characters.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 广度优先遍历的同时把经过路径的父亲存在一棵树里，然后深度优先遍历生成路径。
// 时间复杂度O(n)，空间复杂度O(n)。
class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		unordered_set<string> current, next;	// 当前层，下一层，用集合是为了去重
		unordered_set<string> visited;	// 判重
		unordered_map<string, vector<string> > father;	// 树
		bool found = false;	// 是否走到目标单词

		auto state_is_target = [&](const string &s) {return s == end;};	// 判断是否是目标单词的lambda函数
		auto state_extend = [&](const string &s)->unordered_set<string> {	// 从当前词找到下一个所有可行词的lambda函数
			unordered_set<string> result;	// 用set去重。

			for (size_t i = 0; i < s.size(); ++i)	// 对于当前词的每一个字符
			{
				string new_word(s);
				for (char c = 'a'; c <= 'z'; ++c)
				{
					if (c == new_word[i]) continue;
					swap(c, new_word[i]);	// 从a到c，如果与当前字符不一样，就放到新词该位置

					if ((dict.count(new_word) > 0 || new_word == end) && !visited.count(new_word))
					{
						result.insert(new_word);	// 记录该新词到新词表
					}
					swap(c, new_word[i]);	// 把这个词换回去，因为一次只能改变一个字母
				}
			}
			return result;	// 返回当前词所有可能的下一词
		};

		current.insert(start);	// 第一层只有起始词
		while (!current.empty() && !found)
		{
			// 先将本层全部置为已访问，防止同层之间互相指向
#if __cplusplus < 201103L
			for (auto it = current.begin(); it != current.end(); ++it)
			{
				const auto& word = *it;
#else
			for (const auto& word : current)
			{
#endif
				visited.insert(word);
			}
#if __cplusplus < 201103L
			for (auto it = current.begin(); it != current.end(); ++it)
			{
				const auto& word = *it;
#else
			for (const auto& word : current)
			{
#endif
				const auto new_states = state_extend(word);
#if __cplusplus < 201103L
				for (auto sit = new_states.begin(); sit != new_states.end(); ++sit)
				{
					const auto& state = *sit;
#else
				for (const auto &state : new_states) 
				{
#endif
					if (state_is_target(state)) found = true;
					next.insert(state);
					father[state].push_back(word);
				}
			}
			current.clear();
			swap (next, current);	// 把所有下一层的词放入当前词
		}
		vector<vector<string> > result;
		if (found)
		{
			vector<string> path;
			generate_path(father, path, start, end, result);	// 用深度优先生成路径
		}
		return result;
	}
private:
	void generate_path(unordered_map<string, vector<string> > &father, vector<string> &path, const string &start, const string &word,		vector<vector<string> > &result)
	{
		path.push_back(word);
		if (word == start) {
			result.push_back(path);
			reverse(result.back().begin(), result.back().end());
		} else {
#if __cplusplus < 201103L
			for (auto sit = father[word].begin(); sit != father[word].end(); ++sit)
			{
				const auto& f = *sit;
#else
			for (const auto& f : father[word]) {
#endif
				generate_path(father, path, start, f, result);
			}
		}
		path.pop_back();
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Word_Ladder_II", "[Breadth-First Search]"){
	Solution sln;
	unordered_set<string> dict;
	vector<vector<string> > result;
	SECTION("Empty Input") {
		REQUIRE(sln.findLadders("","",dict) == result);
	}
	SECTION("Normal Input1") {
		dict.insert("a");
		dict.insert("b");
		dict.insert("c");
		vector<string> temp;
		temp.push_back("a");
		temp.push_back("c");
		result.push_back(temp);
		REQUIRE(sln.findLadders("a","c",dict) == result);
	}
	SECTION("Normal Input2") {
		dict.insert("hot");
		dict.insert("dot");
		dict.insert("dog");
		dict.insert("lot");
		dict.insert("log");
		string t[5] = {"hit","hot","lot","log","cog"};
		string e[5] = {"hit","hot","dot","dog","cog"};
		vector<string> temp(t,t+5);
		result.push_back(temp);
		temp.assign(e,e+5);
		result.push_back(temp);
		REQUIRE(sln.findLadders("hit","cog",dict) == result);
	}
}