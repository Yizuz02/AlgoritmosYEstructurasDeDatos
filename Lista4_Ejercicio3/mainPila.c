#include<stdio.h>
#include "pila.h"
#include<stdlib.h>

void manejaMsg(int);
PILA leerExpresion();
int checaParentesis(PILA);
void mostrar(PILA);
void mostrarPila(PILA);
void liberarMem(PILA);

void main(){
	PILA P;
	P=leerExpresion();
	mostrar(P);
	liberarMem(P);
}


PILA leerExpresion(){
	PILA P = crearPila();
	int n, op=0;
	printf("Ingrese la expresion (Presiona ENTER para guardar):\n");
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

void mostrar(PILA P){
	printf("Los parentesis de la expresion ");
	mostrarPila(P);
	if(checaParentesis(P))
		printf(" estan equilibrados.\n");
	else
		printf(" no estan equilibrados.\n");
}

void mostrarPila(PILA P){
	PILA temp = crearPila();
	int n;
	while(!es_vaciaPila(P))
		apilar(temp, desapilar(P));
	while(!es_vaciaPila(temp)){
		n = desapilar(temp);
		printf("%c",n);
		apilar(P, n);
	}
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ","La Pila esta llena . . .","La Pila esta vacia . . ."};
	printf("%s", mensajes[msg] );
}

void liberarMem(PILA P){
	free(P);
	manejaMsg(1);
}


