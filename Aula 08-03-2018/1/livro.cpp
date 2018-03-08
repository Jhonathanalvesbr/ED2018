/*Criar um TAD livro, que contém os elementos título, ano de edição, número de páginas e preço.
Criar as operações criar, acessar e liberar. Faça um programa que usa o TAD criado para ler e
armazenar em vetor dados de 5 livros. Imprimir a média do número de páginas dos livros.*/

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

