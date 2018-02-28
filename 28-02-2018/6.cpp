#include<stdio.h>

int main()
{ 
	float a, b, *p;
	b = 3.0;
	scanf("%f", &a);
	printf("%.2f\n", a);
	printf("%p\n", &a);
	printf("%.2f\n", &p);
	printf("%p\n", p);
	p = &a;
	printf("%i\n", p);
	printf("%.2f\n", b);
	printf("%p\n", &b);
	return 0;
}
