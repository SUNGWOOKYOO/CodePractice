#include <iostream>
#include "Node.h"

using namespace std;

class Stack
{
private:
	Node * head;
	Node* tail;
public:
	Stack();
	~Stack();
	void push(int value);
	Node top();
	void pop();
};

Stack::Stack()
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
}

Stack::~Stack()
{	
	Node* current = head;
	while (current != 0) {
		Node* next = current->next;
		delete current;
		current = next;
	}
	head = 0;
}

void Stack::push(int value)
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

Node Stack::top()
{
	if (head->next == tail)
	{
		cout << "Stack is empty" << endl;
	}
	return *head->next;
}

void Stack::pop()
{
	if (head->next == tail) {
		cout << top().val << endl;
	}
	else {
		Node *d = head->next;
		d->next->prev = head;
		head->next = d->next;
		cout << d->val <<" deleted" << endl;
		delete d;
	}
}