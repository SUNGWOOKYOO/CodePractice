#include <iostream>
#include "Stack.h"
#include "Queue.h"
#define _CRTDBG_MAP_ALLOC #include <stdlib.h> #include <crtdbg.h>  

using namespace std;

int main() {

	Stack S;
	Queue Q;


	cout << "----- Stack test -----" << endl;
	S.push(10);
	S.push(20);
	S.push(30);

	S.pop();
	S.pop();
	S.pop();
	S.pop();
	cout << "----------------------" << endl << endl;

	cout << "----- Queue test -----" << endl;
	Q.push(15);
	Q.push(25);
	Q.push(35);

	Q.pop();
	Q.pop();
	Q.pop();
	Q.pop();
	cout << "----------------------" << endl;

	_CrtDumpMemoryLeaks();
	return 0;
}
