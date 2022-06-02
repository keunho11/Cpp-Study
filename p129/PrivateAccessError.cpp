#include "PrivateAccessError.h"

void PrivateAccessError::setA(int a) {
	a = a; // a는 매개변수 a로 인식된다. // 매개 변수 다른 이름을 써도 됨.
	this->a = a; //자기자신을 가리키는 포인터
}

int PrivateAccessError::GetA() {
	return a;
}

PrivateAccessError::PrivateAccessError() {
	a = 1;
	b = 1;
}

PrivateAccessError::PrivateAccessError(int x) {
	a = x;
	b = x;
}

void PrivateAccessError::f() {
	a = 5;
	b = 5;
}

void PrivateAccessError::g() {
	a = 6;
	b = 6;
}