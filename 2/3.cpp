#include<stdio.h>

int main ()
{
	int mat[4][4], x = 0, i = 0;
	for(x; x < 2; x++)
	{
		for(i; i < 3; i++)
		{
			scanf("%i", &mat[x][i]);
		}
		
		i = 0;
	}
	x = 0, i = 0;
	printf("________________\n");
	for(x; x < 2; x++)
	{
		for(i; i < 3; i++)
		{
			printf("| %d ", mat[x][i]);
		}
		printf("|\n");
		i = 0;
	}
	printf("________________\n");		
	return 0;
}
