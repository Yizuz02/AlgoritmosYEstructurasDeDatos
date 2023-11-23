#include<stdio.h>
#include "Cola.h"
#include<stdlib.h>

void manejaMsg(int);
COLA datosEntrada();
COLA intercambio(COLA);
void imprimir(COLA, COLA);
void mostrarCola(COLA);

void main(){
	COLA C1, C2;
	C1=datosEntrada();
	C2=intercambio(C1);
	imprimir(C1,C2);
	liberarCOLA(C1);
	liberarCOLA(C2);
}


COLA datosEntrada(){
	COLA C = crearCola();
	int n;
	char m;
	while (1){
		printf("Ingrese los dato que desea agregar a la pila (Enter para continuar)\n");
		scanf("%d",&n);
		m = getchar();
		encolar(C, n);
		if (m =='\n')
			break;
	}
	return C;
}

COLA intercambio(COLA C1){
	COLA C2 = crearCola();
	Cola temp = *C1;
	Cola temp2 = *C1;
	int n, p, m;
	p=desencolar(&temp2);
	desencolar(&temp);
	desencolar(&temp);
	while(!es_vaciaCola(&temp)){
		desencolar(&temp);
		encolar(&temp2, desencolar(&temp2));
	}
	encolar(&temp2, p);
	*C2 = temp2;
	return C2;
}

void imprimir(COLA C1, COLA C2){
	printf("Imprimiendo Cola Original: \n");
	mostrarCola(C1);
	printf("\nImprimiendo Cola Intercambio: \n");
	mostrarCola(C2);
	printf("\n");
}

void mostrarCola(COLA C){
	COLA temp = crearCola();
	int n;
	while(!es_vaciaCola(C)){
		n = desencolar(C);
		printf("%d ",n);
		encolar(temp, n);
	}
	while(!es_vaciaCola(temp)){
		encolar(C, desencolar(temp));
	}
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
	"La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s\n", mensajes[msg] );
}
