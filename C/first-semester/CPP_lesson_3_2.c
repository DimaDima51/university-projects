#include <stdio.h>
#include <locale.h>
#include <limits.h>
#include <float.h>

int main() {
	setlocale(LC_ALL, "RUS");
	
	printf("„иапазон значений типов данных:\n");
	
	printf("int: %d до %d\n", INT_MIN, INT_MAX);
	printf("unsigned int: %u до %u\n", UINT_MAX-UINT_MAX, UINT_MAX);
	printf("long: %ld до %ld\n", LONG_MIN, LONG_MAX);
	printf("long long: %lld до %lld\n", LLONG_MIN, LLONG_MAX);
	printf("unsigned long: %lu до %lu\n", ULONG_MAX-ULONG_MAX, ULONG_MAX);
	printf("unsigned long long: %lu до %lu\n", ULLONG_MAX-ULLONG_MAX, ULLONG_MAX);
	
	printf("short: %hd до %hd\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short: %hu до %hu\n", USHRT_MAX-USHRT_MAX, USHRT_MAX);
	
	printf("char: %d до %d\n", CHAR_MIN, CHAR_MAX);
	printf("unsigned char: %d до %d\n", UCHAR_MAX-UCHAR_MAX, UCHAR_MAX);
	printf("signed char: %d до %d\n", SCHAR_MIN, SCHAR_MAX);
	
	printf("float: %f до %f\n", FLT_MIN, FLT_MAX);
	
    printf("double: %f до %f\n", DBL_MIN, DBL_MAX);
	printf("long double: %Le до %Le\n", LDBL_MIN, LDBL_MAX);
	
	printf("Џоведение при выходе за диапазон:\n");
	
	printf("int: %d %d\n", INT_MIN - 1, INT_MAX + 1);
	printf("unsigned int: %u %u\n", UINT_MAX-UINT_MAX - 1, UINT_MAX + 1);
	printf("long: %ld %ld\n", LONG_MIN - 1, LONG_MAX + 1);
	printf("long long: %lld %lld\n", LLONG_MIN - 1, LLONG_MAX + 1);
	printf("unsigned long: %lu %lu\n", ULONG_MAX-ULONG_MAX - 1, ULONG_MAX + 1);
	printf("unsigned long long: %lu %lu\n", ULLONG_MAX-ULLONG_MAX - 1, ULLONG_MAX + 1);
	
	printf("short: %hd %hd\n", SHRT_MIN - 1, SHRT_MAX + 1);
	printf("unsigned short: %hu %hu\n", USHRT_MAX-USHRT_MAX - 1, USHRT_MAX + 1);
	
	char cMAX = CHAR_MAX + 1;
	char cMIN = CHAR_MIN - 1;
	printf("char: %d %d\n", cMIN, cMAX);
	unsigned char ucMAX = UCHAR_MAX + 1;
	unsigned char ucMIX = UCHAR_MAX-UCHAR_MAX - 1;
	printf("unsigned char: %u %u\n", ucMIX, ucMAX);
	signed char scMAX = SCHAR_MAX + 1;
	signed char scMIN = SCHAR_MIN - 1;
	printf("signed char: %d %d\n", scMIN, scMAX);
	
	float fMAX = FLT_MAX + 1.0f;
	float fMIN = FLT_MIN - 1.0f;
	printf("float: %f %f\n", fMIN, fMAX);
	
	double dfMAX = DBL_MAX + 1.0f;
	double dfMIN = DBL_MIN - 1.0f;
    printf("double: %f %f\n", dfMIN, dfMAX);
	long double ldMAX = LDBL_MAX + 1.0f;
	long double ldMIN = LDBL_MIN - 1.0f;
	printf("long double: %Lf %Lf\n", ldMIN, ldMAX);	
}