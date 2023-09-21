#include <stdio.h>
#include <stdlib.h>

int *crearVector();
void darDatos(int*, char);
void productoVectorial(int*, int*, int*);
void imprimirVectores(int*,int*,int*);
void mostrar(int*);
void liberar(int*);
void Mensajes(int);

void main(){
    int *A, *B, *C, volumen;

    A = crearVector();
    B = crearVector();
    C = crearVector();
    darDatos(A, 'A');
    darDatos(B, 'B');
    productoVectorial(A, B, C);
    imprimirVectores(A, B, C);
    liberar(A);
    liberar(B);
    liberar(C);

}

int *crearVector(){
    int * vec;
	vec = (int*) malloc(3*sizeof(int));
	if(vec==NULL){
		Mensajes(0);
		exit(0);
	}
	return vec;
}

void darDatos(int *vec, char num){
	int i;
	printf("Ingrese los datos del vector %c\n", num);
	for(i=0; i<3;i++){
		printf("%c[%c]= ",num,i+'x');
		scanf("%d",&vec[i]);
	}
}

void productoVectorial(int * A, int * B , int * C){
    C[0] = (A[1]*B[2]) - (A[2]*B[1]);
    C[1] = -(A[0]*B[2]) + (A[2]*B[0]);
    C[2] = (A[0]*B[1]) - (A[1]*B[0]);
}

void imprimirVectores(int * A, int * B, int * C){
    printf("Los datos del arreglo A son: \n");
    mostrar(A);
    printf("Los datos del arreglo B son: \n");
    mostrar(B);
    printf("Los datos del arreglo A x B son: \n");
    mostrar(C);
}

void mostrar(int *A){
    printf("[%d, %d, %d]\n",A[0],A[1],A[2]);
}

void liberar(int *vec){
	free(vec);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}