#include <iostream>
#include <string>
#include "mylinkedlist.h"

using namespace std;

void main(void)
{
	mylinkedlist ll;

	ll.addnode(0, "È«±æµ¿", 2000, 1, 1);
	ll.addnode(1, "È«ÀÌµ¿", 2001, 1, 2);
	ll.addnode(2, "È«»ïµ¿", 2002, 1, 3);
	ll.addnode(3, "È«»çµ¿", 2003, 1, 4);
	ll.addnode(4, "È«¿Àµ¿", 2004, 1, 5);

	ll.display();
	cout << endl;

	ll.insertnode(2, 10, "±èÃ¶¼ö", 2020, 1, 1);

	ll.display();
	cout << endl;

	system("pause");
}