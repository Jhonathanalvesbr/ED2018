/*Criar um TAD livro, que cont�m os elementos t�tulo, ano de edi��o, n�mero de p�ginas e pre�o.
Criar as opera��es criar, acessar e liberar. Fa�a um programa que usa o TAD criado para ler e
armazenar em vetor dados de 5 livros. Imprimir a m�dia do n�mero de p�ginas dos livros.*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "livro.h"

struct livro {
	char titulo[30];
	int ano, paginas;
	float preco;
};

Livro* criar(char *Titulolivro, int Anolivro, int Paginalivro, float Precolivro)
{
	Livro *objeto = (Livro*) malloc(sizeof(Livro));
	if(objeto!=NULL)
	{
		strcpy(objeto->titulo,Titulolivro);
		objeto->ano = Anolivro;
		objeto->paginas = Precolivro;
	}
	return objeto;
}

void acessar(Livro *livro, char *Titulolivro, int *Anolivro, int *Paginalivro, float *Precolivro)
{
	strcpy(Titulolivro, livro->titulo);
	*Anolivro = livro->ano;
	*Paginalivro = livro->paginas;
	*Precolivro = livro->preco;
}

void liberar(Livro *livro){
	free(livro);
}

