#include <iostream>
#include <string>
#include "arraystack.h"

using namespace std;

int getpriority(char ch)
{
	char prec[5] = { '*', '/', '+', '-', '(' };
	char prio[5] = { 3, 3, 2, 2, 1 };

	for (int i = 0; i < 5; i++)
	{
		if (prec[i] == ch)	return prio[i];
	}
	return -1;
}

string Postfix_Notation(string& str)
{
	ArrayStack<char> opStack;
	string answer = "";
	string ops = "+-*/";

	int size = str.length();
	for (int i = 0; i < size; i++)
	{
		char ch = str.at(i);
		// '('�̸� ���ÿ� push
		if (ch == '(')
		{
			opStack.push(ch);
		}
		// ')'�̸� '('�� ���� ������ pop, ���
		else if (ch == ')')
		{
			while (opStack.top() != '(')
			{
				answer += opStack.top();
				opStack.pop();
			}
			opStack.pop();
		}
		// �����ڸ�
		else if (ops.find(ch) != -1)
		{
			// ������ ��������� push
			if (opStack.empty())
				opStack.push(ch);
			// ������� �ʴٸ� ��
			else
			{
				while (opStack.size() > 0)
				{
					// �켱 ���� �� �� �ۿ� �ִ� ���� ������ ������ ��� ��
					if (getpriority(opStack.top()) >= getpriority(ch))
					{
						answer += opStack.top();
						opStack.pop();
					}
					// �켱 ������ �ۿ� �ִ� ���� ������ �ݺ��� Ż��
					else
						break;
				}
				opStack.push(ch);
			}
		}
		// �ǿ������� ���
		else
			answer += ch;
	}
	// ������ �� �� ���� pop
	while (!opStack.empty())
	{
		answer += opStack.top();
		opStack.pop();
	}
	
	return answer;
}

int main()
{
	string instr;
	string ops = "+-*/";

	cout << "������ �Է��ϼ���(1~9):";
	cin >> instr;

	string ret = Postfix_Notation(instr);

	cout << ret << endl;

	// ���
	int res = 0;
	ArrayStack<char> calc;
	int size = ret.length();
	for (int i = 0; i < size; i++)
	{
		char ch = ret.at(i);

		// �����ڰ� �ƴϸ�
		if (ops.find(ch) == -1)
			calc.push(ch);
		else
		{
			int val1 = calc.top() - 48; calc.pop();
			int val2 = calc.top() - 48; calc.pop();
			switch (ch)
			{
			case '+': res = val1 + val2;	break;
			case '-': res = val1 - val2;	break;
			case '*': res = val1 * val2;	break;
			case '/': res = val1 / val2;	break;
			}
			calc.push(res + 48);
		}
	}

	cout << "result:" << res << endl;

	return 1;
}