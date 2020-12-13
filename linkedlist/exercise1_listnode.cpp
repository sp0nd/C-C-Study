//exercise: list iterator
#include <iostream>
using namespace std;

class List;

class Node {
	friend class List;
private:
	int num;// 난수를 생성하여 입력한다
	Node* link;
};

class List {
private:
	Node* first;
public:
	List();
	List(int);
	List(const List&);//list를 복사
	List& addList(List&);//a = a+ b(a1 a2 a3 b1 b2 b3 b4)
	void addNode(int);
	void showList();
	int mergeList(List&);//a = a1, b1, a2, b2 등으로 값을 비교하면서 merge
	/*
	friend istream& operator>>(istream&, List&);//List 입력
	friend ostream& operator<<(ostream&, List&);//List 출력
	*/
	List& operator=(const List& l);//list의 first만 복사하는 것으로 구현
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
	MakeList(a1, 10);//난수를 생성하여 노드를 생성, 10은 노드 갯수
	MakeList(a2, 5);//a2가 empty list이거나 임의 list일 때도 동작 가능할 것
	a1.showList();//원형(circular) 리스트이므로 2번 출력하게 구현
	//cout <<a1;
	//cout << a2
	a2.showList();
	List a3 = a1.addList(a2);//복사 생성자를 사용하는 실습

	a3.showList();
	List a4 = a1.mergeList(a2);
	List a5;
	a5 = a4; //assign operator의 overloading
	cout << a4;
	return 1;

}
