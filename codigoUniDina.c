#include <stdio.h>
#include <stdlib.h>

void darDim(int*);
int *crearArregloUni(int);
void darDatos(int*, int);
void mostrar(int*, int);
void liberar(int*);
void Mensajes(int);

void main (){
	int *A, elem;
	
	darDim(&elem);
	A = crearArregloUni(elem);
	darDatos(A, elem);
	mostrar(A, elem);
	liberar(A);
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
		printf("\nA[%d]= ",i+1);
		scanf("%d",&A[i]);
	}
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
