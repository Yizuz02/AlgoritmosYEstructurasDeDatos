#include <stdio.h>
#include <stdlib.h>

void darDim(int*, int*);
int **crearMatriz(int, int);
void darDatosMtz (int**, int, int);
void mostrarMtz(int**, int, int);
void esNula(int**, int, int);
void operaciones(int**, int, int);
void esTrianSup(int**, int, int);
void liberarMtz(int**, int);
void Mensajes(int);


void main(){
	int fil, col, **mtz;
	darDim(&fil,&col);
	mtz = crearMatriz(fil, col);
	darDatosMtz(mtz, fil, col);
	mostrarMtz(mtz, fil, col);
    esNula(mtz, fil, col);
    operaciones(mtz, fil, col);
    esTrianSup(mtz, fil, col);
	liberarMtz(mtz, fil);
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

void mostrarMtz(int **mtz, int fil, int col){
	int i,j;
	
	printf("Los datos de la Matriz R son:\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++)
			printf("\t%d",mtz[i][j]);
		printf("\n");
	}
}

void esNula(int **mtz, int fil, int col){
    int i,j;
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
            if(mtz[i][j]!=0){
                printf("La matriz R no es Nula\n");
                return;
            }
        }
	}
    printf("La matriz R es Nula\n");
}

void operaciones(int **mtz, int fil, int col){
	int i,j,k;
	
	printf("Ingrese un valor k: \n");
    scanf("%d",&k);
    printf("Los datos de la Matriz k*R son:\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++)
			printf("\t%d",mtz[i][j]*k);
		printf("\n");
	}
    printf("Los datos de la Matriz R/k son:\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++)
			printf("\t%.2f",mtz[i][j]/(k*1.00));
		printf("\n");
	}
}

void esTrianSup(int **mtz, int fil, int col){
    int i,j;
    if(fil==col){
        for(i=1;i<fil;i++){
		    for(j=0;j<i;j++){
                if(mtz[i][j]!=0){
                    printf("La matriz R no es una matriz triangular superior\n");
                    return;
                }
            }
	    }
        printf("La matriz R es una matriz triangular superior\n");
    } else {
        printf("La matriz R no es una matriz triangular superior\n");
    }	
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