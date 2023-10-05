#include <stdio.h>
#include <stdlib.h>

int imprimirMenu();
void menu(int*);
void darDim(int*);
int *crearArregloUni(int);
void darDatos(int*, int);
void ordenaSeleccion(int *, int);
void ordenaInsercion(int*, int);
void mostrar(int*, int);
void liberar(int*);
void Mensajes(int);

void main (){
	int *A;
	
	menu(A);
}

int imprimirMenu(){
    int op;
    printf("\nOrdenador de Arreglos\n");
    printf("1.- Establecer Tamaño del Arreglo\n");
    printf("2.- Crear Arreglo\n");
    printf("3.- Ingresar datos del arreglo\n");
    printf("4.- Ordenar de manera creciente\n");
    printf("5.- Ordenar de manera decreciente\n");
    printf("6.- Mostrar el arreglo\n");
    printf("7.- Salir\n");
    printf("Ingrese una opcion:\n");
    scanf("%d",&op);
    getchar();
    return op;
}

void menu(int * A){
    int op = 0, n=0, k=0;
    do
    {
        op = imprimirMenu();
        switch (op){
            case 1:
                darDim(&n);
                break;
            case 2:
                if(n==0){
                	printf("Debe ingresa un tamaño para el arreglo primero\n");
                } else {
                	A = crearArregloUni(n);
                	printf("Arreglo Creado!\n");
                	k=1;
                }
                break;
            case 3:
            	if(k==0)
                	printf("Debe crear un arreglo primero\n");
                else
                	darDatos(A, n);
                break;
            case 4:
                ordenaSeleccion(A, n);
                break;
            case 5:
                ordenaInsercion(A, n);
                break;
            case 6:
                mostrar(A, n);
                break;
            case 7:
                liberar(A);
                break;
            default:
                printf("Opcion no valida\n");
                break;
    }
    } while (op!=7);
    
}

void darDim(int* elem){
	printf("Dar la dimensión del arreglo \n");
	scanf("%d", elem);
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

void darDatos(int *A, int elem){
	int i;
	printf("Ingrese los datos del arreglo\n");
	for(i=0; i<elem;i++){
		printf("A[%d]= ",i+1);
		scanf("%d",&A[i]);
	}
}

void ordenaSeleccion(int *A, int n){
  int menor, i, j, aux;
  
  for(i=0; i<n-1; i++){
        menor=i;
	 for(j=i+1; j<n; j++)
	     if(A[j] <A[menor])
		     menor=j;
	 if(i != menor){
	   	aux=A[i];
	   	A[i]=A[menor];
	   	A[menor]=aux;
	 }
    }
}


void ordenaInsercion(int* A, int n){
	
	int i, j, aux;
	
	for(i=1; i < n; i++){
		j = i;
		aux = A[ i ];
		while( j > 0 && aux > A[ j-1]  ){
			A[ j ] = A[ j-1];
			j--;
		}
		A[j] = aux;
	}
}

void mostrar(int *A, int elem){
	int i;
	printf("Los datos del arreglo son: \n");
	for(i=0;i<elem;i++)
		printf("A[%d] = %d\n",i+1,A[i]);
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
