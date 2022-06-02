#include <iostream>
#include <string>
#include "Circle.h"

using namespace std;

void PrintCircle(Circle* p);

int main(void) {
	Circle src(30);
	src.setName("홍길동");
	cout << "원본의 면적 = " << src.getArea() << endl;
	cout << "name : " << src.getName() << endl;
	
	Circle dest(src);

	cout << "사본의 면적 = " << dest.getArea() << endl;
	cout << "name : " << dest.getName() << endl;

#if 0
	string str = "0123456789012345";
	cout << str.size() << endl;
	cout << str.capacity() << endl;
	cout << str.find("5") << endl; // 시작하는 인덱스를 반환 -> 4를 반환

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
		cout << "Circle " << i << "의 면적은" << circleArray[i].getArea() << endl;
	}

	PrintCircle(circleArray);
#endif
	return 0;
}

void PrintCircle(Circle* p) {
	for (int i = 0; i < 3; i++) {
		cout << "Circle " << i << "의 면적은" << p->getArea() << endl;
		p++;
	}
}

