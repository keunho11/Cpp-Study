#include <iostream>
#include <string>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0) {this->x = x; this->y = y;} // 생성자 선언

	void set(int x, int y) { this->x = x; this->y = y; }
	void showPoint() {
		cout << "(" << x << "," << y << ")" << endl;
	}
};

class ColorPoint : public Point {
private:
	string color;
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint();
};

void ColorPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

class GrayPoint : public Point {
private:
	string color;
	string color1;
public:
	void setColor(string color) {
		this->color = color;
	}
	void showColorPoint();
	void setColor1(string color1) {
		this->color1 = color1;
	}
	void showColorPoint1();
};

void GrayPoint::showColorPoint() {
	cout << color << ":";
	showPoint();
}

void GrayPoint::showColorPoint1() {
	cout << color1 << ":";
	showPoint();
}



void testShow(Point* p) { // 업캐스팅을 해서 넘김
	//p->showColorPoint();
	// 현재는 베이스 클래스만 참조하기 때문에, 파생클래스의 멤버 함수를 사용할 수 없다.

	ColorPoint* cp = (ColorPoint*)p;
	GrayPoint* gp = (GrayPoint*)p;
	cout << typeid(*cp).name() << endl;
	if (typeid(*cp).name() == class ColorPoint) {
		//베이스 클래스가 어떠한 파생 클래스로 부터 업캐스팅 되었는지 확인한다.
		
		cp->showColorPoint();
	}
	else if (typeid(*gp).name() == "class GrayPoint") {
		
		gp->showColorPoint();
	}

	
}
/*
void testShow(ColorPoint& p) {
	p.showColorPoint();
}

void testShow(GrayPoint& p) {
	p.showColorPoint();
}
*/
int main() {
	ColorPoint cp;
	GrayPoint gp;  

	cp.set(3, 4);
	cp.setColor("Red");

	gp.set(1, 2);
	gp.setColor1("Black");

	//testShow(cp); 
	//testShow(gp);
	// 어떨때는 gp를 어떨때는 cp를 출력하고 싶음...
	// 함수중복이 되나, 메모리 낭비..
	
	testShow(&cp);
	testShow(&gp);
	// 두 클래스는 다르지만, 같은 베이스 클래스를 상속

#if 0
	Point* p = new Point;
	ColorPoint* cp = new ColorPoint();
	
	cp = (ColorPoint*)p; // 다운캐스팅인데... 다른 공간 침범한다.
#endif

#if 0
	ColorPoint cp;
	ColorPoint* pDer = &cp;
	Point* pBase = pDer; 

	pDer->set(3, 4);
//	pBase->showColorPoint;

	pDer = (ColorPoint*)pBase; 
	// 업캐스팅된 포인터를 다시 다운캐스팅 해야함.  


	//Point p;
	//p.showPoint();

	ColorPoint cp;
	cp.showPoint(); // 파생 클래스를 생성하면 베이스 클래스의 생성자가 호출된다.

	cp.set(3, 4);
	cp.setColor("red");
	cp.showColorPoint();
#endif
	return 0;
}

