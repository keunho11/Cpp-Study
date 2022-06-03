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
//printf("test: %d\n", *(&num2 + 1)); //초기화 되지 않은 공간을 접근하면 컴파일 에러 난다.
//printf("test: %d\n", *np);  //1이 나온다. Secure Area를 지난 후 그 전 변수에 접근...
	/***********************************************/ 
/*
	for (int i = 0; i < argc; i++)
	{
		printf("argv[%d] pointer: %p\n", i, argv[i]);
		printf("argv[%d] : %s\n", i, argv[i]);
	}
*/// for 문으로 출력

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
	}*/ // while 문으로 출력
/**************************************************************/
	//char* fruit = "straw";
	//char fruit[80] = {0}; // 모두 0으로 초기화됨.
	//char fruit[80] = {'s','t','r','a','w'}; // 나머지 75byte는  null로채워짐
/**************************************************************/

	char fruit[80] = "straw"; // 나머지 75byte는 null로 채워짐
	//my_strcat(fruit, "berry");
	my_strcpy(fruit, "strawberry");
	printf("연결된 문자열 : %s\n", fruit);
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
	*pd = '\0';// 빼도 초기화 할때 0으로 되어 있어서 문제는 되지 않는다.

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
