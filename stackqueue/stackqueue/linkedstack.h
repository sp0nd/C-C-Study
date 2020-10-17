#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#pragma warning(disable:4290)
#include "RuntimeException.h"

//////////////////////////////////////////////////////////////////////////////////////////
template <typename E> class SLinkedList;

template <typename E>
class SNode {						// ���� ��ũ�� ����Ʈ ���
private:
	E elem;							// ��ũ�� ����Ʈ ���� ��
	SNode<E>* next;					// ����Ʈ�� ���� �׸�
	friend class SLinkedList<E>;	// SLinkedList���� ������ ����
};

template <typename E>
class SLinkedList {					// ���� ��ũ�� ����Ʈ
public:
	SLinkedList();					// �� ����Ʈ ������
	~SLinkedList();					// �Ҹ���
	bool empty() const;				// ����Ʈ�� �����?
	const E& front() const;			// ���� ���� ��ȯ
	void addFront(const E& e);		// ����Ʈ�� �տ��� �߰�
	void removeFront();				// ����Ʈ�� �տ��� ����
private:
	SNode<E>* head;					// ����Ʈ�� head
};

template <typename E> SLinkedList<E>::SLinkedList()
	: head(NULL) {}						// ������
template <typename E> bool SLinkedList<E>::empty() const
{	return head == NULL;	}			// ����Ʈ�� �����?
template <typename E> const E& SLinkedList<E>::front() const
{	return head->elem;		}			// ���� ���� ��ȯ
template <typename E> SLinkedList<E>::~SLinkedList()
{	while (!empty()) removeFront();	}	// �Ҹ���
template <typename E> void SLinkedList<E>::addFront(const E& e)
{										// ����Ʈ �տ� �߰�
	SNode<E>* v = new SNode<E>;			// ���ο� ��� �����
	v->elem = e;						// ������ ����
	v->next = head;						// ���� head�� v�� ������.
	head = v;							// v�� ���� ���ο� head�� �ȴ�.
}
template <typename E> void SLinkedList<E>::removeFront()
{										// ���� ��Ʈ�� ����
	SNode<E>* old = head;				// ���� head ����
	head = old->next;					// ���� head�� �ǳʶڴ�.
	delete old;							// ���� head ����
}

//////////////////////////////////////////////////////////////////////////////////////////
typedef string Elem;						// ���� ���� Ÿ��
class LinkedStack
{
public:
	LinkedStack() :S(), n(0) {}
	int size() const { return n; }
	bool empty() const { return n == 0; }
	const Elem& top() const throw(StackEmpty)
	{
		if (empty()) throw StackEmpty("top of empty stack");
		return S.front();
	}
	void push(const Elem& e)
	{
		n++;
		S.addFront(e);
	}
	void pop() throw(StackEmpty)
	{
		if (empty()) throw StackEmpty("Pop from empty stack");
		n--;
		S.removeFront();

	}
private:
	SLinkedList<Elem> S;
	int n;
};
#endif