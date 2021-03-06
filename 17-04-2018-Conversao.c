//Conversão de posfixo para infixo:

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>

int topo = 0;
char algebrica[100][100];

char* pop()
{
	return algebrica[--topo];
}

void montar(char entrada)
{
	char input[100] = "", cpy[100] = "", a[100] = "", b[100] = "", str[100] = "";
	input[0] = entrada;
	strcat(str, "(");
	strcpy(b, pop());
	strcpy(a, pop());
	strcpy(cpy, a);
	strcat(str, cpy);
	strcat(str, input);
	strcpy(cpy, b);
	strcat(str, cpy);
	strcat(str, ")");
	strcpy(algebrica[topo++], str);
	
}

int main ()
{
	char input[100], cpy[100] = "";
	int x = 0;
	gets(input);
	while(input[x] != '\0')
	{
		if(!isalpha(input[x]))
		{
			montar(input[x]);
		}
		else
		{
			cpy[0] = input[x];
			strcpy(algebrica[topo++], cpy);
		}
		x++;
	}
	
	if(topo == 1)
	{
		printf("Expressao valida: %s\n", algebrica);
	}
	else
	{
		printf("Expressao invalida: %s\n", input);
	}
	return 0;	
}
