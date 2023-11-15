#define TAMPILA 100
#define TRUE 1
#define FALSE 0

#include<stdlib.h>
#include "pila.h"

void manejaMsg(int);

PILA crearPila(void){
	PILA S;
	S = (PILA)malloc(sizeof(Pila));
	if (S == NULL){
		manejaMsg(0);
        	exit(0);
	}
	S->tope = -1;
	return S;
}

void apilar(PILA S, Expediente e){
	if(S->tope == TAMPILA -1){
		manejaMsg(2);
		exit(0);
	}
	S->tope++;
	S->pila[S->tope] = e;
}

int es_vaciaPila(PILA S){
	if(S->tope<0)
		return TRUE;
	else
		return FALSE;
}

Expediente desapilar(PILA S){
	Expediente v;
	if(es_vaciaPila(S)==TRUE){
		manejaMsg(3);
		exit(0);
	}
	v = S->pila[S->tope];
	S->tope--;
	return v;
}

Expediente elemTope(PILA S){
	Expediente v;
	if(es_vaciaPila(S)==TRUE){
		manejaMsg(3);
		exit(0);
	}
	v=desapilar(S);
	apilar(S,v);
	return v;
}

