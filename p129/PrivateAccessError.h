#ifndef _PrivateAccessError_H_  
#define _PrivateAccessError_H_

class PrivateAccessError {
private:
	int a;

	//void f();
	//privateAccessError();
public:

	int b;
	void setA(int a);
	int GetA();

	PrivateAccessError();
	PrivateAccessError(int x);

	void f();
	void g();
};

#endif