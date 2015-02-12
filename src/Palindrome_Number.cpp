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
// ʱ�临�Ӷ�O(1)���ռ临�Ӷ�O(1)��
// ���ϵ�ȡ��һλ�����һλ(10������)���бȽϣ������ȡ�ڶ�λ�͵����ڶ�λ��
// ֱ����ɱȽϻ�����;�ҵ��˲�һ�µ�λ��
class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)		{return false;}	// �������ǻ�����
		if (x < 10)	{return true;}		// һλ���ǻ�����
		int divisor(1);
		while (x / divisor >= 10)		// �õ�Ϊ�˵õ����λ���ֵĳ���
		{
			divisor *= 10;
		};
		while (x / 10 && divisor > 0)	// ʣ�µ�����������λ���ҳ�����Ϊ0
		{
			if (x % 10 != (x / divisor) % 10)
			{
				return false;
			}
			x = x / 10;		// Ϊ�˷�ֹ1000021�������͵����ֽ�0�õ���x������ȥ���λ��
			divisor /= 100;	// ��Ϊ�����õ����λ������ÿ��Ӧ����100
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