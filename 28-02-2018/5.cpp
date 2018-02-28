#include<stdio.h>

int main()
{ 
	int INTvet[3], *INTp, x = 0;
	float FLOATvet[2], *FLOATp;
	
	INTvet[0] = 0;
	INTvet[1] = 1;
	INTvet[2] = 2;
	
	FLOATvet[0] = 3.0;
	FLOATvet[1] = 4.0;
	FLOATvet[2] = 5.0;
	
	INTp = INTvet;
	FLOATp = FLOATvet;
	
	printf("INTEIRO\n");
	for(x; x<3; x++)
	{
		printf("|Vet[%d] = %d |>| Ponteiro: %p |\n", x, INTvet[x], INTp+x);
	}
	
	x = 0;
	printf("\nPONTO FLUTUANTE\n");
		for(x; x<3; x++)
	{
		printf("|Vet[%d] = %.2f |>| Ponteiro: %p |\n", x, FLOATvet[x], FLOATp+x);
	}
	
	return 0;
}
