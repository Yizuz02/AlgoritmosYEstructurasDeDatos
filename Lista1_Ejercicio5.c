#include <stdio.h>
#include <stdlib.h>

void darDim(int*, int*);
char **crearMatriz(int, int);
void darDatosMtz (char**, int, int);
void transpuesta(char**,char**,int,int);
void mostrarMtz(char**, int, int);
void liberarMtz(char**, int);
void Mensajes(int);


void main(){
	int fil, col;
    char **R, **RT;
	darDim(&fil,&col);
	R = crearMatriz(fil, col);
    RT = crearMatriz(col,fil);
	darDatosMtz(R, fil, col);
    transpuesta(R,RT,fil,col);
	mostrarMtz(R, fil, col);
    mostrarMtz(RT, col, fil);
	liberarMtz(R, fil);
    liberarMtz(RT, col);
}

void darDim(int * fil, int * col){
	printf("Indique el numero de filas\n");
	scanf("%d", fil);
	printf("Indique el numero de columnas\n");
	scanf("%d", col);
}

char ** crearMatriz(int fil, int col){
	char ** mtz;
	mtz = (char**) malloc(fil*sizeof(char*));
	if (mtz==NULL){
		Mensajes(0);
		exit(0);
	}
	for(int i=0;i<fil;i++)
		mtz[i] = (char*) malloc(col*sizeof(char));
		
	return mtz;
}

void darDatosMtz (char **mtz, int fil, int col){
	int i,j;
	
	printf("Ingrese los datos de la Matriz\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			printf("Dato[%d][%d]= ",i+1,j+1);
            getchar();
			scanf("%c",&mtz[i][j]);
		}
	}
}

void transpuesta(char**R,char**RT,int fil,int col){
    int i,j;
	
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			RT[j][i]=R[i][j];
		}
	}

}

void mostrarMtz(char **mtz, int fil, int col){
	int i,j;
	
	printf("Los datos de la Matriz son:\n");
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++)
			printf("\t%c",mtz[i][j]);
		printf("\n");
	}
}

void liberarMtz(char **mtz, int fil){
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
