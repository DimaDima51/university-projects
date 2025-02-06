#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int a, b, c;
	float discriminant, root1, root2;
	char term;
	printf("Введите коэффициенты a b c: ");
	if ((scanf("%d %d %d%c", &a, &b, &c, &term) != 4) || (term != '\n'))
		printf("Ошибка ввода!");
	else 
	{
	discriminant = (float)b * (float)b - 4 * (float)a * (float)c;
	if(a == 0 && b == 0 && c == 0) printf("a = 0, b = 0, c = 0\nУравнение отсутствует!");
	else if(a == 0 && b == 0 && c != 0) printf("a = 0, b = 0, c != 0\nУравнение не имеет решения!");
	else if(a == 0 && b != 0 && c == 0) printf("a = 0, b != 0, c = 0\nx = 0");
	else if(a == 0 && b != 0 && c != 0){
		printf("%d %d %d", a, b, c);
		printf("a = 0, b != 0, c != 0\nУравнение является линейным: bx + c = 0\n");
		root1 = -((float)c/(float)b);
		printf("Уравнение имеет один корень: %.2f", root1);
	}
	else if(a != 0 && b == 0 && c == 0) printf("a != 0, b = 0, c = 0\nx = 0\nКратность равна 2");
	else if(a != 0 && b == 0 && c != 0) {		
		printf("a != 0, b = 0, c != 0\n");
		if (c < 0){
			root1 = sqrt(((float)-c)/(float)a);
			root2 = -sqrt(((float)-c)/(float)a);
			printf("Уравнение имеет два корня: %.2f %.2f", root1, root2);
		} else printf("Уравнение не имеет действительные корни!");
	}
		else if(a != 0 && b != 0 && c == 0) {
		printf("a != 0, b != 0, c = 0\n");
		root1 = 0;
		root2 = -((float)b/(float)a);
		printf("Уравнение имеет два корня: %.2f и %.2f\n", root1, root2);
	}
	else {
		printf("a != 0, b != 0, c != 0\n");
		if (discriminant > 0) {
			// Расчёт корней
			root1 = (-b + sqrt(discriminant)) / (2 * a);
			root2 = (-b - sqrt(discriminant))/ (2 * a);
			printf("Уравнение имеет два корня: %.2f и %.2f\n", root1, root2);
			// Вывод результатов проверки
			printf("Проверка корней:\n");
			float check1, check2, check3;
			check1 = a*root1*root1 + b*root1 + c;
			check2 = a*root2*root2 + b*root2 + c;
			check3 = check1 + check2;
			printf("%.2f * %.2f * %.2f + %.2f * %.2f + %.2f = %.2f\n", a, root1, root1, b, root1, c, check1);
			printf("%.2f * %.2f * %.2f + %.2f * %.2f + %.2f = %.2f\n", a, root2, root2, b, root2, c, check2);
			printf("%.2f + %.2f = %.2f\n", check1, check2, check3);
		}
		else if (discriminant == 0){
			root1 = ((float)-b) / (2 * (float)a);
			printf("Уравнение имеет один корень: %.2f", root1);
		} else printf("Уравнение не имеет действительные корни!");
	}
	}
}