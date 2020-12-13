//exercise: circular lined list
#include <iostream>
using namespace std;

class List;

class Node {
	friend class List;
private:
	float coef;
	int exp;
	Node* link;
};

class List {
private:
	Node* first;
public:
	List();//�����ڰ� head node �� ����
	List& addList(List&);
	void addNode(float, int);
	void showList();
};


int main(void)
{
	List a1, a2;
	MakeList(a1);//������ ����� �Է��Ͽ� ó��
	MakeList(a2);
	a1.showList();
	//cout <<a1;
	//cout << a2
	a2.showList();
	List a3 = a1.addList(a2);
	a3.showList();
	//cout << a3;
	return 1;

}
