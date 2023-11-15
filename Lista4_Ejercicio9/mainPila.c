#include<stdio.h>
#include "pila.h"
#include<stdlib.h>

void manejaMsg(int);
void darEntero(int *);
PILA convHexa(PILA, int);
void imprimirNum(PILA, int);
void mostrarPila(PILA);
void liberarMem(PILA);

void main(){
	PILA P = crearPila();
	int n;
	darEntero(&n);
	P = convHexa(P,n);
	imprimirNum(P,n);
	liberarMem(P);
}

void darEntero(int * n){
	printf("Ingrese el numero:\n");
	scanf("%d",n);
}

PILA convHexa(PILA P, int n){
	if(n==0)
		return P;
	apilar(P,n%16);
	return convHexa(P, n/16);
}

void imprimirNum(PILA P, int n){
	printf("El numero en decimal: %d\n",n);
	printf("El numero en hexadecimal: ",n);
	mostrarPila(P);
	printf("\n");
}

void mostrarPila(PILA P){
	PILA temp = crearPila();
	int n;
	char hexa[] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	while(!es_vaciaPila(P)){
		n = desapilar(P);
		printf("%c",hexa[n]);
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


