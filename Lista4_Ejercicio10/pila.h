#ifndef _pila_
#define _pila_
#define TAMPILA 100

typedef struct{
	int placa;
	char estado[3];
	char marca[25];
	char modelo[25];
	int año;
	char propietario[25];
}Vehiculo;

typedef struct{
	Vehiculo pila[TAMPILA];
	int tope;
}Pila;

typedef Pila * PILA;

//Operaciones
PILA crearPila(void);
void apilar(PILA S, Vehiculo e);
int es_vaciaPila(PILA S);
Vehiculo desapilar(PILA S);
Vehiculo elemTope(PILA S);

#endif
