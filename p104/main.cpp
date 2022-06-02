#include <iostream>
using namespace std;


#if 0
class Rectangular {
private:
	double width;
	double height;
public:
	Rectangular();
	Rectangular(double wi, double he);
	void SetRectangular(double w, double h);
	double getArea();
};

void Rectangular::SetRectangular(double w, double h) {
	width = w;
	height = h;
}

double Rectangular::getArea() {
	return width * height;
}

Rectangular::Rectangular() {
	cout << "hi" << endl;
}

Rectangular::Rectangular(double wi, double he) {
	width = wi;
	height = he;
}

int main(void)
{
	//Rectangular rect(10.1, 13.4);
	Rectangular rect;
	rect.SetRectangular(10, 13);
	double area = rect.getArea();
	cout << area << endl;
	return 0;
}
#endif


class Circle {
private:
	int radius;
public:
	void SetRadius(int rad);
	double getArea();
	Circle();
	Circle(int r);
};

void Circle::SetRadius(int rad) {
	radius = rad;
	// int radius 하면 지역변수
}

double Circle::getArea(){
	return  3.14 * radius * radius;
}

//Circle::Circle() {
//	radius = 1;
//	cout << "반지름" << radius << "원 생성" << endl;
//}


Circle::Circle() : Circle(1) {}
Circle::Circle(int r) {
	radius = r;
	cout << "반지름" << radius << "원 생성" << endl;
}


void PrintCircle(Circle* p);

int main()
{
	/*
	Circle donut;
	cout << sizeof(donut) << endl;

	donut.SetRadius(1); //public이기 때문에 main에서 접근 가능..
	// 포인터면 -> 로 접근
	double area = donut.getArea();
	cout << "도넛의 면적은" << area << endl;

	Circle pizza;
	pizza.SetRadius(30);
	area = pizza.getArea();
	cout << "도넛의 면적은" << area << endl;
	*/

	Circle donut;
	PrintCircle(&donut);
	//double area = donut.getArea();
	

	Circle pizza(30);
	double area = pizza.getArea();
	cout << "도넛의 면적은" << area << endl;
	return 0;
}

void PrintCircle(Circle* p) // call by pointer
{
	double area = p->getArea();
	cout << "도넛의 면적은(PrintCircle)" << area << endl;
}
