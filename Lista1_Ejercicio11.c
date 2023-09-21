#include <stdio.h>
#include <stdlib.h>

void menu();
void mostrarOpciones();
void darDim(int*);
int *crearArregloUni(int);
void darDatos(int*, int);
void ordAsc(int*, int);
void ordDesc(int*, int);
void mostrar(int*, int);
void liberar(int*);
void Mensajes(int);

void main (){
	menu();
}

void menu(){
    int *A, n=0, op,exit=1;
    while(exit){
        mostrarOpciones();
        printf("Ingrese el numero de la accion que desea realizar: ");
        scanf("%d",&op);
        printf("\n");
        switch (op)
        {
        case 1:
            darDim(&n);
            A = crearArregloUni(n);
            break;
        
        case 2:
            if(n!=0){
                darDatos(A, n);
            } else {
                printf("¡Vector no creado! Ingrese primero el tamaño del vector\n");
            }
            break;
        case 3:
            if(n!=0){
                ordAsc(A, n);
            } else {
                printf("¡Vector no creado! Ingrese primero el tamaño del vector\n");
            }
            break;
        case 4:
            if(n!=0){
                ordDesc(A, n);
            } else {
                printf("¡Vector no creado! Ingrese primero el tamaño del vector\n");
            }
            break;
        case 5:
            if(n!=0){
                mostrar(A, n);
            } else {
                printf("¡Vector no creado! Ingrese primero el tamaño del vector\n");
            }
            break;
        case 6:
            exit=0;
            liberar(A);
            break;

        default:
            printf("¡Opcion no valida! Ingrese una opcion valida\n");
            break;
        }
    }
}

void mostrarOpciones(){
    printf("\n\t\tLaboratorio de Vectores\n\n");
    printf("1.- Ingresar tamaño del vector\n");
    printf("2.- Ingresar elementos del vector\n");
    printf("3.- Ordenar ascendentemente el vector\n");
    printf("4.- Ordenar descendentemente el vector\n");
    printf("5.- Mostrar elementos del vector\n");
    printf("6.- Salir\n\n");
}

void darDim(int* elem){
	printf("Dar la dimensión del arreglo \n");
	scanf("%d", elem);
}

int *crearArregloUni(int elem){
	int * A;
	A = (int*) malloc(elem*sizeof(int));
	if(A==NULL){
		Mensajes(0);
		exit(0);
	}
	return A;
}

void darDatos(int *A, int elem){
	int i;
	printf("Ingrese los datos del arreglo\n");
	for(i=0; i<elem;i++){
		printf("A[%d]= ",i+1);
		scanf("%d",&A[i]);
	}
}

void ordAsc(int *A, int elem){
    int i,j,t;
    for (i=1;i<elem;i++){
        j=i-1;
        t=A[i];
        while(j>=0 && t<A[j]){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=t;
    }
    printf("Elementos ordenados correctamente\n");
}

void ordDesc(int *A, int elem){
    int i,j,t;
    for (i=1;i<elem;i++){
        j=i-1;
        t=A[i];
        while(j>=0 && t>A[j]){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=t;
    }
    printf("Elementos ordenados correctamente\n");
}

void mostrar(int *A, int elem){
	int i;
	printf("Los datos del arreglo son: \n");
	for(i=0;i<elem;i++)
		printf("A[%d] = %d\n",i+1,A[i]);
}

void liberar(int *A){
	free(A);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}