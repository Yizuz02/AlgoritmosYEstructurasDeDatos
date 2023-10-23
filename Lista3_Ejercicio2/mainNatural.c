#include<stdio.h>
#include "natural.h"
#include<stdlib.h>

void manejaMsg(int);
void darNaturales(NATURAL *, NATURAL *);
void mostrarNaturales(NATURAL, NATURAL);
char* impBool(int);

void main(){
    NATURAL N1, N2;
    darNaturales(&N1, &N2);
    mostrarNaturales(N1, N2);
}


void darNaturales(NATURAL * N1, NATURAL * N2){
    int n;
    printf("Dar el valor del Natural 1:\n");
    scanf("%d", &n);
    *N1=crearNatural(n);
    printf("Dar el valor del Natural 2:\n");
    scanf("%d", &n);
    *N2=crearNatural(n);
}

void mostrarNaturales(NATURAL N1, NATURAL N2){
    printf("Natural 1:  %d\n", N1);
    printf("Natural 2:  %d\n", N2);
    printf("Natural 1[%d] es cero:  %s\n",N1,impBool(esCero(N1)));
    printf("Natural 2[%d] es cero:  %s\n",N2,impBool(esCero(N2)));
    printf("Natural 1 < Natural 2:  %s\n",impBool(esMenor(N1,N2)));
    printf("Natural 1 <= Natural 2:  %s\n",impBool(esMenorIgual(N1,N2)));
    printf("Natural 1 > Natural 2:  %s\n",impBool(esMayor(N1,N2)));
    printf("Natural 1 >= Natural 2:  %s\n",impBool(esMayorIgual(N1,N2)));
    printf("El predecesor del Natural 1:  %d\n", predecesor(N1));
    printf("El predecesor del Natural 2:  %d\n", predecesor(N2));
    printf("El sucesor del Natural 1:  %d\n", sucesor(N1));
    printf("El sucesor del Natural 2:  %d\n", sucesor(N2));
}
void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}


char* impBool(int b){
    char * booleano[] = {"Falso","Verdadero"};
    return booleano[b];
}

