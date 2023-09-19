#include <stdio.h>
#include <stdlib.h>

void darDim(int*, int*);
int **crearMatriz(int, int);
void darDatosMtz (int**, int, int);
int *crearArregloUni(int);
void arregloColumnas(int **, int*, int, int);
void arregloFilas(int **, int*, int, int);
void mostrarMtz(int**, int, int);
void mostrar(int*, int);
void liberarMtz(int**, int);
void liberar(int*);
void Mensajes(int);


void main(){
	int fil, col, **mtz, *A, *B;
	darDim(&fil,&col);
	mtz = crearMatriz(fil, col);
	darDatosMtz(mtz, fil, col);
    A = crearArregloUni(col);
    B = crearArregloUni(fil);
    mostrarMtz(mtz, fil, col);
    arregloColumnas(mtz, A, fil, col);
    arregloFilas(mtz, B, fil, col);
	liberarMtz(mtz, fil);
    liberar(A);
    liberar(B);
}

void darDim(int * fil, int * col){
	printf("Indique el numero de filas\n");
	scanf("%d", fil);
	printf("Indique el numero de columnas\n");
	scanf("%d", col);
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

void arregloColumnas(int ** mtz, int * A, int fil, int col){
    int sum,i,j;
    for(i=0;i<col;i++){
        sum = 0;
		for(j=0;j<fil;j++)
			sum += mtz[j][i];
        A[i] = sum;
	}
    printf("Los datos del arreglo columnas son: \n");
    mostrar(A,col);
}

void arregloFilas(int ** mtz, int * A, int fil, int col){
    int sum,i,j;
    for(i=0;i<fil;i++){
        sum = 0;
		for(j=0;j<col;j++)
			sum += mtz[i][j];
        A[i] = sum;
	}
    printf("Los datos del arreglo filas son: \n");
    mostrar(A,fil);
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
    printf("[");
	for(i=0;i<elem-1;i++)
		printf("%d, ",A[i]);
    printf("%d]\n",A[elem-1]);
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