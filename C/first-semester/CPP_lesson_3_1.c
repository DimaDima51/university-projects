#include <stdio.h>
#include <locale.h>

int main() {
	setlocale(LC_ALL, "RUS");
	printf("Выделение памяти типов данных:\n");
	
	printf("int: %d байт\n", sizeof(int));
	printf("unsigned int: %d байт\n", sizeof(unsigned int));
	printf("signed int: %d байт\n", sizeof(signed int));
	printf("long: %d байт\n", sizeof(long));
    printf("long long: %d байт\n", sizeof(long long));
    printf("unsigned long: %d байт\n", sizeof(unsigned long));
    printf("unsigned long long: %d байт\n", sizeof(unsigned long long));
    printf("signed long: %d байт\n", sizeof(signed long));
    printf("signed long long: %d байт\n", sizeof(signed long long));
	
	printf("short: %d байт\n", sizeof(short));
	printf("signed short: %d байт\n", sizeof(signed short));
	printf("unsigned short: %d байт\n", sizeof(unsigned short));
	
	printf("char: %d байт\n", sizeof(char));
	printf("unsigned char: %d байт\n", sizeof(unsigned char));
    printf("signed char: %d байт\n", sizeof(signed char));
	
    printf("float: %d байт\n", sizeof(float));

    printf("double: %d байт\n", sizeof(double));
	printf("long double: %d байт\n", sizeof(long double));
}