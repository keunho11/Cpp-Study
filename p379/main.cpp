#include <iostream>
#include <string>
using namespace std;

class Point {
private:
	int x, y;
public:
	Point(int x = 0, int y = 0) {this->x = x; this->y = y;} // ������ ����

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



void testShow(Point* p) { // ��ĳ������ �ؼ� �ѱ�
	//p->showColorPoint();
	// ����� ���̽� Ŭ������ �����ϱ� ������, �Ļ�Ŭ������ ��� �Լ��� ����� �� ����.

	ColorPoint* cp = (ColorPoint*)p;
	GrayPoint* gp = (GrayPoint*)p;
	cout << typeid(*cp).name() << endl;
	if (typeid(*cp).name() == class ColorPoint) {
		//���̽� Ŭ������ ��� �Ļ� Ŭ������ ���� ��ĳ���� �Ǿ����� Ȯ���Ѵ�.
		
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
	// ����� gp�� ����� cp�� ����ϰ� ����...
	// �Լ��ߺ��� �ǳ�, �޸� ����..
	
	testShow(&cp);
	testShow(&gp);
	// �� Ŭ������ �ٸ�����, ���� ���̽� Ŭ������ ���

#if 0
	Point* p = new Point;
	ColorPoint* cp = new ColorPoint();
	
	cp = (ColorPoint*)p; // �ٿ�ĳ�����ε�... �ٸ� ���� ħ���Ѵ�.
#endif

#if 0
	ColorPoint cp;
	ColorPoint* pDer = &cp;
	Point* pBase = pDer; 

	pDer->set(3, 4);
//	pBase->showColorPoint;

	pDer = (ColorPoint*)pBase; 
	// ��ĳ���õ� �����͸� �ٽ� �ٿ�ĳ���� �ؾ���.  


	//Point p;
	//p.showPoint();

	ColorPoint cp;
	cp.showPoint(); // �Ļ� Ŭ������ �����ϸ� ���̽� Ŭ������ �����ڰ� ȣ��ȴ�.

	cp.set(3, 4);
	cp.setColor("red");
	cp.showColorPoint();
#endif
	return 0;
}

