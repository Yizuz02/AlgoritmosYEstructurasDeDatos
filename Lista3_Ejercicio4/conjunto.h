#include<stdio.h>
#ifndef  _conjunto_
#define  _conjunto_

typedef struct{
   int * elem;
   int num_elem;
   int tamaño;
}Conjunto;

typedef Conjunto * CONJUNTO;

// operaciones
CONJUNTO conjuntoVacio(int);
void añadir(CONJUNTO, int);
void retirar(CONJUNTO, int);
int pertenece(CONJUNTO, int);
int esVacio(CONJUNTO);
int cardinal(CONJUNTO);
int elemento(CONJUNTO, int);
CONJUNTO unionConjunto(CONJUNTO, CONJUNTO);
CONJUNTO interseccion(CONJUNTO, CONJUNTO);
int inclusion(CONJUNTO, CONJUNTO);
#endif
