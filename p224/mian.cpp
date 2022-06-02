#include <iostream>
using namespace std;

class Circle {
private:
	int radius;
public:
	Circle();
	Circle(int radius);
	~Circle();

	double getArea(){ return 3.14*radius*radius; }
	int getRadius(){ return radius; }
	void setRadius(int radius){ this->radius = radius; }
	
};

Circle::Circle() {
	radius = 1;
	cout << "积己磊 角青 radius :" << radius << endl;
}

Circle::Circle(int radius) {
	this->radius = radius;
	cout << "积己磊 角青 radius :" << radius << endl;
}

Circle::~Circle() {
	cout << "家戈磊 角青 radius :" << radius << endl;
}

void increase(Circle c) {
	int r = c.getRadius();
	c.setRadius(r + 1);
}


int main() {
	//int n = 2;
	//int& refn = n;
	//int i = 3;

	//cout << "n : " << n << '\t' << "refn : " << refn << endl;

	Circle waffle(30);
	increase(waffle);

	cout << waffle.getRadius() << endl;


	return 0;
}