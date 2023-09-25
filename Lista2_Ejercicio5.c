#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int real;
    int img;
} Complex;

Complex * crearEstructura();
void darDatos(Complex*, Complex*);
int opciones();
void menu(Complex*, Complex*);
void sumaCom(Complex*, Complex*);
void restaCom(Complex*, Complex*);
void prodCom(Complex*, Complex*);
void divCom(Complex*, Complex*);
void mostrar(Complex*);
void Mensajes(int);
void liberar(Complex*);

void main(){
	Complex *A, *B;
	
	A = crearEstructura();
    B = crearEstructura();
	darDatos(A, B);
    menu(A, B);
	
}

Complex * crearEstructura(){
	Complex * nvo;
	nvo = (Complex*)malloc(sizeof(Complex));
	if(nvo==NULL){
		Mensajes(0);
		exit(0);
	}
	return nvo;

}

void darDatos(Complex * a, Complex * b){
	printf("Introduzca el primer numero complejo:\n");
    printf("Real: ");
	scanf("%d", &a->real);
	printf("Imaginario: ");
	scanf("%d", &a->img);
    printf("Introduzca el segundo numero complejo:\n");
    printf("Real: ");
	scanf("%d", &b->real);
	printf("Imaginario: ");
	scanf("%d", &b->img);
}

void menu(Complex * a, Complex * b){
    int off = 1;
    int op;
    while(off){
        op = opciones();
        switch(op){
            case 1:
                sumaCom(a,b);
                break;
            case 2:
                restaCom(a,b);
                break;
            case 3:
                prodCom(a,b);
                break;
            case 4:
                divCom(a,b);
                break;
            case 5:
                liberar(a);
                liberar(b);
                off = 0;
                break;
            default:
                printf("Opcion no valida, ingrese un numero valido\n");
                break;
        }
    } 
}

int opciones(){
    int op;
    printf("Calculadora de Numeros Complejos\n");
    printf("1.- Suma\n");
    printf("2.- Resta\n");
    printf("3.- Multiplicacion\n");
    printf("4.- Division\n");
    printf("5.- Salir\n");
    printf("Ingrese el numero de la accion que desea ejecutar: \n");
    scanf("%d",&op);
    return op;
}

void sumaCom(Complex*a, Complex*b){
    int real = a->real + b->real;
    int img = a->img + b->img;
    printf("La suma de: \n");
    mostrar(a);
    printf(" + ");
    mostrar(b);
    printf(" = %d + %di\n",real,img);
}

void restaCom(Complex*a, Complex*b){
    int real = a->real - b->real;
    int img = a->img - b->img;
    printf("La resta de: \n");
    mostrar(a);
    printf(" - ");
    mostrar(b);
    printf(" = %d + %di\n",real,img);
}

void prodCom(Complex*a, Complex*b){
    int real = (a->real*b->real)+(a->img*b->img*-1);
    int img = (a->real*b->img)+(a->img*b->real);
    printf("El producto de: \n");
    mostrar(a);
    printf(" * ");
    mostrar(b);
    printf(" = %d + %di\n",real,img);
}

void divCom(Complex*a, Complex*b){
    int numeradorReal = (a->real*b->real)+(a->img*b->img);
    int numeradorImg = (a->real*-b->img)+(a->img*b->real);
    int denominador = b->real*b->real - b->img*b->img*-1;
    printf("La division de: \n");
    mostrar(a);
    printf(" / ");
    mostrar(b);
    printf(" = (%d + %di)/(%d)\n",numeradorReal,numeradorImg,denominador);
}

void mostrar(Complex* a){
	printf("%d + %di",a->real, a->img);
}

void liberar(Complex* exp){
	free(exp);
	Mensajes(1);
}

void Mensajes(int msg){
	char * mensaje[] ={"No hay memoria disponible ... \n",
			"Memoria liberada ... \n"};
	printf("%s", mensaje[msg]);
}