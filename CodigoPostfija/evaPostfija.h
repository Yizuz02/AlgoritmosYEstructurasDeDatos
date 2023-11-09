#ifndef _pila_
#define _pila_

#define TAMPILA 100  
#define TRUE 1
#define FALSE 0

typedef struct {
	float pila[TAMPILA];
	int tope; 	
} Pila;

typedef Pila * PILA;


void crearPila(PILA *S);
void apilar(PILA S, float x);
int es_vaciaPila(PILA S);
float desapilar(PILA S);

#endif
