#include<stdio.h>
#include "pila.h"
#include<stdlib.h>
#include<string.h>

void menu(PILA);
void mostrarOpciones();
void manejaMsg(int);
void agregarElem(PILA);
void elimElem(PILA);
int numElem(PILA);
void mostrarPila(PILA);
void liberarMem(PILA);

void main(){
	PILA P;
	P = crearPila();
	menu(P);
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
			if(numElem(P)<10)
				agregarElem(P);
			else
				printf("Cesto lleno\n");
            break;
        
        case 2:
			elimElem(P);
            break;
        case 3:
			mostrarPila(P);
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
    printf("\n\t\tCesta\n\n");
    printf("1.- Introducir elemento a la cesta\n");
    printf("2.- Sacar elemento de la cesta\n");
    printf("3.- Imprimir elemento de la cesta\n");
    printf("4.- Salir\n\n");
}

void agregarElem(PILA P){
	char n[25];
	getchar();
	printf("Ingrese el producto a agregar a la cesta:\n");
	scanf("%[^\n]",&n);
	printf("Se agrego %s al cesto\n",n);
	apilar(P, n);
}


void elimElem(PILA P){
	char n[25];
	if(!es_vaciaPila(P)){
		strcpy(n, desapilar(P));
		printf("Se elimino %s de la cesta\n", n);
	} else
		printf("El cesto esta vacio\n");
}

int numElem(PILA P){
	PILA temp = crearPila();
	int sum=0;
	while(!es_vaciaPila(P)){
		sum++;
		apilar(temp, desapilar(P));
	}
	printf("\n");
	while(!es_vaciaPila(temp))
		apilar(P, desapilar(temp));
	return sum;
}

void mostrarPila(PILA P){
	PILA temp = crearPila();
	char n[25];
	printf("Cesto de Compras: \n");
	while(!es_vaciaPila(P)){
		strcpy(n, desapilar(P));
		printf("%s\n",n);
		apilar(temp, n);
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


