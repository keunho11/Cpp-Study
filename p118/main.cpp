#include <iostream>
using namespace std;

class Rectangle {
	int width, height;
public:
	Rectangle();
	Rectangle(int w, int h);
	Rectangle(int length);
	bool IsSquare();
};

Rectangle::Rectangle() : Rectangle(1){}

Rectangle::Rectangle(int w, int h) {
	width = w; height = h;
}

//Rectangle::Rectangle(int length) {
//	width = height = length;
//}

Rectangle::Rectangle(int length) : Rectangle(length, length) {}

bool Rectangle::IsSquare() {
	if (width == height) return true;
	else return false;
}

int main(void){
	Rectangle rect1;
	Rectangle rect2(3, 5);
	Rectangle rect3(6);

	if (rect1.IsSquare()) cout << "rect1�� ���簢��" << endl;
	if (rect2.IsSquare()) cout << "rect2�� ���簢��" << endl;
	if (rect3.IsSquare()) cout << "rect3�� ���簢��" << endl;
	return 0;
}