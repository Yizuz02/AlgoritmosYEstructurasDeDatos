#include<stdio.h>
#include "cola.h"
#include<stdlib.h>

void menu(COLA);
void mostrarOpciones();
void manejaMsg(int);
COLA datosEntrada();
void agregarDato(COLA);
void ultimoElemento(COLA);
void mostrarCola(COLA);

void main(){
	COLA C;
	C=datosEntrada();
	menu(C);
}

void menu(COLA C){
    int op;
    do{
        mostrarOpciones();
        printf("Ingrese el numero de la accion que desea realizar: ");
        scanf("%d",&op);
        printf("\n");
        switch (op)
        {
        case 1:
			agregarDato(C);
            break;
        case 2:
			ultimoElemento(C);
            break;
        case 3:
			mostrarCola(C);
            break;
        case 4:
            liberarCOLA(C);
            break;

        default:
            printf("¡Opcion no valida! Ingrese una opcion valida\n");
            break;
        }
    }while(op!=4);
}

void mostrarOpciones(){
    printf("\n\t\tColas\n\n");
    printf("1.- Introducir elementos a cola\n");
    printf("2.- Ultimo elemento de la cola\n");
    printf("3.- Imprimir elementos de la cola\n");
    printf("4.- Salir\n\n");
}

COLA datosEntrada(){
	COLA C = crearCola();
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
	return C;
}

void agregarDato(COLA C){
	int op, n;
	while (1){
		printf("Desea ingresar un dato a la cola? (Si=1/No=0)\n");
		scanf("%d",&op);
		if (!op)
			break;
		printf("Ingrese el dato que desea agregar a la cola:\n");
		scanf("%d",&n);
		encolar(C, n);
	}
}

void ultimoElemento(COLA C){
	Cola temp = *C;
	int n;
	while(!es_vaciaCola(&temp))
		n=desencolar(&temp);
	printf("El ultimo elemento de la cola es: %d\n",n);
}

void mostrarCola(COLA C){
	Cola temp = *C;
	int n;
	printf("Imprimiendo Cola: \n");
	while(!es_vaciaCola(&temp))
		printf("%d ",desencolar(&temp));
	printf("\n");
}

void manejaMsg(int msg){
	char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  ",
    "La Pila esta llena . . .","La Pila esta vacia . . .","Cola Vacia","Cola LLena","Cola liberada"};
	printf("%s", mensajes[msg] );
}