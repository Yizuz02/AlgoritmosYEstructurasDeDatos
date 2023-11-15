#include<stdio.h>
#include "pila.h"
#include<stdlib.h>

void menu(PILA);
void mostrarOpciones();
void manejaMsg(int);
Expediente leerExped();
void agregarExped(PILA);
void imprimirExped(Expediente);
void expedPorMes(PILA);
void expedPorFecha(PILA);
void liberarMem(PILA);

void main(){
	PILA P;
	int n;
}

void menu(PILA P){
    int op;
    do{
        mostrarOpciones();
        printf("Ingrese el numero de la accion que desea realizar: ");
        scanf("%d",&op);
        printf("\n");
        switch (op)
        {
        case 1:
			agregarExped(P); 
            break;
        case 2:
			expedPorMes(P);
            break;
        case 3:
			expedPorFecha(P);
            break;
        case 4:
            liberarMem(P);
            break;

        default:
            printf("¡Opcion no valida! Ingrese una opcion valida\n");
            break;
        }
    }while(op!=4);
}

void mostrarOpciones(){
    printf("\n\t\tPila de Expedientes\n\n");
    printf("1.- Agregar expediente\n");
    printf("2.- Imprimir expedientes por mes\n");
    printf("3.- Imprimir expedientes por fecha\n");
    printf("4.- Salir\n\n");
}

Expediente leerExped(){
	Expediente exp;
	printf("Ingrese los datos del expediente\n");
	printf("Numero: ");
	scanf("%d",&exp.numero);
	getchar();
	printf("Titular: ");
	scanf("%[^\n]",exp.titular);
	getchar();
	printf("Tramite: ");
	scanf("%[^\n]",exp.tramite);
	getchar();
	printf("Dia: ");
	scanf("%d",&exp.fecha.dia);
	getchar();
	printf("Mes: ");
	scanf("%d",&exp.fecha.mes);
	getchar();
	printf("Año: ");
	scanf("%d",&exp.fecha.año);
	getchar();
	return exp;
}

void agregarExped(PILA P){
	Expediente exp;
	int n;
	while(1){
		printf("Desea agregar un expediente a la pila? (1=Si 0=No)\n");
		scanf("%d",&n);
		if(n==0)
			break;
		exp = leerExped();
		apilar(P, exp);
	}
}

void imprimirExped(Expediente exp){
	printf("Numero: %d\n",exp.numero);
	printf("Titular: %s\n",exp.titular);
	printf("Tramite: %s\n",exp.tramite);
	printf("Dia: %d\n",exp.fecha.dia);
	printf("Mes: %d\n",exp.fecha.mes);
	printf("Año: %d\n",exp.fecha.año);
}

void expedPorMes(PILA P){
	PILA temp = crearPila();
	Expediente exp;
	int n;
	printf("Ingrese el numero del mes de los expedientes que desea imprimir\n");
	scanf("%d",&n);
	printf("Expedientes del mes %d\n", n);
	while(!es_vaciaPila(P)){
		exp = desapilar(P);
		apilar(temp, exp);
		if(exp.fecha.mes == n)
			imprimirExped(exp);
	}
	while(!es_vaciaPila(temp))
		apilar(P, desapilar(temp));
}

void expedPorFecha(PILA P){
	PILA temp = crearPila();
	Expediente exp;
	int d1,d2,m1,m2,a1,a2;
	printf("Ingrese la fecha inicial\n");
	printf("Dia: ");
	scanf("%d",&d1);
	printf("Mes: ");
	scanf("%d",&m1);
	printf("Año: ");
	scanf("%d",&a1);
	printf("Ingrese la fecha final\n");
	printf("Dia: ");
	scanf("%d",&d2);
	printf("Mes: ");
	scanf("%d",&m2);
	printf("Año: ");
	scanf("%d",&a2);
	printf("Expedientes del %d/%d/%d al %d/%d/%d\n",d1,m1,a1,d2,m2,a2);
	while(!es_vaciaPila(P)){
		exp = desapilar(P);
		apilar(temp, exp);
		if(exp.fecha.año >= a1 && exp.fecha.año <= a2){
			if(exp.fecha.mes >= m1 && exp.fecha.mes <= m2){
				if(exp.fecha.dia >= d1 && exp.fecha.dia <= d2)
					imprimirExped(exp);
			}
		}
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


