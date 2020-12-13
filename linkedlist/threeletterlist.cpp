/* threeletterlist.cpp - nested class*/
//program 4.1: composite classes
/* �л����� class�� ���� �Լ��� ����� �ǽ� */
#include <iostream>
using namespace std;

class ThreeLetterList;

class ThreeLetterNode {
	friend class ThreeLetterList;
private:
	char data[3];
	ThreeLetterNode* link;
};

class ThreeLetterList {
private:
	class ThreeLetterNode {
	public:
		char data[3];
		ThreeLetterNode* link;
	};
	ThreeLetterNode* first;
public:
	void test();
	void add(char, char, char);
	void display();
};
void ThreeLetterList::add(char a, char b, char c) {
	//�л����� �ǽ��ϴ� ���� �ʿ�
}
void ThreeLetterList::display() {
	////�л����� �ǽ��ϴ� ���� �ʿ�
}
void ThreeLetterList::test()
{
	ThreeLetterNode* f = new ThreeLetterNode;
	f->data[0] = 'a';
	f->data[1] = 'b';
	f->data[2] = 'c';
	f->link = 0;
}

int main(void)
{
	ThreeLetterList l;
	l.test();
	l.add('d', 'e', 'f');

}
