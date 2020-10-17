#ifndef LINKEDQUEUE_H
#define LINKEDQUEUE_H
#pragma warning(disable:4290)
#include "RuntimeException.h"

/////////////////////////////////////////////////////////////////////////////////////

typedef string Elem;			// ���� Ÿ��
class CNode						// ȯ�� ���� ����Ʈ ���
{
private:
	Elem elem;					// ���� ����Ʈ ���� ��
	CNode* next;				// ����Ʈ�� ���� ��Ʈ��
	friend class CircleList;	// CircleList���� ���� ���
};

class CircleList				// ȯ�� ���� ����Ʈ
{
public:
	CircleList();				// ������
	~CircleList();				// �Ҹ���
	bool empty() const;			// �����?
	const Elem& front() const;	// Ŀ�� ������ ����
	const Elem& back() const;	// Ŀ���� ����
	void advance();				// Ŀ���� �������� �̵�
	void add(const Elem& e);	// Ŀ�� �ڿ� �߰�
	void remove();				// Ŀ���� ���� ��� ����
private:
	CNode* cursor;				// Ŀ��
};

CircleList::CircleList() :cursor(NULL) {}
CircleList::~CircleList() { while (!empty()) remove(); }
bool CircleList::empty() const { return cursor == NULL; }
const Elem& CircleList::back() const { return cursor->elem; }
const Elem& CircleList::front() const { return cursor->next->elem; }
void CircleList::advance() { cursor = cursor->next; }
void CircleList::add(const Elem& e)
{
	CNode* v = new CNode;
	v->elem = e;
	if (cursor == NULL)
	{
		v->next = v;
		cursor = v;
	}
	else
	{
		v->next = cursor->next;
		cursor->next = v;
	}
}
void CircleList::remove()
{
	CNode* old = cursor->next;
	if (old == cursor)
		cursor = NULL;
	else
		cursor->next = old->next;
	delete old;
}
/////////////////////////////////////////////////////////////////////////////////////

class LinkedQueue
{
public:
	LinkedQueue() :C(), n(0) {}
	int size() const { return n; }
	bool empty() const { return n == 0; }
	const Elem& front() const throw(QueueEmpty) {
		if (empty()) throw QueueEmpty("front of empty queue");
			return C.front();
	}
	void enqueue(Elem e) {
		C.add(e);
		C.advance();
		n++;
	}
	void dequeue() throw(QueueEmpty) {
		if (empty()) throw QueueEmpty("dequeue from empty queue");
			C.remove();
		n--;
	}
private:
	CircleList C;
	int n;
};

#endif