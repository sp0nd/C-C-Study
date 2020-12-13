/* chainiterator.cpp - iterator class�� ����ϴ� �ǽ� */
/*
 - template ���ÿ� chain.h, chain.cpp => ���ε� ó���� �ȵ� - visual studio2019�� ����
 - template ���ÿ� �ϳ��� file�� ó��
*/
// Chain iterator �ǽ� - TODO�� �ּ�ó�� �Ǿ� �ִ� �κ��� ���� �ǽ��� �� ��.
/*
�ִ�, �ּ�, ��� ���� ���ϴ� �Լ� �ۼ� �ɷ�
*/
#include <iostream>
#include "Chain.h"

using namespace std;

/* template function */
template <class T>
int Show(const Chain<T>& l) {
	ChainIterator<T> li(l); //li is associated with list l
	if (!li.NotNull()) return 0; //empty list, return 0
	T retvalue = *li.First();//get first element
	cout << retvalue;
	while (li.NextNotNull()) //make sure that next element exists
	{
		retvalue = *li.Next();
		cout << " <- " << retvalue;
	}
	return retvalue;
}
template <class T>
int sum(const Chain<T>& l) {
	ChainIterator<T> li(l);    //li is associated with list l
	if (!li.NotNull()) return 0; //empty list, return 0
	T retvalue = *li.First();    //get first element
	while (li.NextNotNull())  //make sure that next element exists
		retvalue += *li.Next();
	return retvalue;
}
template <class T>
int SumProductFifth(const Chain<T>& l) {
	// sum(Xi * Xi+5)
	return 0;
}

template <class T>
int Length(const Chain<T>& l) {
	// list�� ����
	return 0;
}
template <class T>
int Maximum(const Chain<T>& l) {
	// list���� �ִ밪
	return 0;
}
template <class T>
int Minimum(const Chain<T>& l) {
	// list���� �ּҰ�
	return 0;
}
template <class T>
int MakeArray(const Chain<T>& l, int []) {
	//list ���Ҹ� �о� �迭�� ����
	return 0;
}
int main(void) {
	int select;
	//ChainNode<int> nd;
	Chain<int> a, b;
	ChainIterator<int> cit(a);
	int value;
	do
	{
		cout << endl << "1. Add new value to chain 'A'" << endl << "2. Add new value to chain 'B'"
			<< endl << "3. Print all chains" << endl << "4. Invert chain" 
			<< endl << "5. Concatenate A and B" << endl << "6. Delete first node in chain"
			<< endl << "7. Get Sum of the chain" << endl << "8. Get length of the chain" 
			<< endl << "9. Get maximum value in chain" << endl<< "10. Quit" << endl << endl;
		cout << "Select command (1~10) : ";
		cin >> select;
		switch (select)
		{
			// Case 1 : Add new value to chain 'A'
		case 1:
			cout << "Add a new value: ";
			cin >> value;
			a.Add(value);
			break;
				
			// Case 2 : Add new value to chain 'B'
		case 2:
			cout << "Add a new value: ";
			cin >> value;
			b.Add(value);
			break;

			// Case 3 : Print all chains
		case 3:
			cout << "Chain A : ";
			Show(a);
			cout << endl;
			cout << "Chain B : ";
			Show(b);
			cout << endl;
			break;

			// Case 4 : Invert chain
		case 4:
			cout << endl << "Which chain will you invert?" << endl << "1. Chain A" << endl << "2. Chain B" << endl << endl << "Select command (1~2) : ";
			cin >> value;
			if (value == 1)
				a.Invert();
			else if (value == 2)
				b.Invert();
			else
				cout << "Invalid value! Return to menu..." << endl;
			break;

			// Case 5 : Concatenate A and B
		case 5:
			cout << endl << "Concatenated chain" << endl;
			a.Concatenate(b);
			Show(a);
			cout << endl;
			break;

			// Case 6 : Delete first node in chain
		case 6:
			cout << endl << "Which chain will you delete?" << endl << "[1] Chain A" << endl << "[2] Chain B" << endl << endl << "Select command (1~2) : ";
			cin >> value;

			if (value == 1)
				a.Delete();
			else if (value == 2)
				b.Delete();
			else
				cout << "Invalid value! Return to menu..." << endl;
			break;

			// Case 7 : Get Sum of the chain
		case 7:
			cout << endl << "Which chain will you sum?" << endl << "1. Chain A" << endl << "2. Chain B" << endl << endl << "Select command (1~2) : ";
			cin >> value;

			if (value == 1)
				sum(a);
			else if (value == 2)
				sum(b);
			else
				cout << "Invalid value! Return to menu..." << endl;
			break;

			// Case 8 : Get length of the chain
		case 8:
			// TODO : Counting the number of nodes by using iterator class
			cout << endl << "Which chain's length do you want?" << endl << "[1] Chain A" << endl << "[2] Chain B" << endl << endl << "Select command (1~2) : ";
			cin >> value;

			if (value == 1)
				cout << Length(a) << endl;
			else if (value == 2)
				cout << Length(b) << endl;
			else
				cout << "Invalid value! Return to menu..." << endl;
			break;
			// Case 9 : Get maximum value in chain
		case 9:
			// TODO : Find node with maximum value by using iterator class
			cout << endl << "Which chain's max-value do you want?" << endl << "[1] Chain A" << endl << "[2] Chain B" << endl << endl << "Select command (1~2) : ";
			cin >> value;

			if (value == 1)
				cout << Maximum(a) << endl;
			else if (value == 2)
				cout << Maximum(b) << endl;
			else
				cout << "Invalid value! Return to menu..." << endl;
			break;

			// Case q : Quit the program
		case 10:
			cout << "Quit the program..." << endl;
			break;
		default:
			cout << "WRONG INPUT" << endl;
		}
	} while (select != 10);
	system("pause");
	return 0;
}