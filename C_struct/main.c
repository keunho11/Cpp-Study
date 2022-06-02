#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // exit() 정의됨

struct student {
	int number;
	char name[10];
	double score;
};
typedef struct student Student;

void read_st(Student* st, int count, FILE* rfp);
void SaveStudent(Student* st);
void PrintStudent(Student* st);
void InputStudent(Student* st);

int main(void)
{
	//Student st[2] = { {1, "ABC", 85.0 }, {2, "DEF", 12.1 } }; // 정적할당
	//InputStudent(st);
	//SaveStudent(st);

	Student* st;
	FILE* rfp;
	rfp = fopen("st.db", "r"); // st.db의 이름으로, 읽기전용 파일 만듬 or 파일 연다.
	if (!rfp) {
		fputs("st.db 파일을 열 수 없습니다.\n", stdout);    //문자열 상수는 웬만하면 매크로로 사용하는 것이 좋음..
		return 1; //main이 정상 종료이면 0, 나머지는 프로그래머가 결정하는 것. ex) 2이면, argument 갯수 부족..
	}

	/*파일 위치자로 사이즈 구하기*/
	fseek(rfp, 0, SEEK_END); // 첫번째 파일 위치자를 마지막 요소 다음으로 위치시킨다.
	//fseek(rfp, -1, SEEK_END); // 맨 마지막 요소
	int size = ftell(rfp); // 48이 리턴됨
	int count = size / sizeof(Student);
	printf("size: %d, count : %d \n", size, count);

	//calloc(count ,sizeof(Student)); // calloc은 매개변수가 2개, 0혹은 NULL 로 초기화 해줌.
	st = (Student*)malloc(count * sizeof(Student));

	fseek(rfp, 0, SEEK_SET);
	read_st(st, count , rfp);
	PrintStudent(st);
	free(st);
	
	

	

	
	

	
	return 0;
}

void read_st(Student* st, int count, FILE* rfp)
{
	fread(st, sizeof(Student), count, rfp);
}

void SaveStudent(Student* st)
{	
	FILE* wfp;
	wfp = fopen("st.db", "w");
	if (wfp == NULL) 
	// 널포인트가 반환되면, 오류임(read only 파일일 경우.)(sd카드가 빠진 경우.) 
	// 정상인 경우, st.db의 주소가 반환된다.
	{
		fputs("st.db 파일을 열 수 없습니다.\n", stdout); //printf 함수는 무겁고 시간이 오래걸림.
		//stdout : 모니터에 출력해라
		exit(1); // exit(1) : 프로세스를 종료
	}
	fwrite(st, sizeof(Student),2,wfp); //저장한다. -> 보통은 구조체 한개 단위로 저장함.
	// 저장할 내용, 저장할 크기, 저장할 갯수, 저장할 위치
}

void PrintStudent(Student *st)
{
	//int size = sizeof(*st) / sizeof(st[0]);
	for (int i = 0; i < 2; i++)
	{
		//printf("%d, %s, %.1lf\n", st[i].number, st[i].name, st[i].score);
		printf("%d, %s, %.1lf\n", (st+i)->number, (st + i)->name, (st + i)->score);
		//printf("%d, %s, %.1lf\n", (*st).number, (*st).name, (*st).score);
		//st++;
	}

}

void InputStudent(Student* st)
{
	strcpy(st[0].name, "abc");
	strcpy(st[1].name, "def");
}