#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float x;
    float y;
} Punto;

Punto * crearEstructura();
void darDatos(Punto*, Punto*);
void calcularPuntoMedio(Punto*, Punto*,Punto*);
void mostrar(Punto*);
void mostrarPuntos(Punto*, Punto*,Punto*);
void Mensajes(int);
void liberar(Punto*);

void main(){
	Punto *A, *B, *C;
	
	A = crearEstructura();
    B = crearEstructura();
    C = crearEstructura();
	darDatos(A, B);
    calcularPuntoMedio(A,B,C);
    mostrarPuntos(A,B,C);
	liberar(A);
    liberar(B);
    liberar(C);
}

Punto * crearEstructura(){
	Punto * nvo;
	nvo = (Punto*)malloc(sizeof(Punto));
	if(nvo==NULL){
		Mensajes(0);
		exit(0);
	}
	return nvo;

}

void darDatos(Punto * a, Punto * b){
	printf("Introduzca las coordenadas del punto A:\n");
    printf("X: ");
	scanf("%f", &a->x);
	printf("Y: ");
	scanf("%f", &a->y);
    printf("Introduzca las coordenadas del punto B:\n");
    printf("X: ");
	scanf("%f", &b->x);
	printf("Y: ");
	scanf("%f", &b->y);
}

void calcularPuntoMedio(Punto*a, Punto*b,Punto*c){
    c->x = (a->x + b->x)/2;
    c->y = (a->y + b->y)/2;
}

void mostrarPuntos(Punto*A, Punto*B,Punto*C){
    printf("Coordenadas del punto A:\n");
    mostrar(A);
    printf("Coordenadas del punto B:\n");
    mostrar(B);
    printf("Coordenadas del punto medio de A y B:\n");
    mostrar(C);
}

void mostrar(Punto* a){
	printf("X: %.2f\n",a->x);
	printf("Y: %.2f\n",a->y);
}

void liberar(Punto* exp){
	free(exp);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}