#include<stdlib.h>
#include<stdio.h>

/*1. Criar um sistema de cadastro e atendimento de pedidos que tem o seguinte menu:
[1] novo pedido (lê do teclado código numérico e insere na fila)
[2] atender (retirar da fila e mostra na tela e guarda numa outra lista)
[3] listar novos pedidos (não atendidos)
[4] listar pedidos atendidos
[0] sair*/

#define TAMANHO 100

typedef struct fila Fila;

struct fila
{
	int codigo, posicao, elemento;
};

int elemento = 0;
Fila* criar()
{
	Fila* criar = (Fila*) malloc(sizeof(Fila));
	if(criar != NULL)
	{
		criar->posicao = 55;
		criar->elemento = 0;
		return criar;
	}
	return 0;
}

Fila* novoPedido(int codigo)
{
	Fila* novo = criar();
	novo->posicao = (novo->elemento+novo->posicao)%TAMANHO;
	novo->codigo = codigo;
	novo->elemento = elemento++;
	
	return novo;
}

Fila* pedidoConlcuido(Fila* sistemam, int codigo)
{
	Fila* novo = criar();
	
	novo->posicao = (novo->elemento+novo->posicao)%TAMANHO;
	novo->codigo = codigo;
	novo->elemento++;
	
	return novo;
}

int atenderPedido(Fila* sistema)
{
	if(elemento == 0)
	{
		printf("Lista Vazia\n");
		return 0;
	}
	
	int codigo = sistema->codigo;
	
	pedidoConlcuido(sistema, codigo);
	
	sistema->posicao = (sistema->posicao+1)%TAMANHO;
	sistema->elemento--;
	elemento--;
	return codigo;
}

void listarPedidoNaoAtendido(Fila* sistema)
{
	int x = 0, qtd = sistema->elemento;
	Fila* fila = sistema;
	int ele = elemento;
	for(x; x <= qtd; x++)
	{
		printf(" N %i: %i\n", x, fila->codigo);
		fila->posicao = (fila->elemento+fila->posicao+1)%TAMANHO;
		fila->elemento--;
		ele--;
	}
}


int main ()
{
	int codigo = 0, escolha = 0;
	Fila* sistema, sistemaAtendido;
	
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
				sistema = novoPedido(codigo);
				break;
				
			case 2:
				system("cls");
				printf("\t\tPedidos\n\n");
				printf("Pedido Atendido: %i\n\n\n\n\n\n\n\n", atenderPedido(sistema));
				system("pause");
				break;
				
			case 3:
				system("cls");
				printf("\t\tPedidos\n\n");
				printf("Pedidos Nao Atendidos: %i\n", sistema->elemento+1);
				printf("");
				listarPedidoNaoAtendido(sistema);
				system("pause");
				break;
				
			case 4:
				
				break;
				
		}
		
	}
	while(escolha != 0);

	
	
	
	
	
	return 0;
}
