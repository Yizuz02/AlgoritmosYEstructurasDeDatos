#include<stdio.h>
#include "pila.h"
#include<stdlib.h>

void manejaMsg(int);
PILA leeTexto();
void analizaTexto(PILA);
void mostrarTexto(PILA);
void liberarMem(PILA);

void main(){
	PILA P;
	P=leeTexto();
	analizaTexto(P);
	mostrarTexto(P);
	liberarMem(P);
}

PILA leeTexto(){
	PILA P = crearPila();
	int n;
	char m;
	printf("Ingrese los datos que desea agregar a la pila:\n");
	while(1){
		m = getchar();
		if (m =='\n')
			break;
		apilar(P, m);
	}
	return P;
}

void analizaTexto(PILA P){
	PILA temp = crearPila();
	char n;
	int sum=0, elem=0;
	while(!es_vaciaPila(P)){
		n = desapilar(P);
		if(n=='#')
			sum++;
		else if(n=='@')
			elem = 1;
		else if(sum==0 && elem==0)
			apilar(temp, n);
		else
			sum--;
	}
	while(!es_vaciaPila(temp)){
		n= desapilar(temp);
		apilar(P, n);
	}
}

void mostrarTexto(PILA P){
	PILA temp = crearPila();
	int n;
	while(!es_vaciaPila(P))
		apilar(temp, desapilar(P));
	printf("\n");
	while(!es_vaciaPila(temp)){
		n = desapilar(temp);
		printf("%c",n);
		apilar(P, n);
	}
	printf("\n");
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","La Pila esta llena . . .","La Pila esta vacia . . ."};
	printf("%s", mensajes[msg] );
}

void liberarMem(PILA P){
	free(P);
	manejaMsg(1);
}


