//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/10/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
//--------------------------------------------------------------------------------------------------------------*/
/*
细节题。注意几个测试用例：
	1. 不规则输入，但是有效， ”-3924x8fc”， ” + 413”,
	2. 无效格式， ” ++c”, ” ++1”
	3. 溢出数据， ”2147483648”
*/

class Solution {
public:
	int atoi(const char *str) {
		bool is_minus(false);
		int num(0);
		const int n(strlen(str));
		int i(0);

		// 先除空格
		while (str[i] == ' ') i++;

		// 再看符号
		if (str[i] == '+')
		{
			is_minus = false;
			i++;
		}
		else if (str[i] == '-')
		{
			is_minus = true;
			i++;
		}

		// 处理数字
		for (; i < n; ++i)
		{
			if (str[i] >= '0' && str[i] <= '9')
			{
				if (is_minus)
				{
					if ((num < -2147483648 / 10) || ((num == -2147483648 / 10) && ('0' - str[i] < -2147483648 % 10)))
					{
						return -2147483648;
					}else
					{
						num = num * 10 - str[i] + '0';
					}
				}else
				{
					if ((num > 2147483647 / 10) || ((num == 2147483647 / 10) && (str[i] - '0' > 2147483647 % 10)))
					{
						return 2147483647;
					}else
					{
						num = num * 10 + str[i] - '0';
					}
				}
			}
			else
			{
				break;
			}
		}
		return num;
	}
};