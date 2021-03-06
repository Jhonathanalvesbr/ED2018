// 1. Simule a ação do algoritmo de análise de expressões para cada uma das seguintes strings,
// apresentando o conteúdo da pilha em cada ponto
// a. (A + B} ) 1- Empilha (, 2- Empilha }, 3- Empilha
// b. {[A+B]-[(C-D)] 1- Empilha {, 2- Empilha [, 3- Desempilha ], 4- Empilha [, 5- Empilha (, 6- Desempilha ), 7- Desempilha ] 
// c. (A+B)-{C+D}-[F+G] 1- Empilha (, 2- Desempilha ), 3- Desempilha {, 4- Desempilha }, 5- Empilha [, 6- Desempilha ]
// d. ((H)*{([J+K])}) 1- Empilha (, 2- Empilha (, 3- Desempilha ), 4- Empilha {, 5- Empilha (, 6- Empilha [, 7- Desempilha ], 8- Desempilha ), 9- Desempilha }, 10- Desempilha
// e. (((A)))) 1- Empilha (, 2- Empilha (, 3- Empilha (, 4- Desempilha ), 5- Desempilha ), 6- Desempilha ), 7- Desempilha )

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 100

char pilha[N], topo;

void criar_pilha()
{
	topo = 0;
}

void push(char x)
{
	printf("Empilha : %c\n", x);	
	pilha[topo++] = x;
}

void pop(char x)
{
	printf("Desempilha : %c\n", x);
	pilha[topo--];	
}

int pilha_vazia()
{
	return topo <= 0;
}

int main ()
{
	char x[7] = "ABABBA", y[7] = "ABBABA", c[1];
	int z = 0;
	
	criar_pilha();
	
	for(z; z < strlen(x); z++)
	{
		if(x[z] >= 0)
		{
			push(x[z]);
		}
	}
	
	scanf("%c", &c);
	
	for(z; z >= 0; z--)
	{
		if(x[z] >= 0)
		{
			if(pilha[topo] == x[z])
			{
				pop(x[z]);
			}
		}
	}
	
	return 0;
}
