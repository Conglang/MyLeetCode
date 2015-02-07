//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/12/12
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Given two words (start and end), and a dictionary, find the length of shortest transformation sequence from start to end, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
	Return 0 if there is no such transformation sequence.
	All words have the same length.
	All words contain only lowercase alphabetic characters.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
// ��ȱ����㷨��
class Solution {
public:
	int ladderLength(string start, string end, unordered_set<string> &dict) {
		queue<string> current, next;	// ��ǰ�㣬��һ��
		unordered_set<string> visited;	// ����

		int level(0);	// ���
		bool found(false);	// �Ƿ��ߵ�Ŀ�굥��

		auto state_is_target = [&](const string &s) {return s == end;};	// �ж��Ƿ���Ŀ�굥�ʵ�lambda����
		auto state_extend = [&](const string &s){	// �ӵ�ǰ���ҵ���һ�����п��дʵ�lambda����
			vector<string> result;

			for (size_t i = 0; i < s.size(); ++i)	// ���ڵ�ǰ�ʵ�ÿһ���ַ�
			{
				string new_word(s);
				for (char c = 'a'; c <= 'z'; ++c)
				{
					if (c == new_word[i]) continue;
					swap(c, new_word[i]);	// ��a��c������뵱ǰ�ַ���һ�����ͷŵ��´ʸ�λ��

					if (dict.count(new_word) > 0 && !visited.count(new_word))	// �����ɵ�������Ƿ���dict�У�����û�з��ʹ�
					{
						result.push_back(new_word);	// ��¼���´ʵ��´ʱ�
						visited.insert(new_word);	// ��¼���´��Ѿ����ʹ�
					}
					swap(c, new_word[i]);	// ������ʻ���ȥ����Ϊһ��ֻ�ܸı�һ����ĸ
				}
			}
			return result;	// ���ص�ǰ�����п��ܵ���һ��
		};

		current.push(start);	// ��һ��ֻ����ʼ��
		while (!current.empty() && !found)
		{
			while (!next.empty()) next.pop();	// �����һ���ջ
			++level;
			while (!current.empty() && !found)
			{
				const string str = current.front();	// ȡ����ǰ��
				current.pop();

				const auto& new_states = state_extend(str);	// �õ����п�����һ��
				for (const auto& state : new_states)	// ����һ���з������п��дʣ�����ÿ��дʾ���Ŀ��ʾ�����
				{
					next.push(state);
					if (state_is_target(state))	
					{
						found = true;
						break;
					}
				}
			}
			swap (next, current);	// ��������һ��Ĵʷ��뵱ǰ��
		}	// �������γ���һ�㡢��һ�㡢��һ��Ĺ��������ֱ���ҵ�Ŀ��ʣ����������ҵ��Ĵ�һ������С����
		if (found) return level + 1;
		else return 0;
	}
};