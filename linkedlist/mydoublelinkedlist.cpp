#include<iostream>
#include "MyDoubleLinkedList.h"

using namespace std;

MyDoubleLinkedList::MyDoubleLinkedList()
{
	DNODE* head = NULL;
}

MyDoubleLinkedList::~MyDoubleLinkedList()
{
	
	while (1)
	{
		DNODE* t = head->next;
	
		delete head;
		if (t == NULL)break;
		head = t;

	}
}
//void MyDoubleLinkedList::GNode(int id,string name ,int y, int m, int d)
//{
//	DNODE* t = new DNODE;
//	t->id = id;
//	t->name = name;
//	t->year = y;
//	t->month = m;
//	t->day = d;
//	t->prev = NULL;
//	t->next = NULL;
//
//	GNode(t);
//}
//void MyDoubleLinkedList::GNode(DNODE* node)
//{
//	if (head == NULL)
//	{
//		head = node;
//		return;
//	}
//	DNODE* t = head;
//	while (1)
//	{
//		if (t->next == NULL)
//		{
//			t->next = node;
//			return;
//		}
//		t = t->next;
//	}
//
//}
void MyDoubleLinkedList::Front(int _id, string name, int y, int m, int d)
{
	DNODE* t = new DNODE;

	t->id = _id;
	t->name = name;
	t->year = y;
	t->month = m;
	t->day = d;
	t->prev = NULL;
	t->next = NULL;
	addNodeFront(t);
}
void MyDoubleLinkedList::addNodeFront(DNODE* node)
{
	if (head == NULL)
	{
		head = node;
		return;
	}
	

	head->prev = node;
	node->next = head;
	head = node;
	
	
	
}
void MyDoubleLinkedList::Back(int _id, string name, int y, int m, int d)
{
	DNODE* t = new DNODE;

	t->id = _id;
	t->name = name;
	t->year = y;
	t->month = m;
	t->day = d;
	t->prev = NULL;
	t->next = NULL;

	addNodeBack(t);
}

void MyDoubleLinkedList::addNodeBack(DNODE* node)
{
	if (head == NULL)
	{
		head = node;
		return;
	}

	DNODE* t = head;
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
void  MyDoubleLinkedList:: insertNode(int id,int _id, string name, int y, int m, int d)
{
	DNODE* t = new DNODE;

	t->id = id;
	t->name = name;
	t->year = y;
	t->month = m;
	t->day = d;
	t->prev = NULL;
	t->next = NULL;

	insertNode(_id,t);
}

void MyDoubleLinkedList::insertNode(int _id,DNODE* node)
{
	DNODE* t = head;
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
	addNodeBack(node);
}
//void MyDoubleLinkedList::deleteNode(DNODE* _node)
//{
//
//}
//void MyDoubleLinkedList::searchNode(string name, int y, int m, int d)
//{
//
//}
//
//void MyDoubleLinkedList::displayFoward()
//{
//
//}
//void MyDoubleLinkedList::displayBackward()
//{
//
//}
void MyDoubleLinkedList::display()
{
	DNODE* t = head;
	while (1)
	{
		cout << t->id << "," << t->name << "," << t->year << "-" << t->month << "-" << t->day << endl;

		if (t->next == NULL) break;
		t = t->next;
	}
}