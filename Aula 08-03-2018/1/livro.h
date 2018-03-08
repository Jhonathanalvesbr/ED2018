/*Criar um TAD livro, que cont�m os elementos t�tulo, ano de edi��o, n�mero de p�ginas e pre�o.
Criar as opera��es criar, acessar e liberar. Fa�a um programa que usa o TAD criado para ler e
armazenar em vetor dados de 5 livros. Imprimir a m�dia do n�mero de p�ginas dos livros.*/

typedef struct livro Livro;

Livro* criar(char *titulo, int ano, int paginas, float preco);
void acessar(Livro *livro, char *titulo, int ano, int paginas, float preco);
void liberar(Livro *livro);
