#include <iostream>
using namespace std;

class Base {
public:
	virtual void  f();
};

void Base::f() {
	cout << "Base::f() called" << endl;
}

class Derived : public Base {
public:
	virtual void f();
};

void Derived::f() {
	cout << "Derived::f() called" << endl;
}

int main(){
	Derived d, * pDer;
	pDer = &d;
	pDer->f();

	Base* pBase;
	pBase = pDer;
	pBase->f();


	return 0;
}