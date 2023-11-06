#include<stdio.h>
#include "pila.h"
#include<stdlib.h>

void manejaMsg(int);
PILA datosEntrada(char);
PILA sumarPilas(PILA, PILA);
void imprimirPilas(PILA, PILA, PILA);
void mostrarPila(PILA);
void liberarMem(PILA);

void main(){
	PILA A, B, C;
	A = datosEntrada('A');
	B = datosEntrada('B');
	C = sumarPilas(A,B);
	imprimirPilas(A,B,C);
	liberarMem(A);
	liberarMem(B);
	liberarMem(C);
}


PILA datosEntrada(char m){
	PILA P = crearPila();
	int n, op=0;
	printf("Pila %c\n",m);
	do{
		printf("Ingrese el dato que desea agregar a la pila:\n");
		scanf("%d",&n);
		apilar(P, n);
		printf("Desea ingresar otro dato? (1 = Si / 0 = No)\n");
		scanf("%d",&op);
	}while(op!=0);
	return P;
}

PILA sumarPilas(PILA A, PILA B){
	PILA C = crearPila();
	int a, b;
	PILA tempA = crearPila();
	PILA tempB = crearPila();
	while(!es_vaciaPila(A) && !es_vaciaPila(B)){
		a = desapilar(A);
		b = desapilar(B);
		apilar(C, a+b);
		apilar(tempA, a);
		apilar(tempB, b);
	}
	while(!es_vaciaPila(tempA)){
		apilar(A, desapilar(tempA));
		apilar(B, desapilar(tempB));
	}
	return C;
}

void imprimirPilas(PILA A, PILA B, PILA C){
	PILA tempA = crearPila();
	PILA tempB = crearPila();
	while(!es_vaciaPila(A))
		apilar(tempA, desapilar(A));
	printf("Pila A: ");
	mostrarPila(tempA);
	while(!es_vaciaPila(B))
		apilar(tempB, desapilar(B));
	printf("Pila B: ");
	mostrarPila(tempB);
	printf("Pila C: ");
	mostrarPila(C);
}

void mostrarPila(PILA P){
	PILA temp = crearPila();
	int n;
	while(1){
		n = desapilar(P);
		printf("%d",n);
		apilar(temp, n);
		if(es_vaciaPila(P)){
			printf("\n");
			break;
		}
		printf(", ");
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


