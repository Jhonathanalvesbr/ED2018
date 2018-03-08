/*Criar um TAD livro, que contém os elementos título, ano de edição, número de páginas e preço.
Criar as operações criar, acessar e liberar. Faça um programa que usa o TAD criado para ler e
armazenar em vetor dados de 5 livros. Imprimir a média do número de páginas dos livros.*/

typedef struct livro Livro;

Livro* criar(char *titulo, int ano, int paginas, float preco);
void acessar(Livro *livro, char *titulo, int ano, int paginas, float preco);
void liberar(Livro *livro);
