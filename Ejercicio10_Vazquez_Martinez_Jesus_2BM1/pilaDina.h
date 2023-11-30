#ifndef pilaDina
#define pilaDina

#define TRUE    1
#define FALSE  0

typedef struct Nodo_Pila{
    int dato;
    struct Nodo_Pila * anterior;
}Nodo_Pila;

typedef struct{
	Nodo_Pila * tope;
}Pila;
typedef Pila * PILA;

//Operaciones
PILA crearPila(void);
Nodo_Pila * crearNodoPila(void);
void apilar(PILA S, int e);
int es_vaciaPila(PILA S);
int desapilar(PILA S);
int elemTope(PILA S);
#endif
