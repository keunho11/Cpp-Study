#include "PrivateAccessError.h"

void PrivateAccessError::setA(int a) {
	a = a; // a�� �Ű����� a�� �νĵȴ�. // �Ű� ���� �ٸ� �̸��� �ᵵ ��.
	this->a = a; //�ڱ��ڽ��� ����Ű�� ������
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