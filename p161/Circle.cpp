#include "Circle.h"

double Circle::getArea() {
	return 3.14 * radius * radius;
}

Circle::Circle(const Circle& c) {
	this->radius = c.radius;
	strcpy(this->name, c.name);
} 
// 이 코드를 자동으로 생김 -> 디폴트 복사 생성자..
// 멤버변수 갯수 만큼 복사가 된다.
