#include <iostream>
using namespace std;

int main()
{
	cout << "�ּҸ� �Է��ϼ��� : ";
	char address[100];
	cin.getline(address, 100, '*');

	cout << "�ּҴ�" << address;

#if 0
	cout << "�̸��� �Է��ϼ��� : ";
	char name[11];
	cin >> name;

	cout << "�̸��� " << name << "�Դϴ�.\n";
	cin >> name;
	cout << "�̸��� " << name << "�Դϴ�.\n";

#endif

#if 0 // ���Ǻ� ������ -> ���̸� ������
	double width;
	double height;
	double area;	
	cout << "�ʺ�� ���̸�  �Է��Ͻÿ�. >>";

	cin >> width >> height;


	area = width * height;
	cout << "������" << area << "\n";

#endif
}