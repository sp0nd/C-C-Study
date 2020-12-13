#ifndef _MYDOUBLELINKEDLIST_H
#define _MYDOUBLELINKEDLIST_H

#include <string>
using namespace std;

typedef struct _dnode 
{
	int id;
	string name;
	int year, month, day;
	struct _dnode* prev;
	struct _dnode* next;
}DNODE;
class MyDoubleLinkedList
{
private:
	DNODE* head;
public:
	MyDoubleLinkedList();
	~MyDoubleLinkedList();
	/*void GNode(int id, string name, int y, int m, int d);
	void GNode(DNODE* node);*/
	
	void Front(int _id, string name, int y, int m, int d);
	void Back(int _id, string name, int y, int m, int d);
	void addNodeFront(DNODE* node);
	void addNodeBack(DNODE* node);
	void insertNode(int id, int _id, string name, int y, int m, int d);
	void insertNode(int _id, DNODE* _node);
	void deleteNode(DNODE* _node);
	void searchNode(string name, int y, int m, int d);
	void displayFoward();
	void displayBackward();
	void display();
};
#endif