#include<stdio.h>
#include "cola.h"
#include<stdlib.h>

void manejaMsg(int);
void datosEntrada(COLA);
void crearColas(COLA, COLA, COLA, COLA);
COLA agrupaColas(COLA, COLA, COLA, COLA);
COLA mezclaCola(COLA, COLA);
void imprimirColas(COLA, COLA, COLA, COLA, COLA);
void mostrarCola(COLA);

void main(){
	COLA C1,C2,C3,C4,C5;
	C1 = crearCola();
	C2 = crearCola();
	C3 = crearCola();
	C4 = crearCola();
	crearColas(C1,C2,C3,C4);
	C5 = agrupaColas(C1,C2,C3,C4);
	imprimirColas(C1,C2,C3,C4,C5);
	liberarCOLA(C1);
	liberarCOLA(C2);
	liberarCOLA(C3);
	liberarCOLA(C4);
	liberarCOLA(C5);
}

void crearColas(COLA C1, COLA C2, COLA C3, COLA C4){
	printf("Datos C1\n");
	datosEntrada(C1);
	printf("Datos C2\n");
	datosEntrada(C2);
	printf("Datos C3\n");
	datosEntrada(C3);
	printf("Datos C4\n");
	datosEntrada(C4);
}

void datosEntrada(COLA C){
	int n;
    char m;
	printf("Ingrese los datos que desea agregar a la pila (Enter para continuar)\n");
	while (1){
		scanf("%d",&n);
		m = getchar();
		encolar(C, n);
		if (m =='\n')
			break;
	}
}

COLA agrupaColas(COLA C1, COLA C2, COLA C3, COLA C4){
	COLA C5 = mezclaCola(C1,C2);
	C5 = mezclaCola(C5,C3);
	C5 = mezclaCola(C5,C4);
	return C5;
}

COLA mezclaCola(COLA C1, COLA C2){
	COLA C3 = crearCola();
	Cola temp1 = *C1;
	Cola temp2 = *C2;
	int n;
	while(!es_vaciaCola(&temp1)&&!es_vaciaCola(&temp2)){
		encolar(C3, desencolar(&temp1));
		encolar(C3, desencolar(&temp2));
	}
	while(!es_vaciaCola(&temp1))
			encolar(C3, desencolar(&temp1));
	while(!es_vaciaCola(&temp2))
			encolar(C3, desencolar(&temp2));
	return C3;
}

void imprimirColas(COLA C1, COLA C2, COLA C3, COLA C4, COLA C5){
	printf("C1:\n");
	mostrarCola(C1);
	printf("C2:\n");
	mostrarCola(C2);
	printf("C3:\n");
	mostrarCola(C3);
	printf("C4:\n");
	mostrarCola(C4);
	printf("C5:\n");
	mostrarCola(C5);
}

void mostrarCola(COLA C){
	Cola temp = *C;
	int n;
	while(!es_vaciaCola(&temp))
		printf("%d ",desencolar(&temp));
	printf("\n");
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s\n", mensajes[msg] );
}