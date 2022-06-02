#include <iostream>
#include "PrivateAccessError.h"
using namespace std;

int main(void) {
	PrivateAccessError objA;
	PrivateAccessError objB(100);

	//objB.a = 10;
	objB.setA(10);
	cout << "getA() :" << objB.GetA()<< endl;
	objB.b = 20;
	objB.f();
	objB.g();
	return 0;
}



