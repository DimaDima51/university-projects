#include <stdio.h>
#include <locale.h>
#include <math.h>

int main() {
	setlocale(LC_ALL, "RUS");
	int a, b, c;
	float discriminant, root1, root2;
	char term;
	printf("������� ������������ a b c: ");
	if ((scanf("%d %d %d%c", &a, &b, &c, &term) != 4) || (term != '\n'))
		printf("������ �����!");
	else 
	{
	discriminant = (float)b * (float)b - 4 * (float)a * (float)c;
	if(a == 0 && b == 0 && c == 0) printf("a = 0, b = 0, c = 0\n��������� �����������!");
	else if(a == 0 && b == 0 && c != 0) printf("a = 0, b = 0, c != 0\n��������� �� ����� �������!");
	else if(a == 0 && b != 0 && c == 0) printf("a = 0, b != 0, c = 0\nx = 0");
	else if(a == 0 && b != 0 && c != 0){
		printf("%d %d %d", a, b, c);
		printf("a = 0, b != 0, c != 0\n��������� �������� ��������: bx + c = 0\n");
		root1 = -((float)c/(float)b);
		printf("��������� ����� ���� ������: %.2f", root1);
	}
	else if(a != 0 && b == 0 && c == 0) printf("a != 0, b = 0, c = 0\nx = 0\n��������� ����� 2");
	else if(a != 0 && b == 0 && c != 0) {		
		printf("a != 0, b = 0, c != 0\n");
		if (c < 0){
			root1 = sqrt(((float)-c)/(float)a);
			root2 = -sqrt(((float)-c)/(float)a);
			printf("��������� ����� ��� �����: %.2f %.2f", root1, root2);
		} else printf("��������� �� ����� �������������� �����!");
	}
		else if(a != 0 && b != 0 && c == 0) {
		printf("a != 0, b != 0, c = 0\n");
		root1 = 0;
		root2 = -((float)b/(float)a);
		printf("��������� ����� ��� �����: %.2f � %.2f\n", root1, root2);
	}
	else {
		printf("a != 0, b != 0, c != 0\n");
		if (discriminant > 0) {
			// ������ ������
			root1 = (-b + sqrt(discriminant)) / (2 * a);
			root2 = (-b - sqrt(discriminant))/ (2 * a);
			printf("��������� ����� ��� �����: %.2f � %.2f\n", root1, root2);
			// ����� ����������� ��������
			printf("�������� ������:\n");
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
			printf("��������� ����� ���� ������: %.2f", root1);
		} else printf("��������� �� ����� �������������� �����!");
	}
	}
}