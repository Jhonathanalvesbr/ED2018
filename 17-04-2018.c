//Opções:
//1-Inversão de string:
//2-Conversão de posfixo para infixo:

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>


int itopo = 0;
char inversao[100];

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

void conver ()
{
	char input[100], cpy[100] = "";
	int x = 0;
	printf("Conversao de posfixo para infixo: ");
	fflush(stdin);
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
	puts("");
	system("pause");
}

char ipop()
{
	inversao[itopo] = '\0';
	return inversao[--itopo];
}

void ipush(char inverter)
{
	inversao[itopo++] = inverter;
}

void inver()
{
	char inverter[100];
	int x = 0;
	printf("Inversao de string: ");
	fflush(stdin);
	gets(inverter);
	
	while(inverter[x] != '\0')
	{
		ipush(inverter[x]);
		x++;
	}
	printf("Inversao: ", inverter);
	while(x > 0)
	{
		printf("%c", ipop());
		x--;
	}
	printf("\n\n");
	system("pause");
}

int main ()
{
	int escolha = 0;
	printf("1 - Inversao de string\n2 - Conversao de posfixo para infixo\n");
	scanf("%i", &escolha);
	switch (escolha)
	{
		case 1:
			system("cls");
			inver();
			break;
		case 2:
			system("cls");
			conver();
			break;
		default:
			system("cls");
			printf("Opcao Invalida!\n");
	}
	
	
	
	return 0;
}
