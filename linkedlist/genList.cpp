//Gen List
//Devise a function that produces a gen list from the input l = (a,(b,c))
/*
�ҽ��ڵ� �ǽ� ���
1. copy�Ͽ� copy ���� ���� ����� ���
2. 2���� gen list�� ==
3. depth ����� ���
4. reference count ����Ͽ� getnode, retnode ����, gen list ��ȯ �ڵ� ���� �׽�Ʈ
5. template version���� ����� ��
*/
#include <iostream>

using namespace std;
int GetData();

class GenList; // forward declaration

class GenListNode
{
	friend class GenList;
	friend int operator==(const GenList&, const GenList&);
	friend int equal(GenListNode*, GenListNode*);
private:
	GenListNode* link;
	bool tag; // 0 for data, 1 for dlink, 2 for ref
	union {
		int data;
		GenListNode* dlink;
		int ref;
	};
};

class GenList
{
	friend int operator==(const GenList&, const GenList&);
	friend int equal(GenListNode*, GenListNode*);
private:
	GenListNode* first;
	static 	GenListNode* av;
	GenListNode* Copy(GenListNode*);
	void Visit(GenListNode*);//driver
	int Depth(GenListNode*);
	GenListNode* MakeList(GenListNode*);
	void Delete(GenListNode*);
public:
	void Copy(const GenList&);
	void Visit(const GenList&);//workhorse
	~GenList();
	int Depth();
	void MakeList();
};

GenList::~GenList()
//Each head node has a reference count. We assume first != 0
{
	Delete(first);
	first = 0;
}
void GenList::Copy(const GenList& l)
{
	first = Copy(l.first);
}

void GenList::Visit(const GenList& l)//public function���� ����
{
	cout << "(";
	Visit(l.first);
	cout << ")";
}
/*

GenList::~GenList()
{
Delete(first);
first = 0;
}
*/


int operator==(const GenList& l, const GenList& m)
{
	return equal(l.first, m.first);
}

//Workhorse - ��ȯ�ÿ� ���� �߻���
void GenList::Delete(GenListNode* x)
{
	if (x->tag == 2) x->ref--;
	if (!x->ref)
	{
		GenListNode* y = x;
		while (y->link)
		{
			y = y->link;
			if (y->tag == 1) Delete(y->dlink);
		}
		y->link = av;
		av = x;

	}
}
int GenList::Depth()
{
	return Depth(first);
}

void GenList::MakeList()
{
	first = MakeList(first);
}

GenListNode* GenList::MakeList(GenListNode* s)
{
	GenListNode* p, * q, * r;
	bool tag_head = true;
	q = new GenListNode;
	r = q;
	while (int x = GetData())//if x == 0, no more entry
	{
		if (x == 1) //make down link
		{
			if (tag_head) {
				q->dlink = MakeList(q);
				q->tag = true;
				q->link = 0;
				tag_head = false;
				continue;
			}
			else
			{
				p = new GenListNode;
				q->link = p;
				p->tag = true;
				p->link = 0;
				q = p;
				q->dlink = MakeList(q);
			}
		}
		else {
			if (tag_head) {
				q->data = x; q->tag = false; q->link = 0;
				tag_head = false;
			}
			else {
				p = new GenListNode;
				p->data = x; p->tag = false; p->link = 0;
				q->link = p;
				q = p;
			}
		}
	}
	return r;
}

GenListNode* GenList::Copy(GenListNode* p) //private function
{
	GenListNode* q = 0;
	if (p) {
		q = new GenListNode;
		q->tag = p->tag;
		if (!p->tag) q->data = p->data;
		else q->dlink = Copy(p->dlink);
		q->link = Copy(p->link);
	}
	return q;
}

void GenList::Visit(GenListNode* p)
{
	if (p) {
		cout << p->tag << ":";
		if (!p->tag)
			cout << p->data << ",";
		else {
			cout << " (";
			Visit(p->dlink);
			cout << ") ";
		}
		Visit(p->link);
	}
}

int equal(GenListNode* s, GenListNode* t)
{
	int x;
	if ((!s) && (!t)) return 1;
	if (s && t && (s->tag == t->tag)) {
		if (!s->tag)
			if (s->data == t->data) x = 1; else x = 0;
		else x = equal(s->dlink, t->dlink);
		if (x) return  equal(s->link, t->link);
	}
	return 0;
}

int GenList::Depth(GenListNode* s)
{
	if (!s) return 0;
	GenListNode* p = s; int m = 0;
	while (p) {
		if (p->tag) {
			int n = Depth(p->dlink);
			if (m < n) m = n;
		}
		p = p->link;
	}
	return m + 1;
}


int GetData() {
	cout << endl << "0: exit, 1: dlink, >2 value= ";
	int n;
	cin >> n;
	return n;
}
GenListNode* GenList:: av = 0;
int main(void)
{
	GenList l;
	GenList m;
	char select;
	int max = 0, x = 0;
	cout << "Select command m: make, c: copy, d: depth, v: visit, q : quit =>";
	cin >> select;
	while (select != 'q')
	{
		switch (select)
		{
		case 'm':
			l.MakeList();
			break;
		case 'c':
			m.Copy(l);
			cout << "Copy Result" << endl;
			l.Visit(m);
			cout << endl;
			break;
		case 'd':
			cout << "depth: " << l.Depth();
			cout << endl;
		case 'v':
			cout << "tag : data (link)" << endl;
			l.Visit(l);
			cout << endl;
			break;
		case 'q':
			cout << "Quit" << endl;
			break;

		default:
			cout << "WRONG INPUT  " << endl;
			cout << "Re-Enter" << endl;
			break;
		}
		cout << "Select command m: make, c: copy, d: depth, v: visit, q : quit =>";
		cin >> select;
	}
	system("pause");
	return 0;
}