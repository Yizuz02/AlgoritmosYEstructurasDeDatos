#include<stdio.h>
#include "cola.h"
#include<stdlib.h>
#include <time.h>

void manejaMsg(int);
void leerDatos(COLA);
Persona crearPersona();
COLA asignaTicket(COLA);
void colaNoColados(COLA, COLA, COLA);
void imprimirColas(COLA, COLA);
void mostrarCola(COLA);
void imprimirPersona(Persona);

void main(){
	srand (time(NULL)); 
	COLA C,noColados,colados;
	C = crearCola();
	noColados = crearCola();
	colados = crearCola();
	leerDatos(C);
	C = asignaTicket(C);
	colaNoColados(C,noColados,colados);
	imprimirColas(noColados,colados);
	liberarCOLA(C);
	liberarCOLA(noColados);
	liberarCOLA(colados);
}

void leerDatos(COLA C){
	Persona n;
	int op;
	do{
		printf("Ingrese los datos de la persona\n");
		n=crearPersona();
		encolar(C, n);
		printf("Desea ingresar una persona a la cola? (1=Si 0=No)\n");
		scanf("%d",&op);
		getchar();
	} while (op!=0);
}

Persona crearPersona(){
	Persona n;
	printf("Nombre: ");
	scanf("%[^\n]",n.nombre);
	getchar();
	printf("Sexo (M/F): ");
	scanf("%c",&n.sexo);
	getchar();
	printf("Edad: ");
	scanf("%d",&n.edad);
	getchar();
	return n;
}

COLA asignaTicket(COLA C){
	COLA temp = crearCola();
	Persona n;
	while (!es_vaciaCola(C)){
		n = desencolar(C);
		printf("%d\n",n.ticket);
		if (n.ticket)
			n.atencion = rand()%5+1;
		else
			n.atencion = 0;
		encolar(temp,n);
	}
	return temp;
}

void colaNoColados(COLA C, COLA noColados, COLA colados){
	Persona n, temp;
	Cola contador;
	while(!es_vaciaCola(C)){
		n= desencolar(C);
		if(n.ticket==0)
			encolar(colados,n);
		else{
			if(es_vaciaCola(noColados))
				encolar(noColados,n);
			else{
				contador = *noColados;
				while(!es_vaciaCola(&contador)){
					desencolar(&contador);
					temp=desencolar(noColados);
					if(temp.atencion >= n.atencion){
						encolar(noColados,temp);
						if(es_vaciaCola(&contador))
							encolar(noColados,n);
					}else{
						encolar(noColados,n);
						n=temp;
					}
				}
			}
		}
	}
}

void imprimirColas(COLA C1, COLA C2){
	printf("No colados:\n\n");
	mostrarCola(C1);
	printf("Colados:\n\n");
	mostrarCola(C2);
}

void mostrarCola(COLA C){
	Cola temp = *C;
	int n;
	while(!es_vaciaCola(&temp))
		imprimirPersona(desencolar(&temp));
	printf("\n");
}

void imprimirPersona(Persona n){
	printf("Nombre: %s\n",n.nombre);
	printf("Sexo: ");
	if(n.sexo=='M')
		printf("Masculino\n");
	else if (n.sexo=='F')
		printf("Femenino\n");
	else
		printf("Otro\n");
	printf("Edad: %d\n",n.edad);
	printf("Ticket: ");
	if(n.ticket){
		printf("Si\n");
		printf("Atencion: %d\n",n.atencion);
	}
	else
		printf("No\n");
	printf("\n");
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s\n", mensajes[msg] );
}