#include <iostream>
#include "Node.h"

using namespace std;

class Queue
{
private:
	Node * head;
	Node* tail;
public:
	Queue(void);
	~Queue(void);
	void push(int value);
	Node top();
	void pop();
};

Queue::Queue(void)
{
	Node* newHead = new Node;
	Node* newTail = new Node;
	newHead->val = -1;
	newTail->val = -1;
	newHead->next = NULL;
	newTail->next = NULL;

	head = newHead;
	tail = newTail;
	head->next = tail;
	tail->prev = head;
}


Queue::~Queue(void)
{
	Node* current = head;
	while (current != 0) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = 0;
}

void Queue::push(int value)
{
	Node *temp = new Node;
	temp->val = value;
	if (head->next == tail) {
		head->next = temp;
		temp->prev = head;
		temp->next = tail;
		tail->prev = temp;
	}
	else {
		Node *nn = head->next;
		head->next = temp;
		temp->prev = head;
		temp->next = nn;
		nn->prev = temp;
	}
}

Node Queue::top()
{
	if (tail->prev == head)
	{
		cout << "Queue is empty" << endl;
	}
	return *tail->prev;
}

void Queue::pop()
{
	if (head->next == tail) {
		cout << top().val << endl;
	}
	else {
		Node *d = tail->prev;
		d->prev->next = tail;
		tail->prev = d->prev;
		cout << d->val <<" deleted" << endl;
		delete d;
	}
}
