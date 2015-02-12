//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:			YanShicong
//		Date:			2014/10/26
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
* Determine whether an integer is a palindrome. Do this without extra space.
* 
* click to show spoilers.
* 
* Some hints:
* Could negative integers be palindromes? (ie, -1)
* 
* If you are thinking of converting the integer to string, note the restriction of using extra space.
* 
* You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
* 
* There is a more generic way of solving this problem.
//--------------------------------------------------------------------------------------------------------------*/
#include "../project/include.h"
// 时间复杂度O(1)，空间复杂度O(1)。
// 不断地取第一位和最后一位(10进制下)进行比较，相等则取第二位和倒数第二位，
// 直到完成比较或者中途找到了不一致的位。
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)		{return false;}	// 负数不是回文数
		if (x < 10)	{return true;}		// 一位数是回文数
		int divisor(1);
		while (x / divisor >= 10)		// 得到为了得到最高位数字的除数
		{
			divisor *= 10;
		};
		while (x / 10 && divisor > 0)	// 剩下的数字至少两位并且除数不为0
		{
			if (x % 10 != (x / divisor) % 10)
			{
				return false;
			}
			x = x / 10;		// 为了防止1000021这种类型的数字将0裁掉，x并不减去最高位。
			divisor /= 100;	// 因为并不裁掉最高位，除数每次应除以100
		}
		return true;
	}
};
//--------------------------------------------------------------------------------------------------------------
TEST_CASE("Palindrome_Number", "[Detail]"){
	Solution sln;
	SECTION("Normal Input"){
		REQUIRE(sln.isPalindrome(0) == true);
		REQUIRE(sln.isPalindrome(-0) == true);
		REQUIRE(sln.isPalindrome(-11) == false);
		REQUIRE(sln.isPalindrome(121) == true);
		REQUIRE(sln.isPalindrome(123321) == true);
	}
}