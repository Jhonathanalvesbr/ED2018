#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "ficha.h"

struct ficha_pesquisa
{
	int idade, numerofilhos;
	float salario;
	char sexo[10];
};

Ficha* criar(char *Fsexo, int Fidade, int Fnumerofilhos, float Fsalario)
{
	Ficha *objeto = (Ficha*) malloc(sizeof(Ficha));
	if(objeto != NULL)
	{
		strcpy(objeto->sexo,Fsexo);
		objeto->idade = Fidade;
		objeto->numerofilhos = Fnumerofilhos;
		objeto->salario = Fsalario;
	}
	return objeto;
}

void acessar(Ficha *ficha_pesquisa, char *Fsexo, int *Fidade, int *Fnumerofilhos, float *Fsalario)
{
	strcpy(Fsexo,ficha_pesquisa->sexo);
	*Fidade = ficha_pesquisa->idade;
	*Fnumerofilhos = ficha_pesquisa->numerofilhos;
	*Fsalario = ficha_pesquisa->salario;
}

void liberar(Ficha *ficha_pesquisa)
{
	free(ficha_pesquisa);
}
