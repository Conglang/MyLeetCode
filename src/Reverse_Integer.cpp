//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

click to show spoilers.

Have you thought about this?
Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

Throw an exception? Good, but what if throwing an exception is not an option? You would then have to re-design the function (ie, add an extra parameter).
//--------------------------------------------------------------------------------------------------------------*/

// My Way
class Solution {
public:
	int reverse(int x) {
		int result(0);
		while(x)
		{
			int y = x / 10;
			result *= 10;
			result += x % 10;
			x = y;
		}
		return result;
	}
};
//---------------------------------------------------
// A Cleaner Way
// ʱ�临�Ӷ� O(logn) ���ռ临�Ӷ� O(1)
class Solution {
public:
	int reverse (int x) {
		int r = 0;
		for (; x; x /= 10)
			r = r * 10 + x % 10;
		return r;
	}
};