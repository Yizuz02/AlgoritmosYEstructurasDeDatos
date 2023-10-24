#include<stdlib.h>
#include<math.h>
#include "conjunto.h"

void manejaMsg(int);

CONJUNTO conjuntoVacio(int n){
   CONJUNTO C;
   C = (CONJUNTO)malloc(sizeof(Conjunto));
   if( C == NULL){
        manejaMsg(0);
        exit(0);
   }
   C->tamaño = n;
   C->num_elem = 0;
   C->elem = (int*)malloc(n*sizeof(int));
   if( C->elem == NULL){
        manejaMsg(0);
        exit(0);
   }
   return C;
}
void añadir(CONJUNTO C, int n){
    if(cardinal(C) <= C->tamaño){
        for(int i=0;i<cardinal(C);i++){
            if(C->elem[i]==n)
                return;
        }
        C->elem[(C->num_elem)++]=n;
    }
}
void retirar(CONJUNTO C, int elem){
    for(int i=0;i<cardinal(C);i++){
        if(C->elem[i]==elem){
            C->elem[i]=0;
            for(int j=i;j<cardinal(C)-1;j++)
                C->elem[j] = C->elem[j+1];
            C->num_elem--;
            return;
        }
    }
}
int elemento(CONJUNTO C, int n){
    return C->elem[n];
}
int pertenece(CONJUNTO C, int elem){
    for(int i=0;i<cardinal(C);i++){
        if(elemento(C,i)==elem)
            return 1;
    } 
    return 0;
}
int esVacio(CONJUNTO C){
    return C->num_elem==0;
}
int cardinal(CONJUNTO C){
    return C->num_elem;
}
CONJUNTO unionConjunto(CONJUNTO C1, CONJUNTO C2){
    CONJUNTO C3 = conjuntoVacio(cardinal(C1)+cardinal(C2));
    for(int i=0;i<cardinal(C1);i++)
        añadir(C3,elemento(C1,i));
    for(int j=0;j<cardinal(C2);j++){
        if(!pertenece(C3,elemento(C2,j)))
            añadir(C3,elemento(C2,j));
    }
    return C3;
}
CONJUNTO interseccion(CONJUNTO C1, CONJUNTO C2){
    CONJUNTO C3 = conjuntoVacio(cardinal(C1)+cardinal(C2) - fabs(cardinal(C1)-cardinal(C2)));
    for(int i=0;i<cardinal(C1);i++){
        if(pertenece(C2,elemento(C1,i)))
            añadir(C3,elemento(C1,i));
    }
    for(int j=0;j<cardinal(C2);j++){
        if(pertenece(C1,elemento(C2,j)) && !pertenece(C3,elemento(C2,j)))
            añadir(C3,elemento(C2,j));
    }
    return C3;
}
int inclusion(CONJUNTO C1, CONJUNTO C2){
    for(int i=0;i<cardinal(C1);i++){
        if(!pertenece(C2,elemento(C1,i)))
            return 0;
    }
    return 1;
}
