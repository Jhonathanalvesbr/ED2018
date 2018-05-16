#include<stdio.h>
#include<stdlib.h>

#define E 10

struct fila
{
	int placa[E];
	int posicao;
	int elemento;	
};

struct pilha
{
	int placa[E];
	int posicao;
};

typedef struct fila Fila;
typedef struct pilha Pilha;

Pilha* criarPilha();
Fila* criarFila();
Fila* inserir(Fila* fila, int placa);
Fila* remover(Fila* remover);

int main ()
{
	Pilha* pilha;
	Fila* fila;
	int input = 0;
	int placa = 0;
	
	fila = criarFila();
	pilha = criarPilha();
	
	while(1)
	{
		system("cls");
		printf("Estacionamento - Vagas: %i\n", fila->elemento);
		printf("1- Estacionar\n");
		printf("2- Retirar\n");
		scanf("%i", &input);
		if(input == 1)
		{
			printf("Digite a placa: ");
			scanf("%i", &placa);
			inserir(fila, placa);
		}
		else if(input == 2)
		{
			remover(fila);
		}
	}
	
	return 0;
}

Pilha* criarPilha()
{
	Pilha* pilha = (Pilha*) malloc (sizeof(Pilha));
	if(pilha != NULL)
	{
		pilha->posicao = 0;
		
		return pilha;
	}
}

Pilha* pop(Pilha* pilha, int placa)
{
	pilha->placa[pilha->posicao++] = placa;
	
	return pilha;
}

Pilha* push(Pilha* pilha)
{
	
}

Fila* criarFila()
{
	Fila* fila = (Fila*) malloc (sizeof(Fila));
	if(fila != NULL)
	{
		fila->elemento = 0;
		fila->posicao = 7;
		
		return fila;
	}
}

Fila* inserir(Fila* fila, int placa)
{
	if(fila->elemento == 10)
	{
		printf("Estacionamento cheio\n");
		system("pause");
		return 0;
	}
	fila->placa[(fila->elemento+fila->posicao)%E] = placa;
	fila->elemento++;
	
	return fila;
}

Fila* remover(Fila* remover)
{
	Fila* fila = remover;
	
	if(fila->elemento == 0)
	{
		printf("Estacionamento Vazio\n");
		system("pause");
		return 0;
	}
	
	printf("Veiculo Placa: %i\n", fila->placa[fila->posicao]);
	system("pause");
	fila->posicao = (fila->posicao+1)%E;
	fila->elemento--;
	
	return fila;
}
