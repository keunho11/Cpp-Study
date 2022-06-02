#include <iostream>
#include <string>
using namespace std;

int main(int argc, char* argv[])
{
	string song("Falling in love with you");
	string elvis("Elvis Presley");
	string singer;

	cout << song + "를 부른 가수는?";
	cout << "첫글자 힌트는 " << elvis[0] << "입니다.";

	getline(cin, singer);
	if (singer == elvis)
		cout << "정답";
	else
		cout << "틀렸습니다. " << "정답은" + elvis + "입니다.";
}