#include<stdio.h>

int main()
{ 
	int x; 
	int *p1, *p2; 
	p1=&x; 
	p2=p1; 
	printf("%p", p2); // SERA IMPRESSO O ENDERECO DE MEMORIA DA VARIAVEL P2 QUE E A MESMA DE P1;
	return 0;
}
