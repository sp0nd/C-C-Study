#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	// ���� argument�� ������ ������ �����ְ� ����
	if (argc != 2)
	{
		cout << "usage : stack.exe filename" << endl;
		return 1;
	}

	// ���� ���� ����
	stack<char> S;

	// ������ ����. ���ϸ��� argv[1]�� �����Ǿ� �ִ�.
	FILE* fp = fopen(argv[1], "rt");
	if (!fp)
	{
		// ���� ���⿡ �����ϸ�
		cout << "failt to open File:" << argv[1] << endl;
		return 1;
	}

	char ch;
	try
	{
		// ���Ͽ��� ���� �ϳ��� �о� ���δ�. ���� ������(EOF)�̸� ������ ����
		while ((ch = fgetc(fp)) != EOF)
		{
			// ��ȣ�� ������ ���ÿ� �߰� ('{' �Ǵ� '(')
			if (ch == '{' || ch == '(')	S.push(ch);

			// ��ȣ�� ������ ���ð� �� ('}' �Ǵ� ')')
			if (ch == '}' || ch == ')')
			{
				if (S.empty())
				{
					// ������ ����ٸ� �����⵵ ���� �ݴ� ��ȣ�� �������Ƿ� ���ܸ� �߻�
					char msg[64];
					sprintf(msg, "Extra right paren - [%c]", ch);
					throw(exception (msg));
				}
				else
				{
					// ���ÿ� �����ʹ� ������ ��ȣ�� ¦�� ���� ������ ���ܸ� �߻�
					if ((ch == '}' && S.top() != '{') || (ch == ')' && S.top() != '('))
					{
						char msg[64];
						sprintf(msg, "Mismatch paren - [%c]", ch);
						throw(exception(msg));
					}
					// ���ÿ� �����Ͱ� �ְ� ����� ¦�� ������ pop
					else
						S.pop();
				}
			}
		}

		// ���������� ������ ��� ������
		if (S.empty())
			cout << "Match!!!" << endl;
		// ���������� ���ÿ� �����Ͱ� ������
		else
			cout << "Mismatch!!!" << endl;
	}
	catch (const exception& e)
	{
		// ���ܰ� �߻��Ǿ��� ��
		cout << e.what() << endl;
	}

	// ���� �ݱ�
	fclose(fp);

	return 1;
}