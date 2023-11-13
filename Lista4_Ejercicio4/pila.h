#ifndef _pila_
#define _pila_
#define TAMPILA 100

typedef struct{
	int pila[TAMPILA];
	int tope;
}Pila;

typedef Pila * PILA;

//Operaciones
PILA crearPila(void);
void apilar(PILA S, int e);
int es_vaciaPila(PILA S);
int desapilar(PILA S);
int elemTope(PILA S);

#endif
