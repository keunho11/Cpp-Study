#include <iostream>
using namespace std;

void swap(int& a, int& b) {
	int temp;

	temp = a;
	a = b;
	b = temp;
}



int main() {
	int m = 2, n = 5;
	swap(m, n);
	cout << m << '\t' << n << endl;

	return 0;
}