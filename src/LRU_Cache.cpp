//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/19
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
set(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
/*
	Ϊ��ʹ���ҡ������ɾ�����нϸߵ����ܣ�����ʹ��һ��˫������ (std::list) ��һ����ϣ��(std::unordered_map)����Ϊ��
		��ϣ����ÿ���ڵ�ĵ�ַ�����Ի�����֤��O(1)ʱ���ڲ��ҽڵ�
		˫����������ɾ��Ч�ʸߣ�������������ɾ��ʱ����Ҫ���ҽڵ��ǰ���ڵ�
	����ʵ��ϸ�ڣ�
		Խ��������ͷ������ʾ�ڵ��ϴη��ʾ�������ʱ����̣�β���Ľڵ��ʾ�����������
		���ʽڵ�ʱ������ڵ���ڣ��Ѹýڵ㽻��������ͷ����ͬʱ����hash���иýڵ�ĵ�ַ
		����ڵ�ʱ�����cache��size�ﵽ������capacity����ɾ��β���ڵ㣬ͬʱҪ�� hash ����ɾ����Ӧ����½ڵ��������ͷ����
*/
// ʱ�临�Ӷ�O(logn)���ռ临�Ӷ�O(n)
class LRUCache{
private:
	struct CacheNode{
		int key;
		int value;
		CacheNode(int k, int v) : key(k), value(v){}
	};
public:
	LRUCache(int capacity) {
		m_capacity = capacity;
	}

	int get(int key) {
		if (m_cachemap.find(key) == m_cachemap.end()) {return -1;}
		// �ѵ�ǰ���ʵĽڵ��Ƶ�����ͷ�������Ҹ���map�иýڵ�ĵ�ַ��
		m_cachelist.splice(m_cachelist.begin(), m_cachelist, m_cachemap[key]);
		m_cachemap[key] = m_cachelist.begin();
		return m_cachemap[key]->value;
	}

	void set(int key, int value) {
		if (m_cachemap.find(key) == m_cachemap.end())
		{
			// ����������ߴ磬ɾ������β���ڵ㣬���������ٵĽڵ㡣
			if (m_cachelist.size() == m_capacity)
			{
				m_cachemap.erase(m_cachelist.back().key);
				m_cachelist.pop_back();
			}
			// �����½ڵ㵽����ͷ����������map�����Ӹýڵ㡣
			m_cachelist.push_front(CacheNode(key, value));
			m_cachemap[key] = m_cachelist.begin();
		}else
		{
			// ���½ڵ��ֵ���ѵ�ǰ���ʵĽڵ��Ƶ�����ͷ�������Ҹ���map�иýڵ�ĵ�ַ��
			m_cachemap[key]->value = value;
			m_cachelist.splice(m_cachelist.begin(), m_cachelist, m_cachemap[key]);
			m_cachemap[key] = m_cachelist.begin();
		}
	}

private:
	list<CacheNode> m_cachelist;
	unordered_map<int, list<CacheNode>::iterator> m_cachemap;
	int m_capacity;
};