#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h> // exit() ���ǵ�

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
	//Student st[2] = { {1, "ABC", 85.0 }, {2, "DEF", 12.1 } }; // �����Ҵ�
	//InputStudent(st);
	//SaveStudent(st);

	Student* st;
	FILE* rfp;
	rfp = fopen("st.db", "r"); // st.db�� �̸�����, �б����� ���� ���� or ���� ����.
	if (!rfp) {
		fputs("st.db ������ �� �� �����ϴ�.\n", stdout);    //���ڿ� ����� �����ϸ� ��ũ�η� ����ϴ� ���� ����..
		return 1; //main�� ���� �����̸� 0, �������� ���α׷��Ӱ� �����ϴ� ��. ex) 2�̸�, argument ���� ����..
	}

	/*���� ��ġ�ڷ� ������ ���ϱ�*/
	fseek(rfp, 0, SEEK_END); // ù��° ���� ��ġ�ڸ� ������ ��� �������� ��ġ��Ų��.
	//fseek(rfp, -1, SEEK_END); // �� ������ ���
	int size = ftell(rfp); // 48�� ���ϵ�
	int count = size / sizeof(Student);
	printf("size: %d, count : %d \n", size, count);

	//calloc(count ,sizeof(Student)); // calloc�� �Ű������� 2��, 0Ȥ�� NULL �� �ʱ�ȭ ����.
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
	// ������Ʈ�� ��ȯ�Ǹ�, ������(read only ������ ���.)(sdī�尡 ���� ���.) 
	// ������ ���, st.db�� �ּҰ� ��ȯ�ȴ�.
	{
		fputs("st.db ������ �� �� �����ϴ�.\n", stdout); //printf �Լ��� ���̰� �ð��� �����ɸ�.
		//stdout : ����Ϳ� ����ض�
		exit(1); // exit(1) : ���μ����� ����
	}
	fwrite(st, sizeof(Student),2,wfp); //�����Ѵ�. -> ������ ����ü �Ѱ� ������ ������.
	// ������ ����, ������ ũ��, ������ ����, ������ ��ġ
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