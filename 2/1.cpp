#include<stdio.h>
#include<string.h>
int main (){
	char palavra[21] = "";
	gets(palavra);
	if(strcmp(palavra,"teste") == 0)
	{
		printf("OK.\n", palavra);
	}
	else
	{
		printf("KO.\n", palavra);
	}
	return 0;
}
