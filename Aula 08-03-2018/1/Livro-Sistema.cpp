/*Criar um TAD livro, que contém os elementos título, ano de edição, número de páginas e preço.
Criar as operações criar, acessar e liberar. Faça um programa que usa o TAD criado para ler e
armazenar em vetor dados de 5 livros. Imprimir a média do número de páginas dos livros.*/

#include<stdio.h>
#include<stdlib.h>
#include "livro.cpp"

int main () {
	Livro *livro, dados[5];
	
	char titulo[30];
	int ano = 0, pagina = 0, x = 0;
	float preco = 0, media = 0;
	
	for(x; x < 5; x++)
	{
		printf("Nome do titulo: ");
		fflush(stdin);
		gets(titulo);
		printf("Ano de edicao: ");
		scanf("%i", &ano);
		printf("Numero de paginas: ");
		scanf("%i", &pagina);
		printf("Preco: ");
		scanf("%f", &preco);
		livro = criar(titulo, ano, pagina, preco);
		dados[x] = *livro;
	}
	
	x = 0;
	
	for(x; x < 5; x++)
	{
		livro = &dados[x];
		acessar(livro, titulo, &ano, &pagina, &preco);
		media = pagina + media;
	}
	
	printf("A media de paginas dos livros: %.2f", media/x);
	
	x = 0;
	
	for(x; x < 5; x++)
	{
		livro = &dados[x];
		liberar(livro);
	}
	
	return 0;
}
