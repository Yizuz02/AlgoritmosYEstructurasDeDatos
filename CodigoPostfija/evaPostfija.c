#include <stdio.h>
#include<stdlib.h>
#include "evaPostfija.h"

void manejaMsg(int e);

//Creacion de una pila vacia
void crearPila(PILA *S){
	
	*S = (PILA)malloc(sizeof(Pila));
	if (*S == NULL){
	manejaMsg(0);
	exit(0);

	}
	(*S)->tope =-1;
}

/* Anadir un elemento a la Pila*/
void apilar(PILA S, float e){
	if (S -> tope == TAMPILA -1){
	manejaMsg(3); // Pila llena
	exit(0);
	}
S -> tope++;
S -> pila[S -> tope] = e;

}
int es_vaciaPila(PILA S){
    if(S->tope<0)
		return 1;
    return 0;
}

/* Sacar un elemento de la Pila */
float desapilar(PILA S){
	float v;
	if(es_vaciaPila(S)==TRUE){
		manejaMsg(4);//PILA VACIA
		exit(0);
		}
	v = S->pila[S->tope];
	S -> tope --;
	return v;
}
