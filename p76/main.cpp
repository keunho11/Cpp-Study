#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	string singer;

	cout << song + "�� �θ� ������?";
	cout << "ù���� ��Ʈ�� " << elvis[0] << "�Դϴ�.";

	getline(cin, singer);
	if (singer == elvis)
		cout << "����";
	else
		cout << "Ʋ�Ƚ��ϴ�. " << "������" + elvis + "�Դϴ�.";
}