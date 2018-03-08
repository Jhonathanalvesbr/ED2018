typedef struct ficha_pesquisa Ficha; 

Ficha* criar(char *Fsexo, int Fidade, int Fnumerofilhos, float Fsalario);
void acessar(Ficha *ficha_pesquisa, char *Fsexo, int Fidade, int Fnumerofilhos, float Fsalario);
void liberar(Ficha *ficha_pesquisa);

