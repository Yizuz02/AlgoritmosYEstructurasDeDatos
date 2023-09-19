#include <stdio.h>
#include <stdlib.h>

void darDim(int*);
int **crearMatriz(int);
void darDatosMtz (int**, int);
int *crearArregloUni(int);
void asignarValores(int**,int*, int);
void mostrarMtz(int**, int);
void mostrar(int*, int);
void liberarMtz(int**, int);
void liberar(int*);
void Mensajes(int);

void main(){
    int n, **A, *B;
	darDim(&n);
	A = crearMatriz(n);
	darDatosMtz(A, n);
    B = crearArregloUni(n);
    asignarValores(A,B,n);
	mostrarMtz(A, n);
    mostrar(B, n);
	liberarMtz(A, n);
    liberar(B);
}

void darDim(int * n){
	printf("Indique la dimension de una matriz nxn: \n");
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

void darDatosMtz(int **mtz, int n){
	int i,j;
	
	printf("Ingrese los datos de la Matriz\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("Dato[%d][%d]= ",i+1,j+1);
			scanf("%d",&mtz[i][j]);
		}
	}
}

int *crearArregloUni(int n){
	int * A;
	A = (int*) malloc(n*sizeof(int));
	if(A==NULL){
		Mensajes(0);
		exit(0);
	}
	return A;
}

void asignarValores(int**A,int*B,int n){
    int i,k,sum;
	for(i=0;i<n;i++){
        B[i]=0;
        if(i%3==2){
            for(k=0;k<n;k++)
                B[i]+= A[i][k];
        } else if (i%3==1){
            for(k=i-1;k<n;k++)
               B[i]+= A[k][i];
        }
    }
}

void mostrarMtz(int **mtz, int n){
	int i,j;
	
	printf("Los datos de la Matriz A son:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			printf("\t%d",mtz[i][j]);
		printf("\n");
	}
}

void mostrar(int *A, int elem){
	int i;
	printf("Los datos del arreglo B son: \n");
	for(i=0;i<elem;i++)
		printf("A[%d] = %d\n",i+1,A[i]);
}

void liberarMtz(int **mtz, int n){
	int i;
	
	for(i=0;i<n;i++)
		free(mtz[i]);
	free(mtz);
	
	Mensajes(1);
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