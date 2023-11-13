#include<stdio.h>
#include "pila.h"
#include<stdlib.h>

void menu(PILA, PILA);
void mostrarOpciones();
void manejaMsg(int);
PILA datosEntrada();
PILA copiarFila(PILA);
int elemFondo(PILA);
int numElem(PILA);
void mostrarPila(PILA);
void liberarMem(PILA);

void main(){
	PILA P, copyP;
	P=datosEntrada();
	menu(P, copyP);
	mostrarPila(P);
	liberarMem(P);
}

void menu(PILA P, PILA copyP){
    int op;
    do{
        mostrarOpciones();
        printf("Ingrese el numero de la accion que desea realizar: ");
        scanf("%d",&op);
        printf("\n");
        switch (op)
        {
        case 1:
            printf("La pila tiene %d elementos\n",numElem(P));
            break;
        
        case 2:
			printf("El elemento al fondo de la pila es %d\n",elemFondo(P));
            break;
        case 3:
			copyP = copiarFila(P);
			printf("Se ha copiado correctamente la Pila\n");
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
    printf("\n\t\tMenu Pilas\n\n");
    printf("1.- Numero de elementos\n");
    printf("2.- Elemento del fondo\n");
    printf("3.- Copiar Pila\n");
    printf("4.- Salir\n\n");
}

PILA datosEntrada(){
	PILA P = crearPila();
	int n, op=0;
	char m;
	printf("Ingrese los datos que desea agregar a la pila:\n");
	while(1){
		scanf("%d",&n);
		apilar(P, n);
		m = getchar();
		if (m =='\n')
			break;
	}
	return P;
}

PILA copiarFila(PILA P){
	PILA temp = crearPila();
	PILA C = crearPila();
	int n, sum=0;
	while(!es_vaciaPila(P)){
		n = desapilar(P);
		sum++;
		apilar(temp, n);
	}
	printf("\n");
	while(!es_vaciaPila(temp)){
		n= desapilar(temp);
		apilar(P, n);
		apilar(C, n);
	}
	return C;
}

int elemFondo(PILA P){
	PILA temp = crearPila();
	int n;
	while(!es_vaciaPila(P)){
		n = desapilar(P);
		apilar(temp, n);
	}
	printf("\n");
	while(!es_vaciaPila(temp))
		apilar(P, desapilar(temp));
	return n;
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
	int n;
	while(!es_vaciaPila(P)){
		n = desapilar(P);
		printf("%c",n);
		apilar(temp, n);
	}
	printf("\n");
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


