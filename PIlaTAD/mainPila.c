#include<stdio.h>
#include "pila.h"
#include<stdlib.h>

void manejaMsg(int);
PILA datosEntrada();
void mostrarPila(PILA);
void liberarMem(PILA);

void main(){
	PILA P;
	P=datosEntrada();
	mostrarPila(P);
	liberarMem(P);
}


PILA datosEntrada(){
	PILA P = crearPila();
	int n, op=0;
	do{
		printf("Ingrese el dato que desea agregar a la pila:\n");
		scanf("%d",&n);
		apilar(P, n);
		printf("Desea ingresar otro dato? (1 = Si / 0 = No)\n");
		scanf("%d",&op);
	}while(op!=0);
	return P;
}

void mostrarPila(PILA P){
	PILA temp = crearPila();
	int n;
	printf("Imprimiendo Pila: \n");
	while(!es_vaciaPila(P)){
		n = desapilar(P);
		printf("%d\n",n);
		apilar(temp, n);
	}
	while(!es_vaciaPila(temp))
		apilar(P, desapilar(temp));
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","La Pila esta llena . . .","La Pila esta vacia . . ."};
	printf("%s", mensajes[msg] );
}

void liberarMem(PILA P){
	free(P);
	manejaMsg(1);
}


