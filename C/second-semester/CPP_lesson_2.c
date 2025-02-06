#include <stdio.h> 
#include <math.h> 
#include <locale.h> 
 
int sumDigitsIterative(int num) { 
    int sum = 0; 
    int first = 1; 
 
    while(num != 0) { 
        int digit = abs(num % 10); 
        sum += digit; 
   
        if (!first) printf(" + "); 
        else first = 0; 
         
        printf("%d", digit); 
        num = num / 10; 
    } 
    return sum; 
} 
 
int sumDigitsRecursive(int num) { 
    if (num == 0) { 
        return 0; 
    } else { 
        int digit = abs(num % 10); 
        printf("%d", digit); 
   
        if (num / 10 != 0) printf(" + "); 
   
        return digit + sumDigitsRecursive(num / 10); 
    } 
} 
 
int main() { 
 setlocale(LC_ALL, "RUS"); 
    int num; 
     
    printf("Введите целое число: "); 
    scanf("%d", &num); 
     
    num = abs(num); 
 	printf("\nИтеративное сложение: ");
    printf("\nСумма цифр (итеративная): %d\n", sumDigitsIterative(num)); 
    printf("\nРекурсивное сложение: "); 
    printf("\nСумма цифр (рекурсивная): %d\n", sumDigitsRecursive(num)); 
 
    return 0; 
}