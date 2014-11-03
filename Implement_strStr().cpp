//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/3
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
//--------------------------------------------------------------------------------------------------------------*/
// My way. 先知道两者的长度才能在后面查找的时候做终止优化。
class Solution {
public:
	int strStr(char *haystack, char *needle) {
		int haystack_len = 0;
		int needle_len = 0;
		while (needle[needle_len])
		{
			++needle_len;
		}
		while (haystack[haystack_len])
		{
			++haystack_len;
		}

		if (!needle_len) {return 0;}

		for (int h_it = 0; h_it < haystack_len - needle_len + 1; ++h_it)
		{
			int n_it = 0;
			while (n_it < needle_len && needle[n_it] == haystack[h_it + n_it])
			{
				++n_it;
				if (n_it == needle_len)
				{
					return h_it;
				}
			}
		}
		return -1;
	}
};