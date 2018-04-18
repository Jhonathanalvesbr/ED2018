#include<stdio.h>
#include<stdlib.h>

// 1) Explique a diferença entre:
// p++; = Acrescenta o ponteiro em +1, passando para o próximo valor apontado na memoria do mesmo tipo.
// (*p)++; = Acrescenta no conteudo apontado pelo ponteiro +1.
// *(p++); = //Incrementa o ponteiro em +1, passando para o próximo valor do mesmo tipo.

// 2) O que quer dizer *(p+10); ?
// Incrementa o ponteiro em +10, passando para o decimo valor do mesmo tipo.

// Exercicio3 3) Qual o valor de y no final do programa? Tente primeiro descobrir e depois verifique no
// computador o resultado. A seguir, escreva um /* comentário */ em cada comando de atribuição
// explicando o que ele faz e o valor da variável à esquerda do '=' após sua execução.
void exercicio3 () {
	int y, *p, x; // Declara variaveis do tipo inteiro, e uma variavel do tipo ponteiro.
	y = 0; // Atribui para a variavel y o valor 0.
	p = &y; // Faz um apontamento de p para a variavel y.
	x = *p; // Variavel x recebe o conteudo apontado por p.
	x = 4; // Variavel x recebe 4.
	(*p)++; // Incrementa em +1 o conteudo apontado por p.
	x--; // Reduz em -1 o valor da varival x.
	(*p) += x; // Pega o conteudo apontado por p a soma com a variavel x.
	printf ("y = %d\n", y);// Mostra para o usuario depois do sinal de '=' o valor final da variavel y em '%d' do tipo decimal.
	system("pause");
	system("cls");
}

// 4) Verifique o programa abaixo. Encontre o seu erro e corrija-o para que escreva o
// número 10 na tela (mantenha a variável q como parâmetro do printf).
void exercicio4 () {
	int x, *p, **q;
	p = &x;
	q = &p;
	x = 10;
	printf("%d\n", **q); // Ponteiro de ponteiro, ou seja, um ponteiro q que aponta para p, e p apontando para x.
	system("pause");
	system("cls");
}

// 5) Escreva um programa que declare uma matriz 100x100 de inteiros. Voce deve
// inicializar a matriz com zeros usando ponteiros. Preencha depois a matriz com os
// números de 1 a 10.000 usando ponteiros.
void exercicio5 () {
	int mat[100][100], x = 0, y = 0, z = 1, *p, *po, *poo;

	p = &x;
	po = &y;
	poo = &z;

	for(*p; *p < 100; (*p)++) {
		for(*po; *po < 100; (*po)++) {
			mat[*p][*po] = 0;
		}
		(*po) =0;
	}

	for(*p; *p < 100; (*p)++) {
		for(*po; *po < 100; (*po)++) {
			mat[*p][*po] = 	*poo;
			printf("[%d]:[%d] = %i\n",x,y, mat[x][y]);
			(*poo)++;
		}
		(*po) =0;
	}

	system("pause");
	system("cls");
}

// 6) O valor de uma variável ou expressão do tipo vetor é o endereço do elemento zero
// do vetor. Seja a[] um vetor qualquer, independente de tipo e tamanho, e pa um
// ponteiro para o mesmo tipo de a[]. Responda V ou F, justificando:
// (V) Após a atribuição pa=&a[0]; pa e a possuem valores identicos, isto é, apontam
// para o mesmo endereço
// (V) A atribuição pa=&a[0]; pode ser escrita como pa=a;
// (V) a[i] pode ser escrito como *(a+i)
// (V) &a[i] e a+i são idênticos
// (V) a+i e' o endereço do i-ésimo elemento após a
// (V) pa[i] e' idêntico a *(pa+i)
// (V) pa=a e' uma operação valida
// (V) pa++ e' uma operação valida
// (F) a=pa e' uma operação valida
// (F) a++ e' uma operação valida

// 7) O que está errado com os programas abaixo? Descubra e indique a solução para
// consertá-los. Execute-o no computador para ver se o erro foi resolvido.
// a)
// void main(void) /* esse programa esta errado */ {
//	int x, *p;
//	x = 10;
//	*p = x; p ainda nao foi atribuido para um endreço especifico, portanto não pode receber o conteudo de x.
// }
// b)
// void main(void) /* esse programa esta errado */ {
//	int x, *p;
//	x = 10;
//	p = x; Linha errada, atribuição correta seria p = &x.
//	printf ("%d", *p);
// }

// 8) Quais serão os valores de x, y e p ao final do trecho de código abaixo?
// int x, y, *p;
// y = 0; p = &y;
// x = *p; x = 4;
// (*p)++;
// --x;
// (*p) += x; 
// x vale 3, y vale 1, p e o ponteiro para y ou seja, vale 1.

// 9) Os programas (trechos de código) abaixo possuem erros. Qual(is)? Como deveriam
// ser?

// a)
// void main() {
// int x, *p;
// x = 100;
// p = x; 
// printf(“Valor de p: %d.\n”, *p);
// }
// p ainda nao foi atribuido para um endreço especifico, portanto não pode receber o conteudo de x.

// b)
// void troca (int *i, int *j) {
// int *temp;
// *temp = *i;
// *i = *j;
// *j = *temp;
// }
// variavel temp deveria ser do tipo inteiro sem ser ponteiro, pois so precisa receber o conteudo apontado para fazer a troca.

// c)
// char *a, *b;
// a = "abacate";
// b = "uva”;
// if (a < b)
// printf ("%s vem antes de %s no dicionário", a, b);
// else
// printf ("%s vem depois de %s no dicionário", a, b);
// A comparacao de string esta errada, esta comparacao se faz pela funcao strlen() que retorna um valor inteiro;

// 10) Suponha que os elementos do vetor v são do tipo int e cada int ocupa 8 bytes no seu
// computador. Se o endereço de v[0] é 55000, qual o valor da expressão v + 3?
// v[0] = 55000
// v[1] = 55008,
// v[2] = 55016,
// v[3] = 55024, 
// V[3] ira possuir 55024.

int main() {

	exercicio3();

	exercicio4();

	exercicio5();

	return(0);
}
