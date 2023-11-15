#ifndef _pila_
#define _pila_
#define TAMPILA 100

typedef struct{
	char pila[TAMPILA][25];
	int tope;
}Pila;

typedef Pila * PILA;

//Operaciones
PILA crearPila(void);
void apilar(PILA S, char e[]);
int es_vaciaPila(PILA S);
char * desapilar(PILA S);
char * elemTope(PILA S);

#endif
