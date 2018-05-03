#include<stdlib.h>
#include<stdio.h>

// tarefa: implementar funções para:
// 1. inserir um elemento no final da lista
// 2. excluir o último elemento da lista
// 3. inserir um elemento na enésima posição
// 4. excluir o enésimo elemento

typedef struct no No;
	
struct no
{
	int informacao;
	No *proximo;
};
	
No *lista = NULL;
int x = 0;

No* getnode()
{
	No *no = (No*) malloc(sizeof(No));
	if(no != NULL)
	{
		return no;
	}
	else
	{
		printf("Memoria Insficiente.\n");
		exit(0);
	}
}

void freenode(No *no)
{
	free(no);
}


void inserirNoFim(int numero)
{
	No *ponteiro = lista, *ultimo;
	
	while(ponteiro != NULL)
	{
		ultimo = ponteiro;
		ponteiro = ponteiro->proximo;
	}
	
	ponteiro = getnode();
	ponteiro->informacao = numero;
//	ponteiro->x = x++;
	ponteiro->proximo = NULL;
	ultimo->proximo = ponteiro;
}

void removerDoFim()
{
	No *ponteiro = lista, *ultimo;
	
	while(ponteiro->proximo != NULL)
	{
		ultimo = ponteiro;
		ponteiro = ponteiro->proximo;
	}
	
	ultimo->proximo = NULL;
	free(ponteiro);
	
}



void inserirNoInicio(int numero)
{
	No *ponteiro = getnode();
	ponteiro->informacao = numero;
//	ponteiro->x = x++;
	ponteiro->proximo = lista;
	lista = ponteiro;
}


void inserirNaPosicao(int posicao, int numero)
{
	No *p1=lista, *p2, *inserir;
	int x = 0;
	while(posicao != x)
	{
		//printf("Posicao %i: %i\n", x, posicao);
		p2 = p1;
		p1 = p1->proximo;
		x++;
	}
	
	inserir = getnode();
	inserir->informacao = numero;
	inserir->proximo = p1;
	p2->proximo = inserir;
	if(posicao == 0)
	{
		inserirNoInicio(numero);
	}
}

int removerDoInicio()
{
	int remover;
	
	No *ponteiro = lista;
	remover= ponteiro->informacao;
	lista = ponteiro->proximo;
	free(ponteiro);
	
	return remover;
}

void removerNaPosicao(int posicao)
{
	No *p1=lista, *p2;
	int x = 0;
	while(posicao != x)
	{
		p2 = p1;
		p1 = p1->proximo;
		x++;
	}
	
	p2->proximo = p1->proximo;
	
	if(posicao == 0)
	{
		removerDoInicio();
	}
}

int main ()
{
	int elemento = 0;
	int pos = 0;
	
	do
	{
		system("cls");
		printf("Digite o elemento: ");
		if(elemento != 0)
		{
			inserirNoInicio(elemento);
		}
	}
	while(scanf("%i", &elemento), elemento != 0);
	
	printf("Digite a posicao: ");
	scanf("%i", &pos);
//	printf("Digite o elemento: ");
//	scanf("%i", &elemento);
	
	//inserirNaPosicao(pos, elemento);
	removerNaPosicao(pos);
	//inserirNoFim(elemento);
	
	//removerDoFim();
	
	while(lista != NULL)
	{
		printf("Elemento: %i\n", removerDoInicio());
	}
	
	return 0;
}
