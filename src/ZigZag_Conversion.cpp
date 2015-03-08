//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/31
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
* 
* P   A   H   N
* A P L S I I G
* Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
* Write the code that will take a string and make this conversion given a number of rows:
* 
* string convert(string text, int nRows);
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
//--------------------------------------------------------------------------------------------------------------*/
#include "../include/include.h"
// ����ѧ����
/*
*	n = 4:
*	P     I     N
*	A   L s   i G
*	Y A   H R
*	P     I
*	
*	n = 5:
*	P       H
*	A     S I
*	Y   I   R
*	P L     I G
*	A       N
*	
*	�кź��кŴ�0��ʼ����һ��ֱ�к�һб�Խ���Ϊһ�С�
*	
*	���ԣ�����ÿһ�㴹ֱԪ�ص�����index = (2 * nRows - 2) * j + i��
*	����ÿ���㴹ֱԪ��֮��Ĳ���Ԫ��(б�Խ�Ԫ��)��indexD = index + (nRows - i - 1) * 2��
*	
*	��n=4�У�
*	index(s) = (2 * 4 - 2) * 1 + 1 = 7����ԭ�ַ���0��ʼ����s��7����
*	indexD(i) = index(s) + (4 - 1 - 1) * 2 = 11����ԭ�ַ���0��ʼ����i��11����
*/
class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows <= 1 || s.size() <= 1) return s;
		string result;
		for (int i = 0; i < nRows; ++i)
		{
			for (int j = 0, index = i; index < s.size(); ++j, index = (2 * nRows - 2) * j + i)
			{
				result.append(1, s[index]);	// ��ֱԪ��
				if (i == 0 || i == nRows - 1) continue;	// б�Խ�Ԫ��
				if (index + (nRows - i - 1) * 2 < s.size())
				{
					result.append(1, s[index + (nRows - i - 1) * 2]);
				}
			}
		}
		return result;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Zigzag Conversion", "[Detail]"){
	Solution sln;
	SECTION("Empty Input"){
		REQUIRE(sln.convert("", 5) == "");
		REQUIRE(sln.convert("ABC", 1) == "ABC");
	}
	SECTION("Normal Input"){
		REQUIRE(sln.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
		REQUIRE(sln.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
	}
}
