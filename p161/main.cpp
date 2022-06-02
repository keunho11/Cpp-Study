#include <iostream>
#include <string>
#include "Circle.h"

using namespace std;

void PrintCircle(Circle* p);

int main(void) {
	Circle src(30);
	src.setName("ȫ�浿");
	cout << "������ ���� = " << src.getArea() << endl;
	cout << "name : " << src.getName() << endl;
	
	Circle dest(src);

	cout << "�纻�� ���� = " << dest.getArea() << endl;
	cout << "name : " << dest.getName() << endl;

#if 0
	string str = "0123456789012345";
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	cout << str.find("5") << endl; // �����ϴ� �ε����� ��ȯ -> 4�� ��ȯ

	Circle* p, * q;
	p = new Circle;
	q = new Circle(30);
	cout << p->getArea() << endl << q->getArea() << endl;

	delete p, q;


//	Circle circleArray[3] = {Circle(10), Circle(20) ,Circle(30) };
	
	Circle circleArray[3];
	circleArray[0].SetRadius(10);
	circleArray[1].SetRadius(20);
	circleArray[2].SetRadius(30);

	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i << "�� ������" << circleArray[i].getArea() << endl;
	}

	PrintCircle(circleArray);
#endif
	return 0;
}

void PrintCircle(Circle* p) {
	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i << "�� ������" << p->getArea() << endl;
		p++;
	}
}

