#include<stdio.h>

int main()
{ 
	int x, *p;
	x=10;
	//p=x; LINHA ERRADA. PONTEIRO NÃO RECEBE VALOR DA VARIAVEL E SIM O ENDERECO DE MEMORIA DA VARIAVEL.
	p = &x; // LINHA CORRIGIDA.
	printf("%d\n", *p);
	return 0;
}
