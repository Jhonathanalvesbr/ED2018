/*
1- Faça um programa que leia um valor inteiro n e crie dinamicamente um vetor de n elementos
do tipo inteiro. Em seguida o programa deve ler os elementos desse vetor. Depois, o vetor
preenchido deve ser impresso. Além disso, antes de finalizar o programa, deve-se liberar a área
de memória alocada.
*/

#include<stdio.h>
#include<stdlib.h>

int main ()
{
	int n = 0, *p;
	
	printf("Entre com o numero de vetor: ");
	scanf("%i", &n);
	p = (int *) malloc(sizeof(int)*n);
	
	printf("\n");
	
	for(int x=0; x < n; x++)
	{
		printf("Digite um numero do vetor [%i]: ", x);
		scanf("%i", (p+x));
	}
	
	printf("\n");
	
	for(int x=0; x < n; x++)
	{
		printf("\tVet [%i] = %i\n", x, *(p+x));
	}
	
	free(p);
	
	return 0;
}
