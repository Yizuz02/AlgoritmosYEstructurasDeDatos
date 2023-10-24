#include<stdio.h>
#include "conjunto.h"
#include<stdlib.h>

int imprimirMenu();
void menu(CONJUNTO, CONJUNTO);
void darConjuntos(CONJUNTO, CONJUNTO);
void impConjunto(CONJUNTO);
void liberarMem(CONJUNTO, CONJUNTO);
void ingresarElem(CONJUNTO);
void manejaMsg(int);
char* impBool(int);

void main(){
    CONJUNTO C1, C2;    
    menu(C1, C2);
}

int imprimirMenu(){
    int op;
    printf("Calculadora De Conjuntos\n");
    printf("1.- Ingresar elementos a un conjuntos\n");
    printf("2.- Eliminar un elemento de un conjunto\n");
    printf("3.- Imprimir Conjuntos\n");
    printf("4.- Union\n");
    printf("5.- Interseccion\n");
    printf("6.- Inclusion\n");
    printf("7.- Salir\n");
    printf("Ingrese una opcion:\n");
    scanf("%d",&op);
    getchar();
    return op;
}

void menu(CONJUNTO C1, CONJUNTO C2){
    int op=0, n,m;
    printf("Dar el tamaño maximo del Conjunto 1:\n");
    scanf("%d", &n);
    C1=conjuntoVacio(n);
    printf("Dar el tamaño maximo del Conjunto 2:\n");
    scanf("%d", &n);
    C2=conjuntoVacio(n);
    do
    {
        op = imprimirMenu();
        switch (op){
            case 1:
                printf("Elegir el conjunto (1/2):\n");
                scanf("%d", &n);
                if(n==1)
                    ingresarElem(C1);
                else if(n==2)
                    ingresarElem(C2);
                break;
            case 2:
                printf("Elegir el conjunto (1/2):\n");
                scanf("%d", &n);
                printf("Ingresar el numero que desea retirar:\n");
                scanf("%d", &m);
                if(n==1)
                    retirar(C1,m);
                else if(n==2)
                    retirar(C2,m);
                break;
            case 3:
                printf("Conjunto 1:\n");
                impConjunto(C1);
                printf("Conjunto 2:\n");
                impConjunto(C2);
                break;
            case 4:
                printf("Conjunto 1 union Conjunto 2:\n");
                impConjunto(unionConjunto(C1,C2));
                break;
            case 5:
                printf("Conjunto 1 interseccion Conjunto 2:\n");
                impConjunto(interseccion(C1,C2));
                break;
            case 6:
                printf("El Conjunto 1 pertenece al Conjunto 2: %s", impBool(inclusion(C1,C2)));
                break;
            case 7:
                liberarMem(C1,C2);
                break;
            default:
                printf("Opcion no valida\n");
                break;
        }
    } while (op!=7);   
}

void ingresarElem(CONJUNTO C){
    int n,m;
    printf("Dar el numero de elementos a agregar al conjunto:\n");
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        printf("Elemento: ");
        scanf("%d", &m);
        añadir(C,m);
    }
}

void impConjunto(CONJUNTO C){
    int i;
    printf("(");
    for(i=0;i<cardinal(C);i++)
        printf(" %d,",elemento(C,i));
    printf(" )\n");
}

void liberarMem(CONJUNTO C1, CONJUNTO C2){
    free(C1);
    free(C2);
    manejaMsg(1);
}

void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}

char* impBool(int b){
    char * booleano[] = {"Falso","Verdadero"};
    return booleano[b];
}

