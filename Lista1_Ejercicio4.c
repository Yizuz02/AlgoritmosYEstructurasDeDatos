#include <stdio.h>
#include <stdlib.h>

void crearMatrices(int**, int**, int**, int, int, int*, int*);
void darDim(int*, int*);
int **crearMatriz(int, int);
void darDatosMtz (int**, int, int, char);
int menu(int**, int**);
void prodVectorEscalar(int**, int, int, int);
void sumaMtz(int**, int**, int**, int, int);
void restaMtz(int**, int**, int**, int, int);
void productoMtz(int**, int**, int**, int, int);
void mostrarMtz(int**, int, int);
void liberarMtz(int**, int);
void Mensajes(int);


void main(){
	int **A, **B, res=1;
	
	while (res)
    {
        res=menu(A,B);
    }
}

int menu(int**A, int**B){
    int res, fil, col, p,q, **C;
    printf("Calculadora de Matrices\n");
    printf("1.-pA + qB\n");
    printf("2.-qA - pB\n");
    printf("3.-pA * qB\n");
    printf("4.-Salir\n");
    printf("Ingrese un numero: ");
    scanf("%d",&res);
    if (res==4)
        return 0;
    darDim(&fil,&col);
    A = crearMatriz(fil, col);
	darDatosMtz(A, fil, col, 'A');
	B = crearMatriz(fil, col);
	darDatosMtz(B, fil, col, 'B');
    printf("Ingrese el valor de p: ");
    scanf("%d",&p);
    printf("Ingrese el valor de q: ");
    scanf("%d",&q);
    C = crearMatriz(fil, col);
    switch (res)
    {
    case 1:    
        prodVectorEscalar(A,p,fil,col);
        prodVectorEscalar(B,q,fil,col);
        sumaMtz(A, B, C, fil, col);
        mostrarMtz(C, fil, col);
        break;
    case 2:
        prodVectorEscalar(A,q,fil,col);
        prodVectorEscalar(B,p,fil,col);
        restaMtz(A, B, C, fil, col);
        mostrarMtz(C, fil, col);
        break;
    case 3:
        if(fil==col){
            prodVectorEscalar(A,p,fil,col);
            prodVectorEscalar(B,q,fil,col);
            productoMtz(A, B, C, fil, col);
            mostrarMtz(C, fil, col);
        } else
            printf("No se puede realizar la operacion\n");
        break;
    default:
        printf("Esa no es una opcion valida\n");
        break;
    }
    liberarMtz(A, fil);
    liberarMtz(B, fil);
    liberarMtz(C, fil);
    return 1;
    
}

void crearMatrices(int**A, int**B, int**C, int fil, int col, int* p, int*q){
    A = crearMatriz(fil, col);
	darDatosMtz(A, fil, col, 'A');
	B = crearMatriz(fil, col);
	darDatosMtz(B, fil, col, 'B');
    printf("Ingrese el valor de p: ");
    scanf("%d",&p);
    printf("Ingrese el valor de q: ");
    scanf("%d",&q);
    C = crearMatriz(fil, col);
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

void darDatosMtz (int **mtz, int fil, int col, char c){
	int i,j;
	
	printf("Ingrese los datos de la Matriz %c\n", c);
	for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
			printf("Dato[%d][%d]= ",i+1,j+1);
			scanf("%d",&mtz[i][j]);
		}
	}
}

void prodVectorEscalar(int**mtz, int p, int fil, int col){
    int i,j;
    for(i=0;i<fil;i++){
		for(j=0;j<col;j++)
			mtz[i][j]=mtz[i][j]*p;
	}
}

void sumaMtz(int**A, int** B, int** C, int fil, int col){
    int i,j;
    for(i=0;i<fil;i++){
		for(j=0;j<col;j++)
			C[i][j]=A[i][j]+B[i][j];
	}
}

void productoMtz(int**A, int** B, int** C, int fil, int col){
    int i,j,k;
    for(i=0;i<fil;i++){
		for(j=0;j<col;j++){
            C[i][j]=0;
            for(k=0;k<col;k++)
                C[i][j]+=A[i][k]*B[k][j];
        }
	}
}

void restaMtz(int**A, int** B, int** C, int fil, int col){
    int i,j;
    for(i=0;i<fil;i++){
		for(j=0;j<col;j++)
			C[i][j]=A[i][j]-B[i][j];
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