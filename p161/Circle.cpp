#include "Circle.h"

double Circle::getArea() {
	return 3.14 * radius * radius;
}

Circle::Circle(const Circle& c) {
	this->radius = c.radius;
	strcpy(this->name, c.name);
} 
// �� �ڵ带 �ڵ����� ���� -> ����Ʈ ���� ������..
// ������� ���� ��ŭ ���簡 �ȴ�.
