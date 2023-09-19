#include <stdio.h>
#include <stdlib.h>

int *crearVector();
void darDatos(int*, char);
int productoMixto(int*, int*, int*);
void mostrarVolumen(int*, int*, int*,int);
void liberar(int*);
void Mensajes(int);

void main(){
    int *A, *B, *C, volumen;

    A = crearVector();
    B = crearVector();
    C = crearVector();
    darDatos(A, 'A');
    darDatos(B, 'B');
    darDatos(C, 'C');
    volumen = productoMixto(A, B, C);
    mostrarVolumen(A, B, C, volumen);
    liberar(A);
    liberar(B);
    liberar(C);

}

int *crearVector(){
    int * vec;
	vec = (int*) malloc(3*sizeof(int));
	if(vec==NULL){
		Mensajes(0);
		exit(0);
	}
	return vec;
}

void darDatos(int *vec, char num){
	int i;
	printf("Ingrese los datos del vector %c\n", num);
	for(i=0; i<3;i++){
		printf("%c[%c]= ",num,i+'x');
		scanf("%d",&vec[i]);
	}
}

int productoMixto(int * A, int * B , int * C){
    int prodMixto = 0, j=1,k=2,i;
    for(i=0; i<3;i++){
        prodMixto += A[i]*B[j++]*C[k++];
        if(k==3)
            k=0;
        if(j==3)
            j=0;
    }
    j=1;
    k=2;
    for(i=0; i<3;i++){
        prodMixto -= A[k++]*B[j++]*C[i];
        if(k==3)
            k=0;
        if(j==3)
            j=0;
    }
    return prodMixto;
}

void liberar(int *vec){
	free(vec);
	Mensajes(1);
}

void mostrarVolumen(int *A,int *B,int *C,int vol){
	int i;
	printf("Los valores del vector A son: \n");
	for(i=0;i<3;i++)
		printf("A[%c] = %d\n",i+'x',A[i]);
    printf("Los valores del vector B son: \n");
	for(i=0;i<3;i++)
		printf("B[%c] = %d\n",i+'x',B[i]);
    printf("Los valores del vector C son: \n");
	for(i=0;i<3;i++)
		printf("C[%c] = %d\n",i+'x',C[i]);
    printf("El volumen del paralelepipedo es: %d\n",vol);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}