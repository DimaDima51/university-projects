#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	printf("��������� ������ ����� ������:\n");
	
	printf("int: %d ����\n", sizeof(int));
	printf("unsigned int: %d ����\n", sizeof(unsigned int));
	printf("signed int: %d ����\n", sizeof(signed int));
	printf("long: %d ����\n", sizeof(long));
    printf("long long: %d ����\n", sizeof(long long));
    printf("unsigned long: %d ����\n", sizeof(unsigned long));
    printf("unsigned long long: %d ����\n", sizeof(unsigned long long));
    printf("signed long: %d ����\n", sizeof(signed long));
    printf("signed long long: %d ����\n", sizeof(signed long long));
	
	printf("short: %d ����\n", sizeof(short));
	printf("signed short: %d ����\n", sizeof(signed short));
	printf("unsigned short: %d ����\n", sizeof(unsigned short));
	
	printf("char: %d ����\n", sizeof(char));
	printf("unsigned char: %d ����\n", sizeof(unsigned char));
    printf("signed char: %d ����\n", sizeof(signed char));
	
    printf("float: %d ����\n", sizeof(float));

    printf("double: %d ����\n", sizeof(double));
	printf("long double: %d ����\n", sizeof(long double));
}