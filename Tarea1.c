#include <stdio.h>
#include <stdlib.h>

void darDim(int*);
int **crearMatriz(int, int);
void darDatosMtz (int**, int, int);
int *crearArregloUni(int);
void llenarProdDiag(int**, int*, int, int);
void mostrarMtz(int**, int, int);
void mostrar(int*, int);
void liberarMtz(int**, int);
void liberar(int*);
void Mensajes(int);

void main(){
	int **A, *diagP, *diagS, n;
	
	darDim(&n);
	A = crearMatriz(n, n);
	darDatosMtz(A, n, n);
	diagP = crearArregloUni(n);
	diagS = crearArregloUni(n);
	llenarProdDiag(A, diagP, n, 0);
	llenarProdDiag(A, diagS, n, 1);
	mostrarMtz(A, n, n);
	mostrar(diagP, n);
	mostrar(diagS, n);
	liberarMtz(A, n);
	liberar(diagP);
	liberar(diagS);
}

void darDim(int* elem){
	printf("Dar la dimensión de la matriz cuadrada: \n");
	scanf("%d", elem);
}

int ** crearMatriz(int fil, int col){
	int ** mtz, i;
	mtz = (int**) malloc(fil*sizeof(int*));
	if (mtz==NULL){
		Mensajes(0);
		exit(0);
	}
	for(i=0;i<fil;i++)
		mtz[i] = (int*) malloc(col*sizeof(int));
		
	return mtz;
}

void darDatosMtz (int **mtz, int fil, int col){
	int i,j;
	
	printf("Ingrese los datos de la Matriz\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			printf("Dato[%d][%d]= ",i+1,j+1);
			scanf("%d",&mtz[i][j]);
		}
	}
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

void llenarProdDiag(int **mtz, int *arr, int n, int s){
	int prod, z;
	if (s==0){
		for (int i = 0; i<n; i++){
			prod = 1;
			z = 0;
			for(int j=0; j<n-i;j++){
				prod *= mtz[j+i][z++];
			
			}
			arr[i] = prod;
		}
	} else {
		for (int i = 0; i<n; i++){
			prod = 1;
			z = 0;
			for(int j=n-1; j>=i;j--){
				prod *= mtz[z++][j-i];
			
			}
			arr[i] = prod;
		}
	}
	
}

void mostrarMtz(int **mtz, int fil, int col){
	int i,j;
	
	printf("Los datos de la Matriz son:\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++)
			printf("\t%d",mtz[i][j]);
		printf("\n");
	}
}

void mostrar(int *A, int elem){
	int i;
	printf("Los datos del arreglo son: \n");
	for(i=0;i<elem;i++)
		printf("A[%d] = %d\n",i+1,A[i]);
}

void liberarMtz(int **mtz, int fil){
	int i;
	
	for(i=0;i<fil;i++)
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


