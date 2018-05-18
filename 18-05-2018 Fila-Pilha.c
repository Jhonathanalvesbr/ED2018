#include<stdio.h>
#include<stdlib.h>

#define E 10

struct pilha 
{
	int pilha[E];
	int topo;
};

struct fila
{
	int pilha[E];
	int posicao;
	int elemento;	
};

typedef struct pilha Pilha;
typedef struct fila Fila;

Fila* criarFila();
Pilha* criarPilha();
void push(Pilha* pilha, int input);
int pop(Pilha* pilha);
void inserir(Fila* fila, int input);

int main ()
{
	Pilha* pilha1 = criarPilha();
	Pilha* pilha2 = criarPilha();
	Fila* fila = criarFila();
	
	int input = -1;
	
	while(input != 0)
	{
		printf("Push: ");
		scanf("%i", &input);
		push(pilha1, input);
	}
	
	puts("");
	
	while(pilha1->topo != -1)
	{
		push(pilha2,pop(pilha1));
		printf("Pop: %i\n", pilha2->pilha[pilha2->topo]);
	}
	
	printf("\nFila\n\n");
	
	while(pilha2->topo != -1)
	{
		inserir(fila,pop(pilha2));
		printf("Fila: %i\n", fila->pilha[fila->posicao]);
	}
	
	return 0;
}

Fila* criarFila()
{
	Fila* criar = (Fila*) malloc(sizeof(Fila));
	if(criar != NULL)
	{
		criar->posicao = 5;
		criar->elemento = 0;
		
		return criar;
	}
}

Pilha* criarPilha()
{
	Pilha* criar = (Pilha*) malloc (sizeof (Pilha));
	if(criar != NULL)
	{
		criar->topo = -1;
		
		return criar;
	}
}

void push(Pilha* pilha, int input)
{
	pilha->topo++;
	pilha->pilha[pilha->topo] = input;
}

int pop(Pilha* pilha)
{
	int input = pilha->pilha[pilha->topo];
	pilha->topo--;
	
	return input;
}

void inserir(Fila* fila, int input)
{
	fila->posicao = (fila->posicao+fila->elemento)%E;
	fila->elemento++;
	fila->pilha[fila->posicao] = input;
}
