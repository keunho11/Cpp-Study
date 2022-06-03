#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[]) {
	//const char* firstFile = "c:\\temp\\student.txt";  //-> argv[1]
	//const char* secondFile = "c:\\windows\\system.ini"; //-> argv[2]
 
	fstream fout(argv[1], ios::out | ios::trunc); // 쓰기 모드로 파일 열기
	if (!fout) { // 열기 실패 검사
		cout << argv[1] << " 열기 오류";
		return 0;
	}

	fstream fin(argv[2], ios::in | ios::binary); // 읽기 모드로 파일 열기
	// 바이너리 모드로 읽어야 '\r' '\n'을 각각 1byte로 읽는다.
	if (!fin) { // 열기 실패 검사
		cout << argv[2] << " 열기 오류";
		return 0;
	}

	int c;
	int count = 0;
	while ((c = fin.get()) != EOF) { // 파일 끝까지 문자 읽기
		fout.put(c); // 읽은 문자 기록
		count++;
	}
	cout << "file size : " << count << endl;

	fin.close(); // 입력 파일 닫기
	fout.close(); // 출력 파일 닫기
}