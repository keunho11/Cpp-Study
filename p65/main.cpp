#include <iostream>
using namespace std;

int main()
{
	cout << "주소를 입력하세요 : ";
	char address[100];
	cin.getline(address, 100, '*');

	cout << "주소는" << address;

#if 0
	cout << "이름을 입력하세요 : ";
	char name[11];
	cin >> name;

	cout << "이름은 " << name << "입니다.\n";
	cin >> name;
	cout << "이름은 " << name << "입니다.\n";

#endif

#if 0 // 조건부 컴파일 -> 참이면 컴파일
	double width;
	double height;
	double area;	
	cout << "너비와 높이를  입력하시오. >>";

	cin >> width >> height;


	area = width * height;
	cout << "면적은" << area << "\n";

#endif
}