#ifndef _MYLINKEDLIST_H_
#define _MYLINKEDLIST_H_

#include <string>

using namespace std;

typedef struct _tnode
{
	int id;
	string name;
	int year, month, day;
	struct _tnode* next;
}TNODE;
class mylinkedlist
{
private:
	TNODE* head;
public:
	mylinkedlist();
	~mylinkedlist();
	void addnode(int id, string name, int y, int m, int d);
	void addnode(TNODE* node);
	void insertnode(int _id, int id, string name, int y, int m, int d);
	void insertnode(int _id, TNODE* node);
	int deletenode(int );
	TNODE*  searchnode(int);
	void display();
}; 

#endif