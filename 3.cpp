#include<stdio.h>

int main(){
	int x = 299, i = 101;
	for(x; x >= i;x--)
	{
		if(x % 2 != 0)
		{
			printf("|%d|\n", x);
		}
	}
	return 0;
}
