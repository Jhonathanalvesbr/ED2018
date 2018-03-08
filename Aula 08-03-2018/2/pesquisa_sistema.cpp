#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include "ficha_pesquisa.cpp"

int main ()
{
	Ficha *ficha_pesquisa, dados[5];
	int idade = 0, numerofilhos = 0, x = 0;
	char sexo[10];
	float salario = 0, media = 0;
	
	for(x; x < 5; x++)
	{
		printf("Digite a idade: ");
		scanf("%i", &idade);
		printf("Digite a quantidade de filhos: ");
		scanf("%i", &numerofilhos);
		printf("Digite o sexo Masculio ou Feminino: ");
		fflush(stdin);
		gets(sexo);
		printf("Digite o salario: ");
		scanf("%f", &salario);
		ficha_pesquisa = criar(sexo,idade,numerofilhos,salario);
		dados[x] = *ficha_pesquisa;
	}
	
	x = 0;
	
	for(x; x < 5; x++)
	{
		ficha_pesquisa = &dados[x];
		acessar(ficha_pesquisa,sexo,&idade,&numerofilhos,&salario);
		media = media + salario;
	}
	
	printf("Media de salario %.2f", media/x);
	
	for(x; x < 5; x++)
	{
		ficha_pesquisa = &dados[x];
		liberar(ficha_pesquisa);
	}
	
	return 0;	
}
