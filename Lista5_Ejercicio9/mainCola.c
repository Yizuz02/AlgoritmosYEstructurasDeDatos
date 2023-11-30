#include<stdio.h>
#include "cola.h"
#include<stdlib.h>
#include <time.h>

void manejaMsg(int);
void leerDatos(COLA);
Cliente crearCliente();
COLA colaMayores(COLA);
float promedio(COLA);
void mostrarCola(COLA);
void imprimirCliente(Cliente);

void main(){
	COLA C,CMayor;
	C = crearCola();
	leerDatos(C);
	CMayor = colaMayores(C);
	mostrarCola(CMayor);
	liberarCOLA(C);
	liberarCOLA(CMayor);
}

void leerDatos(COLA C){
	Cliente n;
	int op;
	do{
		printf("Ingrese los datos del cliente\n");
		n=crearCliente();
		encolar(C, n);
		printf("Desea ingresar otro cliente al registro? (1=Si 0=No)\n");
		scanf("%d",&op);
		getchar();
	} while (op!=0);
}

Cliente crearCliente(){
	Cliente n;
	printf("Numero de cliente: ");
	scanf("%d",&n.num_cliente);
	getchar();
	printf("Nombre: ");
	scanf("%[^\n]",n.nombre);
	getchar();
	printf("Estado (1 = Activo / 0 = No Activo): ");
	scanf("%d",&n.estado);
	getchar();
	printf("Monto: ");
	scanf("%f",&n.monto);
	getchar();
	return n;
}

float promedio(COLA C){
	Cola temp= *C;
	float sum=0,num=0;
	while(!es_vaciaCola(&temp)){
		sum+=desencolar(&temp).monto;
		num++;
	}
	return sum/num;
}

COLA colaMayores(COLA C){
	COLA C2 = crearCola();
	float prom = promedio(C);
	Cliente n;
	while(!es_vaciaCola(C)){
		n=desencolar(C);
		if(n.monto>prom)
			encolar(C2,n);
	}
	return C2;
}

void mostrarCola(COLA C){
	Cola temp = *C;
	int n;
	while(!es_vaciaCola(&temp))
		imprimirCliente(desencolar(&temp));
	printf("\n");
}

void imprimirCliente(Cliente n){
	printf("Numero de Cliente: %d\n",n.num_cliente);
	printf("Nombre: %s\n",n.nombre);
	printf("Estado: ");
	if(n.estado==1)
		printf("Activo\n");
	else
		printf("Inactivo\n");
	printf("Monto Deposito: %.2f\n",n.monto);
	printf("\n");
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s\n", mensajes[msg] );
}