#include<stdio.h>

int main (){
	int n1 =0, n2 =0, n3 =0, n4 =0;
	float soma =0;
	scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
	soma = n1+n2+n3+n4;
	if(soma / 4 >= 6)
	{
		printf("\n------------------\n| %.2f Aprovado|\n------------------\n", soma/4);
	}
	else
	{
		printf("\n------------------\n| %.2f Reprovado|\n------------------\n", soma/4);
	} 
	return 0;
}
