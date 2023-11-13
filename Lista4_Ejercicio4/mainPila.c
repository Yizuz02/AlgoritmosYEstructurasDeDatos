#include<stdio.h>
#include "pila.h"
#include<stdlib.h>

void manejaMsg(int);
PILA leerCadena();
int checaParentesis(PILA);
void mostrarPila(PILA);
void liberarMem(PILA);

void main(){
	PILA P;
	P=leerCadena();
	mostrarPila(P);
	liberarMem(P);
}


PILA leerCadena(){
	PILA P = crearPila();
	int n, op=0;
	printf("Ingrese la cadena (Presiona ENTER para guardar):\n");
	while(1){
		n=getchar();
		if(n=='\n')
			break;
		apilar(P, n);
	}
	return P;
}

int checaParentesis(PILA P){
	PILA aux = crearPila();
	int n;
	char c;
	while(!es_vaciaPila(P)){
		c=desapilar(P);
		if (c ==')')
			apilar(aux, ')');
		else if (c =='('){
			if(es_vaciaPila(aux))
				return 0;
			else
				desapilar(aux);
		}
	}
	return es_vaciaPila(aux);
}

void mostrarPila(PILA P){
	PILA temp = crearPila();
	int n;
	while(!es_vaciaPila(P)){
		n = desapilar(P);
		printf("%c",n);
		apilar(temp, n);
	}
	printf("\n");
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


