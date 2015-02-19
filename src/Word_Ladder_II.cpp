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
// ������ȱ�����ͬʱ�Ѿ���·���ĸ��״���һ�����Ȼ��������ȱ�������·����
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)��
class Solution {
public:
	vector<vector<string>> findLadders(string start, string end, unordered_set<string> &dict) {
		unordered_set<string> current, next;	// ��ǰ�㣬��һ�㣬�ü�����Ϊ��ȥ��
		unordered_set<string> visited;	// ����
		unordered_map<string, vector<string> > father;	// ��
		bool found = false;	// �Ƿ��ߵ�Ŀ�굥��

		auto state_is_target = [&](const string &s) {return s == end;};	// �ж��Ƿ���Ŀ�굥�ʵ�lambda����
		auto state_extend = [&](const string &s)->unordered_set<string> {	// �ӵ�ǰ���ҵ���һ�����п��дʵ�lambda����
			unordered_set<string> result;	// ��setȥ�ء�

			for (size_t i = 0; i < s.size(); ++i)	// ���ڵ�ǰ�ʵ�ÿһ���ַ�
			{
				string new_word(s);
				for (char c = 'a'; c <= 'z'; ++c)
				{
					if (c == new_word[i]) continue;
					swap(c, new_word[i]);	// ��a��c������뵱ǰ�ַ���һ�����ͷŵ��´ʸ�λ��

					if ((dict.count(new_word) > 0 || new_word == end) && !visited.count(new_word))
					{
						result.insert(new_word);	// ��¼���´ʵ��´ʱ�
					}
					swap(c, new_word[i]);	// ������ʻ���ȥ����Ϊһ��ֻ�ܸı�һ����ĸ
				}
			}
			return result;	// ���ص�ǰ�����п��ܵ���һ��
		};

		current.insert(start);	// ��һ��ֻ����ʼ��
		while (!current.empty() && !found)
		{
			// �Ƚ�����ȫ����Ϊ�ѷ��ʣ���ֹͬ��֮�以��ָ��
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
			swap (next, current);	// ��������һ��Ĵʷ��뵱ǰ��
		}
		vector<vector<string> > result;
		if (found)
		{
			vector<string> path;
			generate_path(father, path, start, end, result);	// �������������·��
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