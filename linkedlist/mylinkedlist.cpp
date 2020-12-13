#include <iostream>
#include "mylinkedlist.h"

using namespace std;

mylinkedlist::mylinkedlist()
{
	head = NULL;
}
mylinkedlist::~mylinkedlist()
{
	TNODE* t = head;
	while (1)
	{
		t = head->next;
		delete head;
		if (t == NULL) break;
		head = t;
	}
}
void mylinkedlist::addnode(int id, string name, int y, int m, int d)
{
	TNODE* t = new TNODE;

	t->id = id;
	t->name = name;
	t->year = y;
	t->month = m;
	t->day = d;
	t->next = NULL;

	addnode(t);
}
void mylinkedlist::addnode(TNODE* node)
{
	if (head == NULL)
	{
		head = node;
		return;
	}

	TNODE* t = head;
	while (1)
	{
		if (t->next == NULL)
		{
			t->next = node;
			return;
		}
		t = t->next;
	}
}
void mylinkedlist::insertnode(int _id, int id, string name, int y, int m, int d)
{
	TNODE* t = new TNODE;

	t->id = id;
	t->name = name;
	t->year = y;
	t->month = m;
	t->day = d;
	t->next = NULL;

	insertnode(_id, t);
}
void mylinkedlist::insertnode(int _id, TNODE* node)
{
	TNODE* t = head;
	while (1)
	{
		if (t->id == _id)
		{
			node->next = t->next;
			t->next = node;

			return;
		}

		if (t->next == NULL) break;
		t = t->next;
	}
	addnode(node);
}
int mylinkedlist::deletenode(int id)
{
	TNODE* t = head->next;
	TNODE* tt = head;
	while (1)
	{
		
		if (t->id ==id)
		{
			t->next =tt->next;
			delete t;
		}

		//if (t->id == id) 
		//t->id=t->next;
	}

	
}
TNODE* mylinkedlist::searchnode(int id)
{
	TNODE* t = head;
	while (1)
	{
		if (t->id == id)
		{
			cout << t->id << "," << t->name << "," << t->year << "-" << t->month << "-" << t->day << endl;
		}
		else
			break;
	}
}
void mylinkedlist::display()
{
	TNODE* t = head;
	while (1)
	{
		cout << t->id << "," << t->name << "," << t->year << "-" << t->month << "-" << t->day << endl;

		if (t->next == NULL) break;
		t = t->next;
	}
}
