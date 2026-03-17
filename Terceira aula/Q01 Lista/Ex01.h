#ifndef FR_H
#define FR_H

typedef struct _fr FR; 

// Aloca memória e retorna o ponteiro do Racional //
FR* CriarRacional();

// Funções de acesso //
int obter_numerador(FR *f);
int obter_denominador(FR *f);

// Libera a memória alocada //
void destruir_racional(FR *f);
//Soma dois numeros racionais recebidos por parametro//
FR* SomarRacionais(FR *f1, FR *f2);

//multiplica dois numeros racionais recebidos por parametro:D//
FR* MultiplicarRacional(FR *f1, FR *f2);

//Testa a igualdade de dois numeros racionais recebidos por parametro :o//
void TestarIgualdade(FR *f1, FR *f2);

//simplifica a racional para evitar numeros exorbitantes e overflow de memoria :)//
void SimplificarRacional(FR *r);

//funçao de apoio para a funçao "SimplificarRacional"//
int CalcularMDC(int a, int b);

#endif