#include<stdio.h>
#include "pilaDina.h"
#include<stdlib.h>

void manejaMsg(int);
void leerDato(int*);
PILA conversion(int);
void imprimirNum(int, PILA);
void liberarMem(PILA);

void main(){
	PILA hexa;
	int n;
	leerDato(&n);
	hexa = conversion(n);
	imprimirNum(n,hexa);
	liberarMem(hexa);
}

void leerDato(int * n){
	printf("Ingrese un numero:\n");
	scanf("%d",n);
}

PILA conversion(int n){
	PILA P = crearPila();
	int digito;
	do{
		digito=n%16;
		n/=16;
		apilar(P,digito);
	}while(n);
	return P;
}

void imprimirNum(int n, PILA hexa){
	int dig;
	printf("Numero decimal: %d\n",n);
	printf("Numero hexadecimal: ");
	while(!es_vaciaPila(hexa)){
		dig=desapilar(hexa);
		if(dig<10)
			printf("%d",dig);
		else
			printf("%c",dig+55);
	}
	printf("\n");
}

void liberarMem(PILA P){
	free(P);
	manejaMsg(1);
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s\n", mensajes[msg] );
}
