#pragma warning(disable:4996)
#ifndef _CIRCLE_H_
#define _CIRCLE_H_


#include <cstring>

class Circle {
	int radius;
	char name[12];
public:
	Circle() { radius = 1; }
	Circle(int r) { radius = r; }
	Circle(const Circle& c);

	void SetRadius(int r) { radius = r; }
	void setName(const char* np) {
		strcpy(name, np);
	}
	char* getName() {
		return name;
	}

	double getArea();
};

#endif 

