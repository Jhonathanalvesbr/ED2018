#include<stdio.h>
#include<string.h>
int main(){
	char string[10] = "";
	gets(string);
	int x = strlen(string);
	for(x;x >= 0;x--)
	{
		printf("%c\n", string[x]);
	} 
	return 0;
}
