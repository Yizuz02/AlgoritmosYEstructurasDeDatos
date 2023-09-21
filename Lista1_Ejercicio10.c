#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void darDim(int*);
int **crearMatriz(int);
double *crearArregloUni(int);
void darDatosMtz (int**, int);
void llenarArreglo(int**,int**,double*,int);
void mostrarMtz(int**, int);
void mostrar(double*, int);
void liberar(double*);
void liberarMtz(int**, int);
void Mensajes(int);


void main(){
	int n, **A, **B;
    double *C;
	darDim(&n);
	A = crearMatriz(n);
    B = crearMatriz(n);
    C = crearArregloUni(n);
	darDatosMtz(A, n);
    darDatosMtz(B, n);
    llenarArreglo(A,B,C,n);
	mostrarMtz(A, n);
    mostrarMtz(B, n);
    mostrar(C, n);
	liberarMtz(A, n);
    liberarMtz(B, n);
    liberar(C);
}

void darDim(int * n){
	printf("Indique el valor n para las matrices n*n: \n");
	scanf("%d", n);
}

int ** crearMatriz(int n){
	int ** mtz, i;
	mtz = (int**) malloc(n*sizeof(int*));
	if (mtz==NULL){
		Mensajes(0);
		exit(0);
	}
	for(i=0;i<n;i++)
		mtz[i] = (int*) malloc(n*sizeof(int));
		
	return mtz;
}

double *crearArregloUni(int elem){
	double * A;
	A = (double*) malloc(elem*sizeof(double));
	if(A==NULL){
		Mensajes(0);
		exit(0);
	}
	return A;
}

void darDatosMtz (int **mtz, int n){
	int i,j;
	
	printf("Ingrese los datos de la Matriz\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Dato[%d][%d]= ",i+1,j+1);
			scanf("%d",&mtz[i][j]);
		}
	}
}

void llenarArreglo(int** A, int** B, double * C, int n){
    int i,j,suma;
    double media,mayor,potencia;
    for(i=0;i<n;i++){
        suma=0;
        for(j=0;j<n;j++)
            suma+=A[j][i];
        media = suma/(n*1.00);
        mayor=B[i][0];
        potencia=i+0;
        for(j=1;j<n;j++){
            if(B[i][j]>mayor){
                mayor=B[i][j];
                potencia=i+j;
            }
        }
        C[i]=pow(media*mayor, potencia);
    }
}

void mostrarMtz(int **mtz, int n){
	int i,j;
	
	printf("Los datos de la Matriz son:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("\t%d",mtz[i][j]);
		printf("\n");
	}
}

void liberarMtz(int **mtz, int n){
	int i;
	
	for(i=0;i<n;i++)
		free(mtz[i]);
	free(mtz);
	
	Mensajes(1);
}

void mostrar(double *A, int elem){
	int i;
	printf("Los datos del arreglo son: \n");
	for(i=0;i<elem;i++)
		printf("C[%d] = %f\n",i+1,A[i]);
}

void liberar(double *A){
	free(A);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}