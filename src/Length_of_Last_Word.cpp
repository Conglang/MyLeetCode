//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/11/2
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
* 
* If the last word does not exist, return 0.
* 
* Note: A word is defined as a character sequence consists of non-space characters only.
* 
* For example, 
* Given s = "Hello World",
* return 5.
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int length = 0;
		while (*s)
		{
			if (*s++ != ' '){ ++length;}	// �ж�����е�++���ǻ�ִ�е�
			else if (*s && *s != ' ')	// ����ж����Ҳ���ǻ�ִ��
			{
				length = 0;
			}
		}
		return length;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Length_of_Last_Word", "[Strings]"){
	Solution s;
	SECTION("Empty Input"){
		REQUIRE(s.lengthOfLastWord("") == 0);
	}
	SECTION("Normal Input"){
		REQUIRE(s.lengthOfLastWord("haha hehe guagua ha!") == 3);
		REQUIRE(s.lengthOfLastWord("haha  hehehe     ") == 6);
		REQUIRE(s.lengthOfLastWord("haha") == 4);
	}
}
