//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/31
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this:
* (you may want to display this pattern in a fixed font for better legibility)
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
// 找数学规律
/*
*	n = 4:
*	P     I     N
*	A   L S   i G
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
*	行号和列号从0开始，以一垂直列和一斜对角列为一列。
*	
*	所以，对于每一层垂直元素的坐标index = (2 * nRows - 2) * j + i。
*	对于每两层垂直元素之间的插入元素(斜对角元素)，indexD = index + (nRows - i - 1) * 2。
*	
*	如n=4中：
*	index(s) = (2 * 4 - 2) * 1 + 1 = 7，即原字符从0开始数，s在7处。
*	indexD(i) = index(s) + (4 - 1 - 1) * 2 = 11，即原字符从0开始数，i在11处。
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
				result.append(1, s[index]);	// 垂直元素
				if (i == 0 || i == nRows - 1) continue;	// 斜对角元素
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
