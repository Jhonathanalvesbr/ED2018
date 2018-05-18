#include<stdio.h>
#include<stdlib.h>

#define E 10

struct fila
{
	int placa[E];
	int posicao;
	int elemento;	
};

typedef struct fila Fila;
typedef struct pilha Pilha;

Fila* criarFila();
Fila* inserir(Fila* fila, int placa);
int remover(Fila* fila);
int removerPosi(Fila* fila, int posicao);
void listar(Fila *fila);

int main ()
{
	Fila* fila;
	Fila* esperar;
	
	int input = 0;
	int placa = 0;
	int entrada = 0; 
	
	fila = criarFila();
	esperar = criarFila();
	
	while(1)
	{
		system("cls");
		printf("\t Estacionamento\nVagas Ocupadas: %i\nVeiculos em Espera: %i\n\n", fila->elemento, esperar->elemento);
		printf("1- Estacionar\n");
		printf("2- Retirar\n");
		printf("3- Listar veiculos dentro do estacionamento\n");
		printf("4- Listar veiculos Aguardando\n");
		scanf("%i", &input);
		if(input == 1)
		{
			printf("Digite a placa: ");
			scanf("%i", &placa);
			if(fila->elemento == 10)
			{
				inserir(esperar, placa);
			}
			else
			{
				inserir(fila, placa);
			}
		}
		else if(input == 2)
		{
			printf("Qual deseja Retirar?\n");
			listar(fila);
			
			scanf("%i", &entrada);
			removerPosi(fila,entrada);
			if(esperar->elemento > 0)
			{
				inserir(fila, esperar->placa[(esperar->posicao)%E]);
				remover(esperar);
			}
			system("pause");
		}
		else if(input == 3)
		{
			listar(fila);
			system("pause");
		}
		else if(input == 4)
		{
			listar(esperar);
			system("pause");
		}
	}
	
	return 0;
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

void listar(Fila *fila)
{
	Fila f = *fila;
	int x = 1;
	while(f.elemento > 0)
	{
		printf("%i - Placa: %i\n", x, f.placa[f.posicao]);
		f.elemento--;
		f.posicao = (f.posicao+1)%E;
		x++;
	}
}

Fila* inserir(Fila* fila, int placa)
{
	if(fila->elemento == 10)
	{
		printf("Estacionamento cheio\n");
		return 0;
	}
	
	fila->placa[(fila->elemento+fila->posicao)%E] = placa;
	fila->elemento++;
	
	return fila;
}

int remover(Fila* fila)
{
	Fila remover = *fila;
	
	if(fila->elemento == 0)
	{
		printf("Estacionamento Vazio\n");
		return 0;
	}
	
	int placa = fila->placa[fila->posicao];
	fila->posicao = (fila->posicao+1)%E;
	fila->elemento--;
	
	return placa;
}

int removerPosi(Fila* fila, int posicao)
{
	Fila *novo=criarFila();
	
	
	int x = 1;
	
	if(fila->elemento == 0)
	{
		printf("Estacionamento Vazio\n");
		return 0;
	}
	
	for(x; x < posicao; x++)
	{
		inserir(novo, remover(fila));
	}

	printf("Veiculo saiu: %i\nQuantidade de movimentos: %i\n", fila->placa[fila->posicao], x);
	remover(fila);
	
	for(x; x > 1; x--)
	{
		
		inserir(fila, remover(novo));
	}

}
