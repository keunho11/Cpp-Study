#include <iostream>
using namespace std;

class Calculator {
	void input() {
		cout << "���� 2���� �Է��ϼ��� >>";
		cin >> a >> b;
	}
protected:
	int a, b;
	virtual int calc(int a, int b) = 0;
public:
	void run() {
		input();
		cout << "���� ����" << clac(a, b) << endl;
	}
};

class Adder : public Calculator {

	virtual int clac(int a, int b) {
		return a + b;
	}
};

class Subtractor : public Calculator {

	virtual int clac(int a, int b) {
		return a - b;
	}
};


int main() {
	Adder adder;
	Subtractor subtractor;

	adder.run();
	substractor.run();

	return 0;
}