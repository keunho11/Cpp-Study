#include <iostream>
using namespace std;

int main(int argc, char* argv[])
{
	/*
	int a = 8;
	double b = 1.14;
	a = a << 1;
	
	std::cout << "Hello"<< std::endl; //<< std::endl -> new line // = '\n'
	std::cout << 5 << std::endl;
	std::cout << 3.14 << std::endl;
	std::cout << a << std::endl;
	*/
	/*
	for (int i = 1; i < 10; i++){
		for(int j =1; j < 10; j++)
			std::cout << j << 'x' << i << '=' << i*j << '\t';
		std::cout << std::endl;
	}
	*/
	int num = 30;

	//std::cout << 25.0 / num * 100 << std::endl;
	cout << 25 / (double)num * 100 << std::endl;
	return 0;
}