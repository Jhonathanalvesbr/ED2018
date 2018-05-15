#include<stdlib.h>
#include<stdio.h>

/*1. Criar um sistema de cadastro e atendimento de pedidos que tem o seguinte menu:
[1] novo pedido (lê do teclado código numérico e insere na fila)
[2] atender (retirar da fila e mostra na tela e guarda numa outra lista)
[3] listar novos pedidos (não atendidos)
[4] listar pedidos atendidos
[0] sair*/

#define TAMANHO 100


struct fila
{
	int codigo[TAMANHO], posicao, elemento;
};

typedef struct fila Fila;


Fila* criar();
void novoPedido(int codigo, Fila* sistema);
void atenderPedido(Fila* sistema, Fila* sistemaAtendido);
void listar(Fila* sistema);

int main ()
{
	int codigo = 0, escolha = 0;
	Fila *sistema, *sistemaAtendido;
	
	sistema = criar();
	sistemaAtendido = criar();
	
	do
	{
		system("cls");
		printf("\t\tCastro\n");
		printf(" 1-Novo Pedido\n");
		printf(" 2-Atender Pedido\n");
		printf(" 3-Lista de Pedidos Nao Atendidos\n");
		printf(" 4-Lista de Pedidos Finalizados\n");
		printf(" 0-Encerrar\n\n");

		scanf(" %i", &escolha);
		
		switch (escolha)
		{
			case 1:
				system("cls");
				printf("\t\tCastro\n\n");
				printf("Digite um codigo numerico: ");
				scanf("%i", &codigo);
				novoPedido(codigo, sistema);
				system("pause");
				break;
				
			case 2:
				system("cls");
				printf("\t\tPedidos\n\n");
				atenderPedido(sistema, sistemaAtendido);
				printf("Pedido Atendido: %i\n", sistemaAtendido->codigo[(sistemaAtendido->posicao+sistemaAtendido->elemento-1)%TAMANHO]);
				system("pause");
				break;
				
			case 3:
				system("cls");
				printf("\t\tPedidos\n\n");
				printf("Quantidade de Pedidos Nao Atendidos: %i\n", sistema->elemento);
				printf("");
				listar(sistema);
				system("pause");
				break;
				
			case 4:
				system("cls");
				printf("\t\tPedidos\n\n");
				printf("Quantidade de Pedidos Atendidos: %i\n", sistemaAtendido->elemento);
				printf("");
				listar(sistemaAtendido);
				system("pause");
				break;
				
		}
		
	}
	while(escolha != 0);
	
	
	return 0;
}

void listar(Fila *sistema)
{
	Fila listar = *sistema;
	{
		while(listar.elemento > 0)
		{
			int codigo = listar.codigo[listar.posicao];
			printf("%i\n", codigo);
			listar.posicao = (listar.posicao+1)%TAMANHO;
			listar.elemento--;
		}
	}
}

void atenderPedido(Fila* sistema, Fila* sistemaAtendido)
{
	if(sistema->elemento > 0)
	{
		int codigo = sistema->codigo[sistema->posicao];
		sistema->posicao = (sistema->posicao+1)%TAMANHO;
		sistema->elemento--;
		
		novoPedido(codigo, sistemaAtendido);
	}
	
}

void novoPedido(int codigo, Fila* fila)
{
	fila->codigo[(fila->posicao+fila->elemento)%TAMANHO] = codigo;
	fila->elemento++;
}

Fila* criar()
{
	Fila* fila = (Fila*) malloc(sizeof(Fila));
	if(fila != NULL)
	{
		fila->posicao = 70;
		fila->elemento = 0;
		return fila;
	}
}
