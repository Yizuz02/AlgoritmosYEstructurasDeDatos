#include<stdio.h>
#include "cola.h"
#include<stdlib.h>

void manejaMsg(int);
void datosEntrada(COLA);
void crearColas(COLA, COLA);
COLA mezclaCola(COLA, COLA);
void imprimirColas(COLA, COLA, COLA);
void mostrarCola(COLA);

void main(){
	COLA C1,C2,C3;
	C1 = crearCola();
	C2 = crearCola();
	crearColas(C1,C2);
	C3 = ponAlaCola(C1,C2);
	imprimirColas(C1,C2,C3);
	liberarCOLA(C1);
	liberarCOLA(C2);
	liberarCOLA(C3);
}

void crearColas(COLA C1, COLA C2){
	printf("Datos C1\n");
	datosEntrada(C1);
	printf("Datos C2\n");
	datosEntrada(C2);
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

void imprimirColas(COLA C1, COLA C2, COLA C3){
	printf("C1:\n");
	mostrarCola(C1);
	printf("C2:\n");
	mostrarCola(C2);
	printf("C3:\n");
	mostrarCola(C3);
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