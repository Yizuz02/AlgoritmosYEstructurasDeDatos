#include <stdio.h>
#include <stdlib.h>

int **crearMatriz();
void darDatosMtz (int**);
void mostrarMtz(int**);
void determinante(int**);
void liberarMtz(int**, int);
void Mensajes(int);

void main (){
    int **mtz;
    mtz = crearMatriz();
    darDatosMtz(mtz);
    mostrarMtz(mtz);
    determinante(mtz);
    liberarMtz(mtz,2);
}

int ** crearMatriz(){
	int ** mtz, i;
	mtz = (int**) malloc(2*sizeof(int*));
	if (mtz==NULL){
		Mensajes(0);
		exit(0);
	}
	for(i=0;i<2;i++)
		mtz[i] = (int*) malloc(2*sizeof(int));
		
	return mtz;
}

void darDatosMtz (int **mtz){
	int i,j;
	
	printf("Ingrese los datos de la Matriz\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++){
			printf("Dato[%d][%d]= ",i+1,j+1);
			scanf("%d",&mtz[i][j]);
		}
	}
}

void mostrarMtz(int **mtz){
	int i,j;
	
	printf("Los datos de la Matriz son:\n");
	for(i=0;i<2;i++){
		for(j=0;j<2;j++)
			printf("\t%d",mtz[i][j]);
		printf("\n");
	}
}

void determinante(int **mtz){
    int det;
    det = (mtz[0][0]*mtz[1][1])-(mtz[0][1]*mtz[1][0]);
    printf("El determinante de la Matriz es: %d\n",det);
}

void liberarMtz(int **mtz, int fil){
	int i;
	
	for(i=0;i<fil;i++)
		free(mtz[i]);
	free(mtz);
	
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}