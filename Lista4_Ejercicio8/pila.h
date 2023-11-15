#ifndef _pila_
#define _pila_
#define TAMPILA 100

typedef struct{
	int dia;
	int mes;
	int año;
}Fecha;

typedef struct{
	int numero;
	char titular[50];
	char tramite[50];
	Fecha fecha;
}Expediente;

typedef struct{
	Expediente pila[TAMPILA];
	int tope;
}Pila;

typedef Pila * PILA;

//Operaciones
PILA crearPila(void);
void apilar(PILA S, Expediente e);
int es_vaciaPila(PILA S);
Expediente desapilar(PILA S);
Expediente elemTope(PILA S);

#endif
