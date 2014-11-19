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
	为了使查找、插入和删除都有较高的性能，我们使用一个双向链表 (std::list) 和一个哈希表(std::unordered_map)，因为：
		哈希表保存每个节点的地址，可以基本保证在O(1)时间内查找节点
		双向链表插入和删除效率高，单向链表插入和删除时，还要查找节点的前驱节点
	具体实现细节：
		越靠近链表头部，表示节点上次访问距离现在时间最短，尾部的节点表示最近访问最少
		访问节点时，如果节点存在，把该节点交换到链表头部，同时更新hash表中该节点的地址
		插入节点时，如果cache的size达到了上限capacity，则删除尾部节点，同时要在 hash 表中删除对应的项；新节点插入链表头部。
*/
// 时间复杂度O(logn)，空间复杂度O(n)
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
		// 把当前访问的节点移到链表头部，并且更新map中该节点的地址。
		m_cachelist.splice(m_cachelist.begin(), m_cachelist, m_cachemap[key]);
		m_cachemap[key] = m_cachelist.begin();
		return m_cachemap[key]->value;
	}

	void set(int key, int value) {
		if (m_cachemap.find(key) == m_cachemap.end())
		{
			// 如果到达最大尺寸，删除链表尾部节点，即访问最少的节点。
			if (m_cachelist.size() == m_capacity)
			{
				m_cachemap.erase(m_cachelist.back().key);
				m_cachelist.pop_back();
			}
			// 插入新节点到链表头部，并且在map中增加该节点。
			m_cachelist.push_front(CacheNode(key, value));
			m_cachemap[key] = m_cachelist.begin();
		}else
		{
			// 更新节点的值，把当前访问的节点移到链表头部，并且更新map中该节点的地址。
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