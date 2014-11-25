//////////////////////////////////////////////////////
//		Project:		MyLeetCode
//
//		Author:		YanShicong
//		Date:			2014/11/25
//////////////////////////////////////////////////////
/*--------------------------------------------------------------------------------------------------------------
Evaluate the value of an arithmetic expression in Reverse Polish Notation.
http://en.wikipedia.org/wiki/Reverse_Polish_notation

Valid operators are +, -, *, /. Each operand may be an integer or another expression.

Some examples:
["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6
//--------------------------------------------------------------------------------------------------------------*/
// Learned Way
class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<string> cal_stack;	// ջ�д��ַ���
		for (auto token : tokens)
		{
			if (!is_operator(token))
			{
				cal_stack.push(token);
			}else
			{
				int y = stoi(cal_stack.top());	// stoi
				cal_stack.pop();
				int x = stoi(cal_stack.top());
				cal_stack.pop();
				if (token[0] == '+') { x += y;}	// ��������������һ������
				else if (token[0] == '-') { x -= y;}
				else if (token[0] == '*') { x *= y;}
				else if (token[0] == '/') { x /= y;}
				cal_stack.push(to_string(x));	// to_string
			}
		}
		return stoi(cal_stack.top());
	}
private:
	bool is_operator(const string& op)
	{
		return op.size() == 1 && string("+-*/").find(op) != string::npos;	// ����д���ܺã��ж�ĳstring�ڲ�������ѡ��֮��
	}
};