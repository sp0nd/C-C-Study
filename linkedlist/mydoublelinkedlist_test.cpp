#include <iostream>
#include <string>
#include<stdlib.h>
#include "mydoublelinkedlist.h"

using namespace std;

void main(void)
{
	MyDoubleLinkedList ll;
	cout << "GNode" << endl;
	ll.Front(0, "ȫ�浿", 2000, 1, 1);
	ll.display();
	cout << endl;
	cout << "Frontadd " << endl;
	ll.Front(10,"kkk",2222,2,2);
	ll.display();
	cout << endl;
	cout << "Backadd " << endl;
	ll.Back(11,"tttt", 3333, 3, 3);
	ll.display();
	cout << endl;
	ll.insertNode();//int id, int _id, string name, int y, int m, int d
	


	system("pause");
}