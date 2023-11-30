#include<stdio.h>
#include "cola.h"
#include "pila.h"
#include<stdlib.h>

void manejaMsg(int);
void leerDato(int*);
int comprobar(int);
void imprimirNum(int);

void main(){
	int n;
	leerDato(&n);
	imprimirNum(n);
}

void leerDato(int * n){
	printf("Ingrese un numero:\n");
	scanf("%d",n);
}

int comprobar(int n){
	COLA C = crearCola();
	PILA P = crearPila();
	int div=1,digito,m;
	while(n){
		m=n%(div*10);
		digito=m/div;
		n-=m;
		encolar(C,digito);
		apilar(P,digito);
		div*=10;
	}
	while (!es_vaciaCola(C)){
		if(desapilar(P)!=desencolar(C))
			return 0;
	}
	return 1;
}

void imprimirNum(int n){
	printf("El numero %d ",n);
	if(comprobar(n))
		printf("es un capicua\n");
	else
		printf("no es un capicua\n");
}


void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s\n", mensajes[msg] );
}