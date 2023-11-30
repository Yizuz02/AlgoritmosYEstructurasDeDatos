#include "Cola.h"
#include<stdio.h>
#include<stdlib.h>

COLA crearCola (){ 
    COLA C;
    C = (COLA)malloc(sizeof(Cola)); 
    if(C== NULL ){
        manejaMsg(0); 
        exit(0);
    }
    C -> primero = 0;
    C -> ultimo = 0;
    C -> tam = 0;
    return C;
}

int es_vaciaCola(COLA C){
    if( C -> tam ==0) 
        return TRUE; 
    else
        return FALSE; 
}

int sig (int i){
    int p; 
    p = (i + 1) % TAMCOLA; 
    return p;
}

void encolar (COLA C, Persona x){
    if( C -> tam == TAMCOLA){ 
        manejaMsg(3);
    }
    C->cola[C->ultimo] = x;
    C->ultimo = sig(C->ultimo);
    C->tam = C->tam+1;
}

Persona desencolar (COLA C){
    Persona v; 
    if(es_vaciaCola(C)==TRUE){
        manejaMsg(2);
        exit(0);
    }
    v = C->cola[C->primero]; 
    C->primero = sig(C->primero);
    C->tam=C->tam-1; 
    return v;
}


Persona primero(COLA C){
    Persona v;
    if( es_vaciaCola(C)==TRUE){
        manejaMsg(2);
        exit(0);
    }
    v = C->cola[C->primero]; 
    return v;
}

void liberarCOLA(COLA C){
    free(C);
    manejaMsg(1);
}
