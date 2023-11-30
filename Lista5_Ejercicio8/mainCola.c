#include<stdio.h>
#include "cola.h"
#include<stdlib.h>

void manejaMsg(int);
void leerDatos(COLA);
void crearColas(COLA, COLA);
COLA interseccion(COLA, COLA);
void mostrarCola(COLA);

void main(){
	COLA C1,C2,C3;
	C1 = crearCola();
	C2 = crearCola();
	crearColas(C1,C2);
	C3 = interseccion(C1,C2);
	mostrarCola(C3);
	liberarCOLA(C1);
	liberarCOLA(C2);
	liberarCOLA(C3);
}

void crearColas(COLA C1, COLA C2){
	printf("Datos C1\n");
	leerDatos(C1);
	printf("Datos C2\n");
	leerDatos(C2);
}

void leerDatos(COLA C){
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

COLA interseccion(COLA C1, COLA C2){
	COLA C3 = crearCola();
	Cola temp;
	int n, m;
	while(!es_vaciaCola(C1)){
		n=desencolar(C1);
		temp=*C2;
		while (!es_vaciaCola(&temp)){
			if(desencolar(&temp)==n){
				encolar(C3,n);
				break;
			}
		}	
	}
	return C3;
}

void mostrarCola(COLA C){
	Cola temp = *C;
	int n;
	printf("Cola Intersección: \n");
	while(!es_vaciaCola(&temp))
		printf("%d ",desencolar(&temp));
	printf("\n");
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s\n", mensajes[msg] );
}