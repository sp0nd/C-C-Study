#include <iostream>
#include <string>
#include "mylinkedlist.h"

using namespace std;

void main(void)
{
	mylinkedlist ll;

	ll.addnode(0, "ȫ�浿", 2000, 1, 1);
	ll.addnode(1, "ȫ�̵�", 2001, 1, 2);
	ll.addnode(2, "ȫ�ﵿ", 2002, 1, 3);
	ll.addnode(3, "ȫ�絿", 2003, 1, 4);
	ll.addnode(4, "ȫ����", 2004, 1, 5);

	ll.display();
	cout << endl;

	ll.insertnode(2, 10, "��ö��", 2020, 1, 1);

	ll.display();
	cout << endl;

	system("pause");
}