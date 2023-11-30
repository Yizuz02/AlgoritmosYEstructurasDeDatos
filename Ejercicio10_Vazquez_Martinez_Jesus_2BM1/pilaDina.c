#define TAMPILA 100
#define TRUE 1
#define FALSE 0

#include<stdlib.h>
#include "pilaDina.h"

void manejaMsg(int);

PILA crearPila ( ){
	PILA S;
	S = (PILA)malloc(sizeof(Pila));
	if( S == NULL){
		manejaMsg(0); 
		exit(0);
	}
        S -> tope = NULL;
        return S;
}


// ESTA VACÍA LA PILA
int es_vaciaPila(PILA S){
	if( S-> tope == NULL)
		return TRUE;
	else
		return FALSE;
}

// CREA UN ELEMENTO DE LA PILA
Nodo_Pila * crearNodoPila(  ){
   Nodo_Pila * nvo;
   nvo = (Nodo_Pila *)malloc(sizeof(Nodo_Pila));
   if(nvo == NULL){
      manejaMsg(0);
      exit(0); 
   }
   return nvo;
}

// CONSULTAR EL ELEMENTO DEL TOPE LA PILA

int elemTope(PILA S){
	int v;
	if( es_vaciaPila(S)==TRUE){
		manejaMsg(3);  //PILA VACIA
		exit(0);
	}
	v = S ->tope->dato;
	return v;
}

// AGREGAR ELEMENTOS A LA PILA

void apilar(PILA S, int e){
       Nodo_Pila * nvo;
        nvo = crearNodoPila( );	
        nvo -> dato = e;
        nvo ->anterior = S->tope;
        S-> tope = nvo;
}

// ELIMINAR UN ELEMENTO DE LA PILA

int desapilar(PILA S){
	int v;
      Nodo_Pila *  aux;
	if( es_vaciaPila(S)==TRUE){
		manejaMsg(3);  //PILA VACIA
		exit(0);
	}
	aux = S->tope;
        v = aux -> dato;
	S->tope = aux -> anterior;
        free(aux);
	return v;
}
