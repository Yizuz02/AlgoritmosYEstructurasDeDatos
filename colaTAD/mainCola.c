#include<stdio.h>
#include "cola.h"
#include<stdlib.h>

void manejaMsg(int);
COLA datosEntrada();
void mostrarCola(COLA);

void main(){
	COLA C;
	C=datosEntrada();
	mostrarCola(C);
	liberarCOLA(C);
}


COLA datosEntrada(){
	COLA C = crearCola();
	int n, op=0;
	do{
		printf("Ingrese el dato que desea agregar a la pila:\n");
		scanf("%d",&n);
		encolar(C, n);
		printf("Desea ingresar otro dato? (1 = Si / 0 = No)\n");
		scanf("%d",&op);
	}while(op!=0);
	return C;
}

void mostrarCola(COLA P){
	COLA temp = crearCola();
	int n;
	printf("Imprimiendo Cola: \n");
	while(!es_vaciaCola(P)){
		n = desencolar(P);
		printf("%d\n",n);
		encolar(temp, n);
	}
	while(!es_vaciaCola(temp)){
		encolar(P, desencolar(temp));
	}
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s", mensajes[msg] );
}