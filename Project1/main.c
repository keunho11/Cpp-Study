#include <stdio.h>

char* my_strcat(char* pd, const char* ps);
char* my_strcpy(char* pd, const char* ps);

int main(int argc, char* argv[])
{
//	int num0 = 0;
//	char ch0 = 'a';
//	int num1 = 1;
//	int num2 = 2;
//	int* np = &num2 + 3;
//printf("test: %d\n", *(&num2 + 1)); //�ʱ�ȭ ���� ���� ������ �����ϸ� ������ ���� ����.
//printf("test: %d\n", *np);  //1�� ���´�. Secure Area�� ���� �� �� �� ������ ����...
	/***********************************************/ 
/*
	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d] pointer: %p\n", i, argv[i]);
		printf("argv[%d] : %s\n", i, argv[i]);
	}
*/// for ������ ���

	/*int i = 0;
	while (1) 
	{
		if (argv[i] != 0x0)
		{
			printf("argv[%d] : %s\n", i, argv[i]);
			i++;
		}
		else
			break;
	}*/ // while ������ ���
/**************************************************************/
	//char* fruit = "straw";
	//char fruit[80] = {0}; // ��� 0���� �ʱ�ȭ��.
	//char fruit[80] = {'s','t','r','a','w'}; // ������ 75byte��  null��ä����
/**************************************************************/

	char fruit[80] = "straw"; // ������ 75byte�� null�� ä����
	//my_strcat(fruit, "berry");
	my_strcpy(fruit, "strawberry");
	printf("����� ���ڿ� : %s\n", fruit);
	return 0;
}

char* my_strcat(char* pd, const char* ps)
{
	char* po = pd;
	//char static temp[10] = "hello";
	while (*pd != '\0')
	{
		pd++;
	}

	while (*ps != '\0')
	{
		*pd = *ps;
		pd++;
		ps++;
	}
	*pd = '\0';// ���� �ʱ�ȭ �Ҷ� 0���� �Ǿ� �־ ������ ���� �ʴ´�.

	return po;
	//return temp;
}

char* my_strcpy(char* pd, const char* ps)
{
	char* po = pd;

	while (*ps != '\0')
	{
		*pd = *ps;
		pd++; ps++;
	}
	*pd = '\0'; // 

	return po;

}
