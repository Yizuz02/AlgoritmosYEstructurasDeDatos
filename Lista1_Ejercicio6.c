#include <stdio.h>
#include <stdlib.h>

void darDim(int*);
int **crearMtzVec(int);
void darDatosMtz (int**, int);
float calcularArea(int**,int);
void mostrarArea(float);
void liberarMtz(int**, int);
void Mensajes(int);

void main (){
    int **mtz, n;
    float area;

    darDim(&n);
    mtz = crearMtzVec(n);
    darDatosMtz(mtz,n);
    area = calcularArea(mtz,n);
    mostrarArea(area);
    liberarMtz(mtz,n);
}

void darDim(int * n){
    printf("Ingrese el número de lados del poligono: \n");
    scanf("%d",n);
}

int **crearMtzVec(int n){
    int ** mtz;
    mtz = (int**)malloc(n*sizeof(int));
    if(mtz==NULL){
        Mensajes(0);
        exit(0);
    }
    for(int i=0;i<n;i++)
        mtz[i] = (int*)malloc(2*sizeof(int));
    
    return mtz;
}

void darDatosMtz (int** mtz, int n){
    for(int i=0;i<n;i++){
        printf("Ingrese los datos del vector %d\n",i+1);
        printf("X[%d]= ",i+1);
        scanf("%d",&mtz[i][0]);
        printf("Y[%d]= ",i+1);
        scanf("%d",&mtz[i][1]);
    }
}

float calcularArea(int** mtz,int n){
    int area=0;
    for(int i=0;i<n-1;i++)
        area+= (mtz[i][0] + mtz[i+1][0]) * (mtz[i][1] - mtz[i+1][1]);
    area += (mtz[n-1][0] + mtz[0][0]) * (mtz[n-1][1] - mtz[0][1]);
    area = area/2;
    if (area<0){
        area *= -1;
    } 
    return area;
}

void mostrarArea(float a){
    printf("El area del poligono es de: %.2f\n",a);
}

void liberarMtz(int **mtz, int n){
	int i;
	
	for(i=0;i<n;i++)
		free(mtz[i]);
	free(mtz);
	
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}
