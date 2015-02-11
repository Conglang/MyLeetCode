#include "include.h"
vector<int> get_nodes_val( ListNode* head )
{
	vector<int> val;
	while (head)
	{
		val.push_back(head->val);
		head = head->next;
	}
	return val;
}
