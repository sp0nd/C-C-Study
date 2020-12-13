//exercise: list iterator
#include <iostream>
using namespace std;

class List;

class Node {
	friend class List;
private:
	int num;// ������ �����Ͽ� �Է��Ѵ�
	Node* link;
};

class List {
private:
	Node* first;
public:
	List();
	List(int);
	List(const List&);//list�� ����
	List& addList(List&);//a = a+ b(a1 a2 a3 b1 b2 b3 b4)
	void addNode(int);
	void showList();
	int mergeList(List&);//a = a1, b1, a2, b2 ������ ���� ���ϸ鼭 merge
	/*
	friend istream& operator>>(istream&, List&);//List �Է�
	friend ostream& operator<<(ostream&, List&);//List ���
	*/
	List& operator=(const List& l);//list�� first�� �����ϴ� ������ ����
};

ostream& operator<<(ostream& os, List& l)
{
		return os;
}
istream& operator>>(istream& is, List& l)
{
	return is;
}

int main(void)
{
	List a1, a2;
	MakeList(a1, 10);//������ �����Ͽ� ��带 ����, 10�� ��� ����
	MakeList(a2, 5);//a2�� empty list�̰ų� ���� list�� ���� ���� ������ ��
	a1.showList();//����(circular) ����Ʈ�̹Ƿ� 2�� ����ϰ� ����
	//cout <<a1;
	//cout << a2
	a2.showList();
	List a3 = a1.addList(a2);//���� �����ڸ� ����ϴ� �ǽ�

	a3.showList();
	List a4 = a1.mergeList(a2);
	List a5;
	a5 = a4; //assign operator�� overloading
	cout << a4;
	return 1;

}
