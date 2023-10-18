#include<stdio.h>
#include "fraccion.h"
#include<stdlib.h>

void manejaMsg(int);
void darFracciones(FRACCION, FRACCION);
void mostrarFraccion(FRACCION, FRACCION, FRACCION, FRACCION);
void liberarMem(FRACCION, FRACCION, FRACCION);

void main(){
      FRACCION F1, F2, F3, F4;
      F1=crearFraccion();
      F2=crearFraccion ();
      F3=crearFraccion ();
      F4=crearFraccion ();
      darFracciones(F1, F2);
      F3 = producto(F1, F2);
      F4 = division(F1, F2);
     mostrarFraccion(F1, F2, F3,F4);
     liberarMem(F1, F2, F3);
}


void darFracciones(FRACCION F1, FRACCION F2){
     int n, d;
     printf("Dar el numerador de la fraccion 1\n");
     scanf("%d", &n);
     asignaNum(F1, n);
     printf("Dar el denominador de la fraccion 1\n");
     scanf("%d", &d); 
     asignaDenom(F1, d);
    printf("Dar el numerador de la fraccion 2\n");
     scanf("%d", &n);
     asignaNum(F2, n);
     printf("Dar el denominador de la fraccion 2\n");
     scanf("%d", &d); 
     asignaDenom(F2, d);
}

void mostrarFraccion(FRACCION F1, FRACCION F2, FRACCION F3, FRACCION F4){
    printf("Fraccion 1  %d/%d \n", obtenNum(F1), obtenDenom(F1) );
    printf("Fraccion 2  %d/%d \n", obtenNum(F2), obtenDenom(F2) ); 
    printf("El producto es %d/%d \n", obtenNum(F3), obtenDenom(F3));
    printf("El cociente es %d/%d \n", obtenNum(F4), obtenDenom(F4));
}
void manejaMsg(int msg){
     char * mensajes[] = {"No hay memoria disponible . . .","Se ha liberado la memoria . . .  "};
     printf("%s", mensajes[msg] );
}
void liberarMem(FRACCION F1, FRACCION F2, FRACCION F3){
    free(F1);
    free(F2); 
    free(F3);
    manejaMsg(1);
}


